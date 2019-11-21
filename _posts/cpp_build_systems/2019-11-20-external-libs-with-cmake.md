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

<b>Download the Libraries </b> 
Download links:
[OpenCV 3.4](){:target="_blank"}  
[Eigen3](){:target="_blank"}

<b>Build the Libraries</b>
After your downloads are complete, extract the compressed files. 

<b>Build and Install OpenCV</b>
```
$ cd /full/path/opencv_extraction_dir
$ mkdir build && cd build
$ mkdir opencv_install_dir
$ cmake .. -DCMAKE_INSTALL_PREFIX=/full/path/opencv_install_dir
$ make -j2 
$ make install
```

The `-DCMAKE_INSTALL_PREFIX` argument tells CMake to produce a Makefile such that
when you run `make install`, the installation is performed in the directory that you specify. 
Later, you can use this path in your project's CMake file to specify where `package` OpenCV 
can be found.

Now, for finding the OpenCV package, this is the path you need to specify to your project's CMakeFile : 
`/full/path/opencv_install_dir/lib/cmake/opencv3`
At this path, you will also find `OpenCVConfig.cmake`. Check this file to see the CMake variables 
that the OpenCV package defines for use in external projects.

<i>Note : </i> If you are trying this with a version of OpenCV that complains about Eigen headers during `make`, when running `CMake`, specify where the cmake config file for Eigen can be found using the flag 
`-DEigen3_DIR` and where the includes can be found using `-DEIGEN3_INCLUDE_DIR` (maybe first read the installation guide for Eigen below). 

<b>Build and Install Eigen:</b>
```
$ cd /full/path/eigen_extraction_dir
$ mkdir build && cd build
$ mkdir eigen_install_dir
$ cmake .. -DCMAKE_INSTALL_PREFIX=/full/path/eigen_install_dir
$ make -j2 
$ make install
```

You can now find the cmake config file for "finding" Eigen3 package at /full/path/eigen_install_dir/share/eigen3/cmake