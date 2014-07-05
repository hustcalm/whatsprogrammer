SFMedu: Structrue From Motion for Education Purpose
Written by Jianxiong Xiao (MIT License)

Function:

This code demonstrates how a traditional structure from motion pipeline is done and how to compute a dense point cloud by matching propagation in a simplest way. It is mainly designed for teaching a computer vision lecture in MIT. Please check the slides together with this code release.

Run:

run SFMedu.m in Matlab.

Compile:

1. You need to compile the ceres-solver and related libraries in ./lib/ceres. Please refer to the document of ceres-solver.
2. In ./ba2D, you need to compile ba2D.cc. Example scripts are in compile.sh file.

Copyright Notice:

The third party library in the lib folders may have different licenses that you need to follow. We include them for the convinience for the users and don't imply any copyright issues.

How to make it better? (i.e. potential homework problem, class final project, or research direction):

1. The two view essential matrix estimation from fundamental matrix is very unstable. Consider using a 5-point algorithm (http://cmp.felk.cvut.cz/minimal/5_pt_relative.php) with two view bundle adjustment (e.g. initialize from the same camera projection matrices [I|0]).
2. The focal length is not computed on the fly. Consider to estimate the focal length by autocalbiration (http://mit.edu/jxiao/Public/software/autocalibrate/autocalibration_lin.m) or exhaustive search to find the solution with minimal reprojection error.
3. The matching graph now is ordered by neighboring relationship only. Consider to build a better graph such as bundler (http://phototour.cs.washington.edu/bundler/).
4. Consider to make this work for a generic video (e.g. download a youtube video and reconstruct it).
5. Consider to make this work faster (e.g. in real time).
