function [cameraRt,pointCloud] = bundleAdjustment2DRobustFile(cameraRt,pointCloud,pointObserved, pointObservedValue, K, weight, mode)

% SFMedu: Structrue From Motion for Education Purpose
% Written by Jianxiong Xiao (MIT License)


[camID,ptsID,valID] = find(pointObserved);


nCam=uint32(size(cameraRt,3));
nPts=uint32(size(pointCloud,2));
nObs=uint32(length(valID));
fx=K(1,1); 
fy=K(2,2); 
px=K(1,3); 
py=K(2,3);

% transform the cameraRt
for camera=1:size(cameraRt,3)    
    cameraRt(:,:,camera) = [cameraRt(:,1:3,camera)' cameraRt(:,1:3,camera)'*(-cameraRt(:,4,camera))];
end

fname_inout = tempname;
fname_in = [fname_inout '.in'];
fname_out = [fname_inout '.out'];


fin = fopen(fname_in, 'wb');
fwrite(fin, nCam, 'uint32');
fwrite(fin, nPts, 'uint32');
fwrite(fin, nObs, 'uint32');
fwrite(fin, fx, 'double');
fwrite(fin, fy, 'double');
fwrite(fin, px, 'double');
fwrite(fin, py, 'double');

fwrite(fin, cameraRt, 'double');
fwrite(fin, pointCloud, 'double');

% write observation  
ptsObservedIndex = uint32([camID,ptsID]-1)';
ptsObservedValue = pointObservedValue(:,valID);
fwrite(fin, ptsObservedIndex, 'uint32');
fwrite(fin, ptsObservedValue, 'double');

fclose(fin);

cmd = sprintf('ba2D/ba2D %d %f %s %s', mode, weight, fname_in, fname_out);
fprintf('%s\n',cmd);
system(cmd);

% read the result back;
fout = fopen(fname_out, 'rb');
nCam=fread(fout,1,'uint32');
nPts=fread(fout,1,'uint32');
cameraRt = fread(fout,12*nCam,'double');
pointCloud = fread(fout,3*nPts,'double');
fclose(fout);

cameraRt = reshape(cameraRt,3,4,[]);
pointCloud = reshape(pointCloud,3,[]);

% transform the cameraRt back
for camera=1:size(cameraRt,3)
    cameraRt(:,:,camera) = [cameraRt(:,1:3,camera)' cameraRt(:,1:3,camera)'*(-cameraRt(:,4,camera))];
end

delete(fname_in);
delete(fname_out);
