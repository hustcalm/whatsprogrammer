function RtInverse = inverseCameraRt(Rt)

% SFMedu: Structrue From Motion for Education Purpose
% Written by Jianxiong Xiao (MIT License)

RtInverse = [Rt(:,1:3)' Rt(:,1:3)'*(-Rt(:,4))];
