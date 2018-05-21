# Ryan Wong's page on github.io (kinchungwong.github.io)

----

## About GitHub Pages

See https://pages.github.com/ for instructions on setting up.

----

## Read this first

Google is for personal business. Don't risk your business on Google.
Companies that use Google runs the risk of getting entire company's communication infrastructure shut down, if any employee (1) specifies a personal email address as a password recovery email (or somehow allows Google to trace the company's account to that other email address), and (2) that employee did something wrong (and was traced to that personal email) that prompted Google to take action.
The result is that a wide net of "connected accounts" (where the "connection" is merely tangential) got shut down as well.
The insanity is that apparently Google "crawls" for emails that could be tangentially related, and then proceeds to shut down those accounts.
While plenty of concerned Googlers offered to help, the business divisions at Google refused to be contacted.
Forward a link to any recruiters or business associates who may contact you. You may lose a job opportunity, but you wouldn't want to work for them unless they change.  
https://news.ycombinator.com/item?id=17115643

----

## About my work

* C++ programmer
* OpenCV programmer
* Currently half way through a six-month gap during which I will contribute code to OpenCV

----

## Currently working on

*This section contains links to projects owned/maintained by other people or organizations. Please refer to each linked project website for legally-required or contratually-required copyright notices, user agreements, and other legal information.*

*Note: I am **in no way** obliged to make good on anything mentioned in this section. I have total freedom to abandon this work or change course at any time.*

----

### Binary size analysis and reporting in OpenCV

* [Introduction and rationale](https://github.com/opencv/opencv/issues/11157)
* Other OpenCV users who are looking for the same
  * [Link 1 (\#11460)](https://github.com/opencv/opencv/issues/11460)
* Open-source projects which might be useful toward this goal
  * [SymbolSort](https://github.com/adrianstone55/SymbolSort), by Adrian Stone and others, Apache 2.0 License.
* My own incomplete prototype for parsing the disassembly output from DUMPBIN
  * [My sample source code (without a name)](https://gist.github.com/kinchungwong/9ce34edea81012b428e302e3e64bdd67)
  * Note: my incomplete prototype is currently not released as open-source because it is not ready yet.
  * Features
    * Call-graph based on function call instructions parsed from disassembly
  * Omissions
    * Unable to convert decorated function names, because doing so requires the "MSDIA" tool.
      * This problem can be solved if my code can be integrated with Adrian's SymbolSort, because SymbolSort contains interop for the "MSDIA" tool.
* My upcoming plan
  * To study SymbolSort in depth
  * To understand the nuances of this area of work
  * To suggest improvements to SymbolSort
  * To integrate (contribute) my code with (into) SymbolSort
  * To design and implement visualizations and reports that will help OpenCV users understand the compiled binary size of the library

----

### OpenCV SIMD universal intrinsics

----

### For SIMD contributions in OpenCV 3.4 (or a possible 3.5)

* Currently, my work for SIMD on OpenCV 3.4 is limited to passive code reviewing.
  * Currently, contributions to SIMD on OpenCV 3.4 are required to compile and run on three SIMD architectures:
    * x86/x64 SSE/AVX
    * ARM NEON
    * Power Architecture VSX
    * Contributions which break build or doesn't produce identical result on any one architecture are rejected.
    * The burden of proof on performance improvement or non-regression is currently placed on the code contributor.
    * Contributions into the 3.4 branch are required to be C++98 conforming, and cannot use any C++11 features.
  * My development machine is not set up for reliable performance benchmarking.
  * My machine required aggressive thermal throttling (DVFS) to stay cool.
    * [Link 1: dynamic voltage scaling](https://en.wikipedia.org/wiki/Dynamic_voltage_scaling)
    * [Link 2: dynamic frequency scaling](https://en.wikipedia.org/wiki/Dynamic_frequency_scaling)
  * I do not have access to ARM NEON or Power8 machines for unit testing and/or reliable performance benchmarking.
  * However, I do plan to purchase a few ARM Architecture development devices. Once it is ready I might resume my work in this area.

----

### For SIMD contributions in OpenCV 4.0

----

### Proposed coding style enhancement for SIMD moving window in OpenCV 4.0

This proposal allows any image processing algorithms that read from a fixed-size moving-window from the input to be written in a very fluent coding style in C\+\+.

[Link to sample code on my Gist](https://gist.github.com/kinchungwong/94a090ace1bdd67c02cf932c4a4b8a2a)

Firstly, ```v_extract``` and ```v_insert``` will be extended (overloaded) to work on 1D (single-row) and 2D (multi-row) arrays of SIMD vector types.

An example of 1D array of vectors:
```cpp
template <typename vec_type, int nv>
using v_arr = std::array<vec_type, nv>;
```

An example of 2D array of vectors:
```cpp
template <typename vec_type, int nvr, int nvc>
using v_arr2d = std::array<std::array<vec_type, nvc>, nvr>;
```

The new overloads for ```v_extract``` and ```v_insert``` will extract and modify a sub-sequence of elements inside the array of vectors. The sub-sequence does not need to be aligned to the vector boundaries inside the array.

Secondly, the helper functions ```v_extract_around_center``` and ```v_insert_around_center``` apply an offset to the compile-time row/column offsets while calling ```v_extract``` and ```v_insert```.

----

### Modernization of existing SIMD code in image processing algorithms in OpenCV 4.0

* [OpenCV's page on 4.0](https://github.com/opencv/opencv/wiki/OE-4.-OpenCV-4)
* [OpenCV's page on universal intrinsics](https://github.com/opencv/opencv/wiki/OE-27.-Wide-Universal-Intrinsics)

----

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
  * My MSc work was in 3D face recognition
    * *Caveat: this part of my knowledge is completely obsolete.*
    * *Advice to anyone interested: your starting point should be [Active Appearance Model (AAM)](https://en.wikipedia.org/wiki/Active_appearance_model).*
  * Worked on camera document imaging in previous employment
    * Flat model, cylindrical model, text-line-flow model
    * Document image thresholding, denoising, other enhancements
    * Document image feature detection (line detection, mark detection, feature segmentation)
* CPU-based software performance engineering
* Some *outdated* neural network knowledge
* Some C#
  * Some WinForms
* Some mobile
  * I have adapted my C++ code to compile with Android NDK (GCC), iOS Xcode (Clang)
  * In general, OpenCV is a very instructive code base to prepare a C++ programmer to write cross-platform code

----

## Technologies which I know, and which I have neutral feelings about

* Microsoft WIC (Windows Imaging Component)
  * It has taught me:
    * Interface design (API-level and object-level),
    * Memory efficiency, in designing pipeline-able image processing components that use much less transient memory than ordinary designs
    * Memory safety, in resolving a big headache for application programmers (users of the library)

----

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

----

## Areas I might be prevented from working on

* Document image processing (algorithms, design, ideas, suggestions)
  * The information listed above is all I can say. I cannot give details.
* Enterprise document management systems (ideas on user interface design)
  * I cannot say anything about the UI design of particular systems coming from a certain vendor.

----

## Questions I will ignore

* Questions about vulnerabilities and hardening of libtiff, or TIFF file format
  * For questions about libtiff relating to vendor-specific code/products/services, contact the vendor
  * For information or questions about vulnerabilities in libtiff, contact CVE
* Certain questions about my previous employment (unless there is a "need to know")
* Questions about previous salary levels

----
