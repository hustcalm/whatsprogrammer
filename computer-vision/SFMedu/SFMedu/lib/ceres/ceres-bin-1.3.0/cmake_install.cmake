# Install script for directory: /csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ceres" TYPE FILE FILES
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/conditioned_cost_function.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/problem.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/crs_matrix.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/sized_cost_function.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/types.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/local_parameterization.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/normal_prior.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/iteration_callback.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/numeric_diff_cost_function.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/solver.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/fpclassify.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/rotation.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/cost_function.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/autodiff_cost_function.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/loss_function.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/jet.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/ceres.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ceres/internal" TYPE FILE FILES
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/internal/fixed_array.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/internal/port.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/internal/manual_constructor.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/internal/eigen.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/internal/autodiff.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/internal/scoped_ptr.h"
    "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-solver-1.3.0/include/ceres/internal/macros.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-bin-1.3.0/internal/ceres/cmake_install.cmake")
  INCLUDE("/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-bin-1.3.0/examples/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-bin-1.3.0/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/csail/vision-torralba6/people/jxiao/SUNgeon_detector/SUNdetector/optimization/ceres-bin-1.3.0/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
