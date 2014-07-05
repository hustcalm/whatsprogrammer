% SFMedu: Structrue From Motion for Education Purpose
% Written by Jianxiong Xiao (MIT License)

%% set up things
clear;
close all;
addpath(genpath('lib'));
addpath(genpath('denseMatch'));
addpath(genpath('sfm'));

visualize = true;
if matlabpool('size')==0
    matlabpool
end
clc;
disp('SFMedu: Structrue From Motion for Education Purpose');
disp('Written by Jianxiong Xiao (MIT License)');

%% data
frames.images{1}='images/B21.jpg';
frames.images{2}='images/B22.jpg';
frames.images{3}='images/B23.jpg';
frames.focal_length = 719.5459;
frames.K = eye(3);
frames.K(1,1) = frames.focal_length;
frames.K(2,2) = frames.focal_length;

%% SIFT matching and Fundamental Matrix Estimation

frames.length = length(frames.images);
imsize = size(imread(frames.images{1}));
%imsize = repmat([imsize(2);imsize(1)],1,frames.length);
for frame=1:frames.length-1
    s = RandStream('mcg16807','Seed',10); % need to set this random seed to produce exact same result
    RandStream.setGlobalStream(s);
    MatchPairs{frame} = align2view(frames, frame, frame+1);
end

%% Essential Matrix Estimation
for frame=1:frames.length-1
    % Essential Matrix
    MatchPairs{frame}.E = frames.K' * MatchPairs{frame}.F * frames.K; % MVG Page 257 Equation 9.12

    % Decompose Essential Matrix
    [R1, R2, t1, t2] = PoseEMat(MatchPairs{frame}.E); % MVG Page 257-259
    
    % Four possible solution
    MatchPairs{frame}.Rt(:,:,1) =[R1 t1];
    MatchPairs{frame}.Rt(:,:,2) =[R1 t2];
    MatchPairs{frame}.Rt(:,:,3) =[R2 t1];
    MatchPairs{frame}.Rt(:,:,4) =[R2 t2];
    
    % triangulation 
    P{1} = frames.K * [eye(3) [0;0;0]];
    for i=1:4
        clear X;
        P{2} = frames.K * MatchPairs{frame}.Rt(:,:,i);
        for j=1:size(MatchPairs{frame}.matches,2)
            X(:,j) = vgg_X_from_xP_nonlin(reshape(MatchPairs{frame}.matches(:,j),2,2),P,repmat([imsize(2);imsize(1)],1,2));
        end
        X = X(1:3,:) ./ X([4 4 4],:);
        
        dprd = MatchPairs{frame}.Rt(3,1:3,i) * ((X(:,:) - repmat(MatchPairs{frame}.Rt(1:3,4,i),1,size(X,2))));
        goodCnt(i) = sum(X(3,:)>0 & dprd > 0);
        
        %{
        figure
        plot3(X(1,:),X(2,:),X(3,:),'.')
        axis equal
        drawCamera(inverseCameraRt([eye(3) [0;0;0]]), imsize(2), imsize(1), frames.K(1,1), 0.001,1);
        drawCamera(inverseCameraRt(MatchPairs{frame}.Rt(:,:,i)), imsize(2), imsize(1), frames.K(1,1), 0.001,3);
        axis tight
        %}
    end
    
    % pick one solution from the four
    goodCnt
    [~, bestIndex]=max(goodCnt);
    MatchPairs{frame}.Rtbest = MatchPairs{frame}.Rt(:,:,bestIndex);
    i= bestIndex;
    clear X;
    P{2} = frames.K * MatchPairs{frame}.Rt(:,:,i);
    for j=1:size(MatchPairs{frame}.matches,2)
        X(:,j) = vgg_X_from_xP_nonlin(reshape(MatchPairs{frame}.matches(:,j),2,2),P,repmat([imsize(2);imsize(1)],1,2));
    end
    X = X(1:3,:) ./ X([4 4 4],:);
    MatchPairs{frame}.X = X;
    
    if visualize
        % two view visualization
        figure
        plot3(X(1,:),X(2,:),X(3,:),'.')
        axis equal
        title(['two views: ' num2str(max(goodCnt))]);
        drawCamera(inverseCameraRt([eye(3) [0;0;0]]), imsize(2), imsize(1), frames.K(1,1), 0.001,1);
        drawCamera(inverseCameraRt(MatchPairs{frame}.Rt(:,:,i)), imsize(2), imsize(1), frames.K(1,1), 0.001,3);
        axis tight
    end
    
end


% camera back transform
cameraRt = zeros(3,4,frames.length);
cameraRt(:,:,1) = [eye(3) [0;0;0]];
for frameID=1:frames.length-1
    cameraRt(:,:,frameID+1) = inverseCameraRt(MatchPairs{frameID}.Rtbest);
end

% camera cancatenate
for frameID = 1:frames.length-1
    cameraRt(:,:,frameID+1) = [cameraRt(:,1:3,frameID) * cameraRt(:,1:3,frameID+1) cameraRt(:,1:3,frameID) * cameraRt(:,4,frameID+1) + cameraRt(:,4,frameID)];
end

%% established linking

fprintf('linking point tracks ...');
tic;

% link track
maxNumSIFT = frames.length*1000;
pointObserved= sparse(frames.length,maxNumSIFT);
pointObservedValue = zeros(2,maxNumSIFT);


pointCloud   = zeros(3,maxNumSIFT);
pointCount = size(MatchPairs{1}.matches,2);
pointObservedValueCount = size(MatchPairs{1}.matches,2)*2;
pointObservedValue(1:2,1:pointObservedValueCount) = [MatchPairs{1}.matches(1:2,:) MatchPairs{1}.matches(3:4,:)];
pointObserved(1,1:pointCount)=1:pointCount;
pointObserved(2,1:pointCount)=pointCount + (1:pointCount);
previousIndex = 1:pointCount;

pointCloud(:,1:pointCount) = MatchPairs{1}.X;


for frameID = 2:frames.length-1
    [~,iA,iB] = intersect(MatchPairs{frameID-1}.matches(3:4,:)',MatchPairs{frameID}.matches(1:2,:)','rows');
    
    
    alreadyExist = false(1,size(MatchPairs{frameID}.matches,2));
    alreadyExist(iB) = true;
    newCount = sum(~alreadyExist);
    
    
    currentIndex = zeros(1,size(MatchPairs{frameID}.matches,2));
    currentIndex(iB) = previousIndex(iA);
    currentIndex(~alreadyExist) = (pointCount+1):(pointCount+newCount);
    
    pointObservedValue(:,pointObservedValueCount+1:pointObservedValueCount+newCount+length(currentIndex)) = [MatchPairs{frameID}.matches(1:2,~alreadyExist) MatchPairs{frameID}.matches(3:4,:)];
    
    pointObserved(frameID  ,currentIndex(~alreadyExist)) = (pointObservedValueCount+1):(pointObservedValueCount+newCount);
    pointObservedValueCount = pointObservedValueCount + newCount;
    pointObserved(frameID+1,currentIndex) = (pointObservedValueCount+1):(pointObservedValueCount+length(currentIndex));
    pointObservedValueCount = pointObservedValueCount + length(currentIndex);
    
    
    pointCloud(:,pointCount+1:pointCount+newCount) = transformRT(MatchPairs{frameID}.X(:,~alreadyExist), cameraRt(:,:,frameID), false);
    
    pointCount = pointCount + newCount;
    
    previousIndex = currentIndex;
end


pointCloud = pointCloud(:,1:pointCount);
pointObserved = pointObserved(:,1:pointCount);
pointObservedValue = pointObservedValue(:,1:pointObservedValueCount);

if visualize
    figure
    plot3(pointCloud(1,:),pointCloud(2,:),pointCloud(3,:),'.')
    axis equal
    title('whole cloud without bundle')
    for i=1:frames.length
        drawCamera(cameraRt(:,:,i), imsize(2), imsize(1), frames.K(1,1), 0.001,i*2-1);
    end
    axis tight
    
    figure
    imagesc(pointObserved)
    title('observation matrix');
end

%% bundle adjustment

framesAligned = true(1,frames.length);
fprintf('bundle adjusting    ...\n');
tic
[cameraRt,pointCloud] = bundleAdjustment2DRobustFile(cameraRt,pointCloud,pointObserved, pointObservedValue, frames.K, 0, 2);
toc;

if visualize
    figure
    plot3(pointCloud(1,:),pointCloud(2,:),pointCloud(3,:),'.r')
    axis equal
    title('whole cloud with bundle adjustment')
    for i=1:frames.length
        drawCamera(cameraRt(:,:,i), imsize(2), imsize(1), frames.K(1,1), 0.001,i*2-1);
    end
    axis tight
end

%% multiple view dense stereo

% dense match
for frame=1:frames.length-1
    MatchPairs{frame} = denseMatch(MatchPairs{frame}, frames, frame, frame+1);
end

% triangulate
for frame=1:frames.length-1
    clear X;
    P{1} = frames.K * inverseCameraRt(cameraRt(:,:,frame));
    P{2} = frames.K * inverseCameraRt(cameraRt(:,:,frame+1));
    parfor j=1:size(MatchPairs{frame}.denseMatch,2)
        %pair.denseMatch(1,:) ,pair.denseMatch(2,:)
        X(:,j) = vgg_X_from_xP_nonlin(reshape(MatchPairs{frame}.denseMatch(1:4,j),2,2),P,repmat([imsize(2);imsize(1)],1,2));
    end
    X = X(1:3,:) ./ X([4 4 4],:);
    x1= P{1} * [X; ones(1,size(X,2))];
    x2= P{2} * [X; ones(1,size(X,2))];
    x1 = x1(1:2,:) ./ x1([3 3],:);
    x2 = x2(1:2,:) ./ x2([3 3],:);
    MatchPairs{frame}.denseX = X;
    MatchPairs{frame}.denseRepError = sum(([x1; x2] - MatchPairs{frame}.denseMatch(1:4,:)).^2,1);
end

% visualize the dense point cloud
figure
for frame=1:frames.length-1
    hold on
    goodPoint =  MatchPairs{frame}.denseRepError < 0.05;
    plot3(MatchPairs{frame}.denseX(1,goodPoint),MatchPairs{frame}.denseX(2,goodPoint),MatchPairs{frame}.denseX(3,goodPoint),'.b','Markersize',1);
end
hold on
plot3(pointCloud(1,:),pointCloud(2,:),pointCloud(3,:),'.r')
axis equal
title('dense cloud')
for i=1:frames.length
    drawCamera(cameraRt(:,:,i), imsize(2), imsize(1), frames.K(1,1), 0.001,i*2-1);
end
axis tight

%% output as ply file to open in Meshlab
plyPoint = [];
plyColor = [];
for frame=1:frames.length-1
    goodPoint =  MatchPairs{frame}.denseRepError < 0.05;
    X = MatchPairs{frame}.denseX(:,goodPoint);
    P{1} = frames.K * inverseCameraRt(cameraRt(:,:,frame));
    x1= P{1} * [X; ones(1,size(X,2))];
    x1 = round(x1(1:2,:) ./ x1([3 3],:));
    x1(1,:) = imsize(2)/2 - x1(1,:);
    x1(2,:) = imsize(1)/2 - x1(2,:);
    indlin = sub2ind(imsize(1:2),x1(2,:),x1(1,:));
    im = imread(frames.images{frame});
    imR = im(:,:,1);
    imG = im(:,:,2);
    imB = im(:,:,3);
    colorR = imR(indlin);
    colorG = imG(indlin);
    colorB = imB(indlin);
    plyPoint = [plyPoint X];
    plyColor = [plyColor [colorR; colorG; colorB]];
end

outputPly('dense.ply',plyPoint,plyColor);
