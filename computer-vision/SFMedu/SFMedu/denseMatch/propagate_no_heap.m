function [match_heap match_im_i match_im_j] = propagate_slow(initial_match, im_i, im_j, matchable_im_i, matchable_im_j )

%{
Please cite this paper if you use this code.
J. Xiao, J. Chen, D.-Y. Yeung, and L. Quan
Learning Two-view Stereo Matching
Proceedings of the 10th European Conference on Computer Vision (ECCV2008)
Springer Lecture Notes in Computer Science (LNCS), Pages 15-27
%}


match_heap = initial_match;
match_im_i(:,:,1) = matchable_im_i - 2;     match_im_i(:,:,2) = match_im_i(:,:,1);
match_im_j(:,:,1) = matchable_im_j - 2;     match_im_j(:,:,2) = match_im_j(:,:,1);
maxMatchingNumber = min(numel(matchable_im_i),numel(matchable_im_j));

xyMin = 3;
WindowHalfSizeOfLocalPropagation = 2;
CostMax = 0.5;

while ( maxMatchingNumber >=0 )
    [bestPriority bestIndex] = max(match_heap(:,5));
    if bestPriority <= 0
        break;
    end
    match_heap(bestIndex,5) = - match_heap(bestIndex,5);
    
    x0 = match_heap(bestIndex,1);    y0 = match_heap(bestIndex,2);
    x1 = match_heap(bestIndex,3);    y1 = match_heap(bestIndex,4);
    

    xMin0= max(WindowHalfSizeOfLocalPropagation+1, x0-WindowHalfSizeOfLocalPropagation);     
    xMax0= min(size(matchable_im_i,1)-WindowHalfSizeOfLocalPropagation, x0+WindowHalfSizeOfLocalPropagation+1);
	yMin0= max(WindowHalfSizeOfLocalPropagation+1, y0-WindowHalfSizeOfLocalPropagation);     
    yMax0= min(size(matchable_im_i,2)-WindowHalfSizeOfLocalPropagation, y0+WindowHalfSizeOfLocalPropagation+1);
    
	xMin1= max(WindowHalfSizeOfLocalPropagation+1, x1-WindowHalfSizeOfLocalPropagation);     
    xMax1= min(size(matchable_im_j,1)-WindowHalfSizeOfLocalPropagation, x1+WindowHalfSizeOfLocalPropagation+1);
	yMin1= max(WindowHalfSizeOfLocalPropagation+1, y1-WindowHalfSizeOfLocalPropagation);     
    yMax1= min(size(matchable_im_j,2)-WindowHalfSizeOfLocalPropagation, y1+WindowHalfSizeOfLocalPropagation+1);

    local_heap = [];
    for xx0= xMin0:xMax0
		for yy0= yMin0:yMax0
			if ( match_im_i(xx0,yy0,1) == -1 )
                xx= (xx0+x1)-x0;
                yy= (yy0+y1)-y0;
				for xx1 = max(xMin1, xx-1) : min(xMax1, xx+2)
					for yy1= max(yMin1, yy-1) : min(yMax1, yy+2)
						if ( match_im_j(xx1,yy1,1) == -1 )
                            descriptor_i = ZNCCpatch(im_i, [xx0,yy0], WindowHalfSizeOfLocalPropagation);
                            descriptor_j = ZNCCpatch(im_j, [xx1,yy1], WindowHalfSizeOfLocalPropagation);
                            AuxCost= sum(sum(descriptor_i{1} .* descriptor_j{1}));
                            if (1- AuxCost <= CostMax) % IsEpipolarValidMatch(xx0,yy0,xx1,yy1) &&
                                local_heap(end+1,:) = [xx0,yy0,xx1,yy1,AuxCost];
                            end
                        end
                    end
                end
            end
        end
    end
    
    % keep best candidate matches first of local_heap
    while size(local_heap,1) > 0
        [bestPriority bestIndex] = max(local_heap(:,5));
        if bestPriority <= 0
            break;
        end
        xx0 = local_heap(bestIndex,1);  yy0 = local_heap(bestIndex,2);
        xx1 = local_heap(bestIndex,3);  yy1 = local_heap(bestIndex,4);
        
        if ( match_im_i(xx0,yy0,1) < 0 && match_im_j(xx1,yy1,1) < 0 )
            match_im_i(xx0,yy0,:) = [xx1,yy1];
            match_im_j(xx1,yy1,:) = [xx0,yy0];
			match_heap(end+1,:) = local_heap(bestIndex,:);
            maxMatchingNumber = maxMatchingNumber - 1;
        end
        local_heap(bestIndex,5) = - local_heap(bestIndex,5);
    end
end

match_heap = match_heap( size(initial_match,1)+1:end, :);
match_heap(:,5) = - match_heap(:,5);
