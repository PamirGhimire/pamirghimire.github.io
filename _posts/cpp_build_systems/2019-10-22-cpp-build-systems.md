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

<b>What are build systems anyway?</b><br>
Three actors in this story:<br>
Source files \| Compiler \| Compiler-instructions 

When you write C++, you create a bunch of files: .hs and .cpps. These constitute your project. 
These files have to be consumed by a software, i.e., the compiler to produce your software (an executable, static/dynamic libs, ...).
For this, the compiler has build your source files, link the resulting object files with precompiled libs, and 
produce an executable that is tailored to run on a particular OS (your particular installation). All arguments that are hence 
fed to the compiler need to very specific (names of files, compiler options, etc.).

While this might be easily manageable for small projects, for large projects, this is not practical. Hence the need for 
build systems. Tell these systems about your source files, locations where they can find library files that you want to use, 
and compiler options you'd like, and they can take this information and produce something that can be fed to the 
compiler to produce your target. 

What might you desire from a build system? Take a clue from this guy on [stackoverflow](https://stackoverflow.com/questions/12017580/c-build-systems-what-to-use){:target="_blank"}:<br>
1. Support for C++98/14/17
2. Cross platform (Linux as main target, but able to build on at least Windows as well)
3. Decent unit testing support
4. Support for multiple modules for separating code out
5. Easy to maintain

Now a survey of surveys/posts/etc. on build systems for C++.

1. [An overview of build systems (mostly for C++ projects)](https://medium.com/@julienjorge/an-overview-of-build-systems-mostly-for-c-projects-ac9931494444){:target="_blank"} <br>
Talks about 12 build systems.<br>
Summary : There are many build systems, some very old, most are unnecessarily complex, overpromise, and use their own 
language. CMake is currently the best bet. Premake is also not completely detestable.


2. [The stackoverflow post with question about choice for build-system](https://stackoverflow.com/questions/12017580/c-build-systems-what-to-use){:target="_blank"}<br>
General consensus here is again in favor of CMake, one recommendation for Scons due to its 'bullet-proof' builds, 
but lots of complaints about it being slow. [This post]{:target="_blank"}, however, argues that scons is not actually slow. 
Oh, and you write build files using python when using scons. The same post also shows how using make directly is dramatically
faster for large projects (with thousands of C files). If you program in python, I would recommend taking a look at SCons project, 
for example, in [this video](https://www.youtube.com/watch?v=tkXsSB0t7PU){:target="_blank"} since it might make the whole build 
process quite transparent for you.  

<!-- build systems help you manage non out-of-source builds (using remote artifacts) -->
Using a build system, you can also depend on code outside of your local repository for building your targets (executables, libraries, ...). For example, in Bazel, you can define using http_archive in your WORKSPACE a cloud-hosted repo as a target that other local targets can depend on. For example : 

In your WORKSPACE file : <br>
http_archive(
    name = "googletest",
    path = "googletest-release-x.y.z.tar.gz",
    repo = "https://url-of-google-test",
    sha256 = "some-unique-sha",
    strip_prefix = "googletest-release-a.b.c",
)

<br>

And then in one of your local BUILD files : <br>
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


Similarly, in CMake, you can do the following : 
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
            CONFIGURE_COMMAND cd <SOURCE_DIR> && ./bootstrap.${SCRIPT_EXTENSION} --prefix=<INSTALL_DIR> --with-libraries=atomic,container,date_time,exception,filesystem,graph,iostreams,log,math,program_options,regex,serialization,system,test,thread
            BUILD_COMMAND cd <SOURCE_DIR> && ./b2 --prefix=<INSTALL_DIR> variant=${CMAKE_BUILD_TYPE_LOWERCASE} link=shared threading=multi -j8
            INSTALL_COMMAND cd <SOURCE_DIR> && ./b2 variant=${CMAKE_BUILD_TYPE_LOWERCASE} link=shared threading=multi install
            DEPENDS ${ZLIB_TARGET}
            )
    set(BOOST_CMAKE_FLAGS -DBOOST_ROOT=${CMAKE_INSTALL_PREFIX})
endif()
