function Y3D = transformRT(X3D, Rt, isInverse)

% SFMedu: Structrue From Motion for Education Purpose
% Written by Jianxiong Xiao (MIT License)

if nargin<3 || ~isInverse
    Y3D = Rt(:,1:3) * X3D + repmat(Rt(:,4),1,size(X3D,2));
else
    Y3D = Rt(:,1:3)' * (X3D - repmat(Rt(:,4),1,size(X3D,2)));
end
