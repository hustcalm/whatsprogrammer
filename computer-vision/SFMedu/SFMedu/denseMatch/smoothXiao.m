function smoothed_im = smooth(im, IsHorizontal, K, kernel_size)


kernel = [1:(kernel_size-1)].^2;
kernel = [kernel(end:-1:1) 0 kernel];
kernel = exp(K * kernel);
kernel = kernel / sum(kernel);

if IsHorizontal ~= true
    kernel = kernel';
end

smoothed_im = imfilter(im, kernel);
