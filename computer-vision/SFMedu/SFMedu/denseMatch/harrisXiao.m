function PointTable = harrisXiao(image)

MinimumProportion = 0.0000005;

rows = size(image,1);
cols = size(image,2);

K = -0.125;

Ix = derivateXiao(smoothXiao(image,true ,K,5),true ,K,5);
Iy = derivateXiao(smoothXiao(image,false,K,5),false,K,5);

Ixy = Ix .* Iy;
Ixx = Ix .* Ix;
Iyy = Iy .* Iy;

K = -0.5;

Ixx = smoothXiao(smoothXiao(Ixx,true ,K,7),false ,K,7);
Ixy = smoothXiao(smoothXiao(Ixy,true ,K,7),false ,K,7);
Iyy = smoothXiao(smoothXiao(Iyy,true ,K,7),false ,K,7);
    
% det(A) - k * trace(A) ^2
Map = Ixx .* Iyy - Ixy .* Ixy - 0.06 .* (Ixx + Iyy) .^2;

MapMax = max(max(Map));
MapMin = MinimumProportion * MapMax;

peaks = zeros([rows cols]);
for r=12:rows-12
    for c=12:cols-12
        M = Map(r,c);
        if MapMin < M
            if Map(r-1,c-1)<M && Map(r-1,c)<M && Map(r-1,c+1)<M ...
            && Map(r  ,c-1)<M                 && Map(r  ,c+1)<M ...
            && Map(r+1,c-1)<M && Map(r+1,c)<M && Map(r+1,c+1)<M
                peaks(r,c) = M;
            end
        end
    end
end

[PointTableRow PointTableCol] = find(peaks~=0);
PointTableValue = nonzeros(peaks);
[PointTableValue sorted_idx] = sort(PointTableValue,'descend');
PointTable = [PointTableRow PointTableCol];
PointTable = PointTable(sorted_idx,:);
