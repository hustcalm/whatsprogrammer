function derivate_im = derivate(im, IsHorizontal, K, kernel_size)

kernel = 1:(kernel_size-1);
kernel = kernel .* exp( K * (kernel .^ 2));
kernel = kernel / sum(kernel);
kernel = [kernel(end:-1:1) -kernel];


if IsHorizontal ~= true
    kernel = kernel';
end

derivate_im = imfilter(im, kernel);