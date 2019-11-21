---
layout: post
title:  "Using Opencv and Eigen in a CMake Project"
author: Pamir Ghimire
date:   2019-11-20 20:38:37 +0200
permalink: /opencv-eigen-in-cmake/
categories: jekyll update
---

In this post, we will see how to use third party libraries, namely, OpenCV and Eigen
in your CMake C++ project. We will use modern CMake.

```
My CMake version : 3.10.2
```

<b>Download the Libraries </b><br> 

[OpenCV 3.4](https://codeload.github.com/opencv/opencv/zip/3.4.0){:target="_blank"}  
[Eigen3](https://bitbucket.org/eigen/eigen/get/3.3.7.tar.gz){:target="_blank"}

<b>Build the Libraries</b><br>
After your downloads are complete, extract the compressed files. 

<i>Build and Install OpenCV : </i>
```
$ cd /full/path/to/where_you_unzipped_opencv
$ mkdir build && cd build
$ mkdir opencv_install_dir
$ cmake .. -DCMAKE_INSTALL_PREFIX=/full/path/to/where_you_unzipped_opencv/build/opencv_install_dir
$ make -j2 
$ make install
```

The `-DCMAKE_INSTALL_PREFIX` argument tells CMake to produce a Makefile such that
when you run `make install`, the installation is performed in the directory that you specify. 
Later, you can use this path in your project's CMakeFile to specify where `package` OpenCV 
can be found.


<i>Note : </i> If you are trying this with a version of OpenCV that complains about Eigen headers during `make`, when running `CMake`, specify where the cmake config file for Eigen can be found using the flag 
`DEigen3_DIR` and where the includes can be found using the flag `DEIGEN3_INCLUDE_DIR` (maybe first read the installation guide for Eigen below). 

<i>Build and Install Eigen:</i>
```
$ cd /full/path/to/where_you_unzipped_eigen
$ mkdir build && cd build
$ mkdir eigen_install_dir
$ cmake .. -DCMAKE_INSTALL_PREFIX=/full/path/to/where_you_unzipped_eigen/build/eigen_install_dir
$ make -j2 
$ make install
```

<b>Setting Up Your Project:</b>

Set up a project directory as follows : 

```
Project_dir
    -CMakeLists.txt
    -apps
        -CMakeLists.txt
        -yourapp.cpp
    -build
```
Now, in your top `CMakeLists` file, you can set up your project as follows :

```
cmake_minimum_required (VERSION 3.1)
project (YourCmakeProjectName)

set(OpenCV_DIR "/full/path/to/where_you_unzipped_opencv/build/opencv_install_dir/share/OpenCV")
find_package(OpenCV REQUIRED PATHS OpenCV_DIR)

set(Eigen3_DIR "/full/path/to/where_you_unzipped_eigen/build/eigen_install_dir/share/eigen3/cmake")
find_package(Eigen3 REQUIRED PATHS Eigen3_DIR)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIRS}
)

add_subdirectory(apps)
```

Note that here we used the installation directories that we specified earlier using the `CMAKE_INSTALL_PREFIX` flag
to specify the paths where Eigen and OpenCV packages can be found by our CMake project.

The `include_directories` directive in the project's top-level CMake file makes sure that the source files in all subdirectories
can see the headers specified here at the top. 

In the `CMakeLists` file inside the apps folder, you can arrange for your source code in `yourapp.cpp` to be compiled into an 
executable binary as follows: 

```
cmake_minimum_required (VERSION 3.1)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCE_FILES ${PROJECT_SOURCE_DIR}/apps/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/apps/*.h)

include_directories(
    ${PROJECT_SOURCE_DIR}/apps/
)

add_executable(nameOfYourProjectBinary ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(nameOfYourProjectBinary ${OpenCV_LIBS} Eigen3::Eigen)
```

The `EXECUTABLE_OUTPUT_PATH` variable specifies where the binary will be placed when you build your project (using make, for example).
In this project, we have no header files, but in case there were any present in the 'apps' directory, they would have been found by the 
`GLOB` for `HEADER_FILES`.

The variables that specify the paths for linking your target to the external libraries (here, for example, OpenCV_LIBS) can be found in their respective `xyzConfig.cmake` file (which you can find at the location that you specified for `find_package`).

And voila, you now know how to set up a simple CMake project that links against two external libraries. 