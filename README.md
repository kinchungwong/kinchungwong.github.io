# Ryan Wong's page on github.io

## About GitHub Pages

See https://pages.github.com/ for instructions on setting up.

## About Ryan Wong (kinchungwong)

## Work

* C++ programmer
* OpenCV programmer
* Currently half way through a six-month gap during which I will contribute code to OpenCV

## Currently working on

* OpenCV 4.0 SIMD intrinsics
  * [OpenCV's page on 4.0](https://github.com/opencv/opencv/wiki/OE-4.-OpenCV-4)
  * [OpenCV's page on universal intrinsics](https://github.com/opencv/opencv/wiki/OE-27.-Wide-Universal-Intrinsics)
  * [My *piecemeal* contributions, *growing bit by bit everyday*](https://github.com/kinchungwong/cv400_intrinsics_playground)
  * Goal 1: make it easy for programmers outside the OpenCV core team to understand the algorithms, even if they are implemented in SIMD.
  * Goal 2: make it easier to port existing implementations to newer SIMD architectures, such as those having wider widths, or vector-length-agnostic.

## Current objective

* Contribute to OpenCV 4.0
  * Moving code base to C++11
  * Resolving issues
  * Refactoring existing image processing code to make them easier to understand (for programmers who are not OpenCV core developers)
  * Continue to improve image processing performance
  * Ideas for logging

## Secondary objective

* Learn Python (as a programming language for hosting continuous integration systems)
* Learn database stuff
* Learn modern neural network tools
* Learn [Halide, a DSL for implementing, compiling, transforming, synthesizing image processing and computational photography algorithms](http://halide-lang.org/)

## Tertiary objective

* Thinking about the do's and dont's before I sign my next NDA (non-disclosure agreement) or work-for-hire contract

## Skills

* C++
  * C++11, 14, 17, etc
  * I would like to work with projects that upgrade to the latest C++ compilers every 1-3 years
* OpenCV
  * My entire career would not exist without OpenCV
* SIMD programming
  * SSE 128-bit (SSE2 - SSE4.2)
  * Some ARM NEON
* Multicore programming
  * Uses MS PPL (C++), .NET TPL (C#)
* Image processing
  * Invention and implementation of new image processing algorithms
  * Optimizations of image processing algorithms (using SIMD and multicore)
  * Quality assurance for image processing algorithm implementations
* Some computer vision knowledge
  * My MSc work was in 3D face recognition<br/>(*Caveat: this part of my knowledge is completely obsolete*)
  * Worked on camera document imaging in previous employment
    * Flat model, cylindrical model, text-line-flow model
    * Document image thresholding, denoising, other enhancements
    * Document image feature detection (line detection, mark detection, feature segmentation)
* CPU-based software performance engineering
* Some (*outdated*) neural network knowledge
* Some C#
  * Some WinForms
* Some mobile
  * I have adapted my C++ code to compile with Android NDK (GCC), iOS Xcode (Clang)
  * In general, OpenCV is a very instructive code base to prepare a C++ programmer to write cross-platform code

## Technologies which I know, and which I have neutral feelings about

* Microsoft WIC (Windows Imaging Component)
  * It has taught me:
    * Interface design (API-level and object-level),
    * Memory efficiency, in designing pipeline-able image processing components that use much less transient memory than ordinary designs
    * Memory safety, in resolving a big headache for application programmers (users of the library)

## Technologies I prefer not to work on

* Microsoft C++/CLI (also known as C++ .NET, C++/CX)
  * It has been a very important glue between two technologies
    * Rapid application development in C#
    * Computationally-intensive non-IO code in C++
  * However, it has finally reached a dead-end after a decade of good service.
    * https://github.com/dotnet/corefx/issues/24444
  * Users should migrate from C++/CLI to P/Invoke to ensure cross-platform readiness
* MFC
* Gdiplus

## Areas I might be prevented from working on

* Document image processing (algorithms, design, ideas, suggestions)
  * The information listed above is all I can say. I cannot give details.
* Enterprise document management systems (ideas on user interface design)
  * I cannot say anything about the UI design of particular systems coming from a certain vendor.

## Questions I will ignore

* Questions about vulnerabilities and hardening of libtiff, or TIFF file format
  * For questions about libtiff relating to vendor-specific code/products/services, contact the vendor
  * For information or questions about vulnerabilities in libtiff, contact CVE
* Certain questions about my previous employment (unless there is a "need to know")
* Questions about previous salary levels
