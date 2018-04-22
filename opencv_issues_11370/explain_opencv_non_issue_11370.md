# Explain the OpenCV non-Issue #11370

[Link to non-issue (https://github.com/opencv/opencv/issues/11370)](https://github.com/opencv/opencv/issues/11370)

<details><summary>The code sample that triggers the error</summary>

```cpp
#include <iostream>
#include <opencv2/core.hpp>
void reproduce_issue_11370_error()
{
    cv::Mat image = cv::Mat::zeros(480, 640, CV_8UC1);
    std::cout << image.at<int>(476,638) << std::endl; // No Error
    std::cout << image.at<int>(477,638) << std::endl; // Error is HERE
}
```

</details>

## Why? (1st)

Let's apply the [Five Whys method](https://en.wikipedia.org/wiki/5_Whys).

The first reason is, of course, the battery is dead. (Did you read the Wikipedia article?)

## Why? (2nd)

It causes an memory access violation, or access outside a memory allocation's bounds.

The original memory allocation was for ```(480 * (640 * sizeof(uchar) + padding))```. In this case, padding was zero.

## But wait? (rebuttal to 2nd)

However, from reading the code, we notice that there are 480 rows in the matrix, and we're only reading from row 477, the fourth row from the bottom, based on our code-reading. What could go wrong?

Even if we're reading past the end of one row, typically the current and next rows are allocated in the same piece, which means it should not be triggering an invalid memory access, unless the program is compiled with OpenCV-aware instrumentation.

## Why? (3rd) (answers the rebuttal to 2nd)

----

## My test code which reveals the issue

[show_pixel_addresses.cpp](./show_pixel_addresses.cpp)

If I build and run this in debug mode, it would throw an exception due to a ```CV_DbgAssert```. This is how we intend to prevent users from making this mistake. (See ***How do we prevent this*** below.)

If I build and run this in release mode, here is the output:
<details><summary>Output from my MSVC15 x64 Release</summary>

```txt
============================================================================
ptrFuncAt_8UC1_RowCol = 305918
ptrFuncPtr_8UC1_RowCol = 305918
============================================================================
ptrFuncAt_8UC1_RowColz = 305280
ptrFuncPtr_8UC1_RowColz = 305280
ptrFuncPtr_8UC1_RowOnly = 305280
============================================================================
ptrFuncAt_32SC1_RowCol = 307832
ptrFuncPtr_32SC1_RowCol = 305918
============================================================================
ptrFuncAt_32SC1_RowColz = 305280
ptrFuncPtr_32SC1_RowColz = 305280
ptrFuncPtr_32SC1_RowOnly = 305280
============================================================================
```

</details>

From the release mode output, I saw an odd one: ```307832```. It corresponds to this expression inside my sample:

```cpp
mat.at<int>(477, 638)
```

The answer is simple. *Because I told this method to **assume*** the matrix's pixel type is ```CV_32SC1```. It follows that assumption, and calculates the pixel's address as [(see: mat.inl.hpp, line 1093)](https://github.com/opencv/opencv/blob/4b2d1aaeea52e07dff6e925a86313bd3c2f66e8b/modules/core/include/opencv2/core/mat.inl.hpp#L1093):

```cpp
return ((_Tp*)(data + step.p[0] * i0))[i1];
```

Compare this to the ```ptr<T>()``` method: [(see: mat.inl.hpp, line 972)](https://github.com/opencv/opencv/blob/4b2d1aaeea52e07dff6e925a86313bd3c2f66e8b/modules/core/include/opencv2/core/mat.inl.hpp#L972)

```cpp
return (_Tp*)(data + i0 * step.p[0] + i1 * step.p[1]);
```

In the ```at<T>()``` method, the column index doesn't need a multiplication with ```step.p[1]```, *because I told the method to **assume*** it is ```sizeof(int)```.

----

# Lessons for OpenCV users (*and OpenCV library developers too*)

Declaring a matrix as one type (such as ```CV_8UC1```, which corresponds to ```uchar```) and then accessing its pixels by calling its ```at<T>()``` method with a different type (such as ```mat.at<int>(row, col)```) is strictly unsupported.

----

# How do we prevent this

1. Try debug build
2. Try Address Sanitizer (ASan) available for Clang *and* on Apple Xcode
3. Read the OpenCV documentation and follow the guidelines
4. Read the OpenCV C++ implementation code

## Debug build

OpenCV's methods already contain ```CV_DbgAssert``` which throws an exception with an explanation when parameters are invalid.

## Try Address Sanitizer (ASan)

Instructions for Apple Xcode

1. https://developer.apple.com/documentation/code_diagnostics/address_sanitizer
2. https://developer.apple.com/documentation/code_diagnostics/address_sanitizer/enabling_the_address_sanitizer

## Read the OpenCV documentation and follow the guidelines

\[\[TODO\]\] *you. no, not me. no. everyone. me included.*

## Reading the OpenCV C++ implementation code

### Class ```cv::Mat``` (non-template)

#### Method ```at<T>(...)``` (template), overloaded for different arguments

[Declarations (mat.hpp, lines 1894 - 1946)](https://github.com/opencv/opencv/blob/4b2d1aaeea52e07dff6e925a86313bd3c2f66e8b/modules/core/include/opencv2/core/mat.hpp#L1894-L1946)

[Definitions: (mat.inl.hpp, lines 1085 - 1199)](https://github.com/opencv/opencv/blob/4b2d1aaeea52e07dff6e925a86313bd3c2f66e8b/modules/core/include/opencv2/core/mat.inl.hpp#L1085-L1199)

### Method ```ptr(...) -> uchar``` (non-template) and ```ptr<T>(...) -> T``` (template), overloaded for different arguments

[Declarations (mat.hpp, lines 1808 - 1862)](https://github.com/opencv/opencv/blob/4b2d1aaeea52e07dff6e925a86313bd3c2f66e8b/modules/core/include/opencv2/core/mat.hpp#L1808-L1862) 

[Definitions (mat.inl.hpp, lines 917 - 1083)](https://github.com/opencv/opencv/blob/4b2d1aaeea52e07dff6e925a86313bd3c2f66e8b/modules/core/include/opencv2/core/mat.inl.hpp#L917-L1083) 
