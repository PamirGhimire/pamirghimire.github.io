---
layout: post
title:  "Build Systems for C++"
author: Pamir Ghimire
date:   2019-10-21 20:38:37 +0200
permalink: /cpp-build-systems/
categories: jekyll update
---

<!-- How C++ compiler works : video -->
<iframe width="560" height="315" src="https://www.youtube.com/embed/3tIqpEmWMLI" frameborder="0" allow="accelerometer; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<br>
<h4> What is a (C++) build system anyway? </h4>
Let's look at CMake and Bazel, two popular build systems for large C++ projects. 

[<b>What is CMake ?</b>](https://cmake.org/overview/)
 CMake is a system that manages the build process. CMake is designed to be used with native build environments (ex : Make on unix). Simple configuration files placed in each source directory (called CMakeLists.txt files) <b> are used to generate standard build files </b> (e.g., Makefiles on Unix and projects/workspaces in Windows MSVC) which are used in <i>the usual way.</i>
 <br><br>
 [<b>What is Bazel ?</b>](https://docs.bazel.build/versions/1.1.0/bazel-overview.html) 
 Bazel is a build and test tool similar to Make, Maven, and Gradle. It uses a human-readable, high-level build language. Bazel builds outputs for multiple platforms.
 <br>

<b>Generalization</b> : CMake produces Make files for C++ projects using CMake configuration files. 
Bazel produces executables (or libraries) directly using Bazel Build files and [user specified C++ toolchain](https://docs.bazel.build/versions/master/tutorial/cc-toolchain-config.html) (gcc, compiler flags, ...). So, a build system saves you the trouble of specifying build instructions to your compiler explicitly, and helps you manage the build process with "human-readable" configuration files.

<!-- both cmake and bazel rebuild the targets if the dependencies change -->
<i>Incremental builds </i> : This comes specially handy when your projects are large, and have many dependencies. 
Both CMake and Bazel track changes you make to your file (time of last modification vs current time, md5 hashes, etc.) and recompile only those files that were changed since the last build (incremental build). For example,
Bazel uses an ['action graph'](https://docs.bazel.build/versions/0.27.0/bazel-overview.html) and checks if files it needs to build for a particular target have 
[time stamps](http://gensoft.pasteur.fr/docs/bazel/0.3.0/bazel-user-manual.html)
 exactly the same as those in its database for incremental builds.


<!-- both cmake and bazel can be used to fetch remote artifacts -->
