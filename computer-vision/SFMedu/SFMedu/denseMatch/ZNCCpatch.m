function descriptor = ZNCCpatch(image, point, HalfSizeWindow)

SizeWindow= 1+2*HalfSizeWindow;

for i=1:size(point,1)
    x = point(i,1);
    y = point(i,2);
    patch = image(x-HalfSizeWindow : x+HalfSizeWindow,y-HalfSizeWindow : y+HalfSizeWindow);
    Mean  = mean(mean(patch));
    Deviation =  sqrt( sum(sum(patch .^ 2)) - (SizeWindow * Mean)^2 );
    descriptor{i} = (patch - Mean) ./ Deviation;
end

