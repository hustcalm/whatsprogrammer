function point_pair = point_match(size_i,point_i,descriptor_i,size_j,point_j,descriptor_j)

DisparityMax = [0.4, 0.2];
CostMax = 0.4;
NbMatchMax=2000;

point_pair = [];
for i=1:size(point_i,1)
    for j=1:size(point_j,1)
        if abs( point_i(i,1) / size_i(1) - point_j(j,1) / size_j(1) ) < DisparityMax(1) ...
        && abs( point_i(i,2) / size_i(2) - point_j(j,2) / size_j(2) ) < DisparityMax(2)
            Score = sum(sum(descriptor_i{i} .* descriptor_j{j}));
            if 1-Score<= CostMax
                point_pair(end+1,:)=[i,j,Score];
            end
        end
    end
end
[Scores idx] = sort(point_pair(:,3),'descend');
if length(idx) > NbMatchMax
    idx = idx(1:NbMatchMax);
end
point_pair = point_pair(idx,:);