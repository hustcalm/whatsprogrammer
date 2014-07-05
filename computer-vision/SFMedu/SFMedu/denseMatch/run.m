addpath priority_queue_1.0

close all

NbPointImageMax = 800;
HalfSizeWindow  = 5;
HalfSizePropagate = 2;


fname{1} = 'templeSR0001.png';
fname{2} = 'templeSR0002.png';

visualization = true;
rectified = false;

% Corner Detection and Descriptor Computation
for i=1:2
    image{i} = imread(fname{i});
    image{i} = double(image{i})/256;
    
    %image{i} = imresize(image{i},1/16);
    
    if size(image{i},3)==3
        image{i} = ( 76 * image{i}(:,:,1) + 150 * image{i}(:,:,2) + 30 * image{i}(:,:,3) ) / 256;
    end
    
    matchable_image{i} = ReliableArea(image{i});
    zncc{i} = ZNCCpatch_all(image{i},HalfSizePropagate);
    
    if visualization
        figure
        imshow((image{i} + matchable_image{i}) * 0.5);
    end

    % harris corner detection
    point{i} = harrisXiao(image{i});
    % get most reliable ones 
    point{i} = point{i}(1:NbPointImageMax,:);
    % compute patches
    descriptor{i} = ZNCCpatch(image{i}, point{i}, HalfSizeWindow);
    % ZNCCSpeedUp(SInt16(View0_[i].x()), SInt16(View0_[i].y()), SizeWindow, 0, ZNCCTable0+i*Surface)
    if visualization
        figure
        imshow(image{i});
        hold on;
        for k=1:size(point{i},1)
            plot(point{i}(k,2),point{i}(k,1),'y+');
        end
        hold off;
    end
end

for i=1
    j=i+1;
    
    
    % sparse matching
    point_pair = point_match(size(image{i}),point{i},descriptor{i},size(image{j}),point{j},descriptor{j});
    
    if visualization
        figure
        imshow( [image{i} image{j}] );
        hold on
        for k=1:size(point_pair,1)
            plot( [point{i}(point_pair(k,1),2),size(image{i},2)+  point{j}(point_pair(k,2),2)],...
                  [point{i}(point_pair(k,1),1),                   point{j}(point_pair(k,2),1)],'y+');
        end
        hold off
    end
    
    % cross checking and WinnerTakeAll
    for k=1:size(point_pair,1)-1
        if point_pair(k,3) > 0
            p_i = point_pair(k,1);
            idxs = find(point_pair(k+1:end,1)==p_i);
            idxs = k+idxs;
            point_pair(idxs,3) = 0;
            
            p_j = point_pair(k,2);
            idxs = find(point_pair(k+1:end,2)==p_j);
            idxs = k+idxs;
            point_pair(idxs,3) = 0;
        end
    end
    idxs = find(point_pair(:,3)>0);
    point_pair = point_pair(idxs,:);


    initial_match = [point{i}(point_pair(:,1),:) point{j}(point_pair(:,2),:) point_pair(:,3)];
    
    if rectified
        for k=1:size(initial_match,1)
            if abs(initial_match(k,1) - initial_match(k,3)) > 20
                initial_match(k,5) = - 1;
            end
        end
        initial_match = initial_match(find(initial_match(:,5)>=0),:);
    end
    
    if visualization
        figure
        imshow( [image{i} image{j}] );
        hold on
        for k=1:size(initial_match,1)
            plot( [initial_match(k,2), size(image{i},2)+initial_match(k,4)],...
                  [initial_match(k,1),                  initial_match(k,3)],'y+');
        end
        hold off
    end
        
    
    tic
    [match_heap match_im_i match_im_j] = propagate(initial_match, image{i}, image{j}, matchable_image{i}, matchable_image{j}, zncc{i}, zncc{j}, HalfSizePropagate );
    % [match_heap match_im_i match_im_j] = propagate_no_zncc_precompute(initial_match, image{i}, image{j}, matchable_image{i}, matchable_image{j});
    toc
    
    
    if visualization
        figure

        disparity = ( match_heap(:,1) - match_heap(:,3) ) .^ 2 + ( match_heap(:,2) - match_heap(:,4) ) .^ 2 ;
        [disparity sorted_idx] = sort(disparity);
        match_heap = match_heap(sorted_idx,:);
        disparity = cumsum( [1; (disparity(2:end) ~= disparity(1:end-1) )] );
        
        depth_i = ones(size(image{i}));
        for k=1:size(disparity,1)
            depth_i(match_heap(k,1),match_heap(k,2)) = disparity(k) / size(disparity,1);
        end
        subplot(1,2,1);
        imshow(depth_i * 200);
        
        depth_j = ones(size(image{j}));
        for k=1:size(disparity,1)
            depth_j(match_heap(k,3),match_heap(k,4)) = disparity(k) / size(disparity,1);
        end
        subplot(1,2,2);
        imshow(depth_j * 200);
    end
    
    
    
end










