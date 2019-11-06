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
 Bazel is a build and test tool similar to Make, Maven, and Gradle. It uses a human-readable, high-level build language. Bazel <b>builds outputs</b> for multiple platforms.
 <br>

<b>Generalization</b> : <i> Build systems produce Make files or binaries from 'simple' configuration files </i>
<br> CMake produces Make files for C++ projects using CMake configuration files. 
Bazel produces executables (or libraries) directly using Bazel Build files and [user specified C++ toolchain](https://docs.bazel.build/versions/master/tutorial/cc-toolchain-config.html) (gcc, compiler flags, ...). So, a build system saves you the trouble of specifying build instructions to your compiler explicitly, and helps you manage the build process with "human-readable" configuration files. 

A build system also delivers some other benefits like : 

<!-- both cmake and bazel rebuild the targets if the dependencies change -->
<i><b>Incremental builds </b></i> : Very important for achieving fast builds when your projects are large, and have many dependencies. 
Both CMake and Bazel track changes you make to your files (time of last modification vs current time, md5 hashes, etc.) and recompile only those files that were changed since the last build (hence, incremental build). 
For example, Bazel uses an ['action graph'](https://docs.bazel.build/versions/0.27.0/bazel-overview.html) and checks if files it needs to build for a particular target have 
[time stamps](http://gensoft.pasteur.fr/docs/bazel/0.3.0/bazel-user-manual.html)
 exactly the same as those in its database for incremental builds.



<!-- build systems help you manage non out-of-source builds (using remote artifacts) -->
<i><b>Using External (and cloud-based) Dependencies </b></i> : Using a build system, you can also depend on code outside of your local repository for building your targets. For example, in Bazel, you can define using `http_archive` in your `WORKSPACE` a cloud-hosted repo as a target that other local targets can depend on. For example : 

In your `WORKSPACE` file : <br>
```
http_archive(
    name = "googletest",
    path = "googletest-release-x.y.z.tar.gz",
    repo = "https://url-of-google-test",
    sha256 = "some-unique-sha",
    strip_prefix = "googletest-release-a.b.c",
)
```

And then in one of your local `BUILD` files : <br>
```
cc_test(
    name = "your_very_important_test",
    srcs = glob([
        "test/*.cpp",
        "test/*.h",
    ]),

    deps = [
        ":your-local-library-to-be-tested",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
```

Similarly, in CMake, you can do the following : 
```
if(YOUR_PROJECT_NAME_BUILD_BOOST)
    set(BOOST_TARGET boost)
    ExternalProject_Add(${BOOST_TARGET}
            URL https://url/to/boost/tar/boost_1_61_0.tar.gz
            PREFIX ${BUILD_DIR}
            BUILD_IN_SOURCE 0
            BUILD_ALWAYS 0
            SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/boost
            BINARY_DIR ${BUILD_DIR}/boost_build
            INSTALL_DIR ${CMAKE_INSTALL_PREFIX}
            CONFIGURE_COMMAND cd <SOURCE_DIR> && ...
            BUILD_COMMAND cd <SOURCE_DIR> && ...
            INSTALL_COMMAND cd <SOURCE_DIR> && ...
            DEPENDS ${SOME_OTHER_TARGET_LIKE_ZLIB}
            )
    set(BOOST_CMAKE_FLAGS -DBOOST_ROOT=${CMAKE_INSTALL_PREFIX})
endif()
```