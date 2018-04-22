#include <cstdint>
#include <string>
#include <iostream>
#include <opencv2/core.hpp>

std::intptr_t getPtrDiff(const void* p1, const void* p0)
{
    const auto v1 = reinterpret_cast<std::uintptr_t>(p1);
    const auto v0 = reinterpret_cast<std::uintptr_t>(p0);
    return (v1 > v0) ? static_cast<std::intptr_t>(v1 - v0) :
        (-static_cast<std::intptr_t>(v0 - v1));
}

void Test_Issues_11370()
{
    cv::Mat mat(480, 640, CV_8UC1);

    const void* ptrStart = mat.data;
    // 
    const void* ptrFuncAt_8UC1_RowCol = &(mat.at<uchar>(477, 638));
    const void* ptrFuncPtr_8UC1_RowCol = mat.ptr<uchar>(477, 638);
    // 
    const void* ptrFuncAt_8UC1_RowColz = &(mat.at<uchar>(477, 0));
    const void* ptrFuncPtr_8UC1_RowColz = mat.ptr<uchar>(477, 0);
    const void* ptrFuncPtr_8UC1_RowOnly = mat.ptr<uchar>(477);
    // 
    const void* ptrFuncAt_32SC1_RowCol = &(mat.at<int>(477, 638));
    const void* ptrFuncPtr_32SC1_RowCol = mat.ptr<int>(477, 638);
    // 
    const void* ptrFuncAt_32SC1_RowColz = &(mat.at<int>(477, 0));
    const void* ptrFuncPtr_32SC1_RowColz = mat.ptr<int>(477, 0);
    const void* ptrFuncPtr_32SC1_RowOnly = mat.ptr<int>(477);
    //
    std::string banner(76, '=');
    std::cout
        << banner << "\n"
        << "ptrFuncAt_8UC1_RowCol = " << getPtrDiff(ptrFuncAt_8UC1_RowCol, ptrStart) << "\n"
        << "ptrFuncPtr_8UC1_RowCol = " << getPtrDiff(ptrFuncPtr_8UC1_RowCol, ptrStart) << "\n"
        << banner << "\n"
        << "ptrFuncAt_8UC1_RowColz = " << getPtrDiff(ptrFuncAt_8UC1_RowColz, ptrStart) << "\n"
        << "ptrFuncPtr_8UC1_RowColz = " << getPtrDiff(ptrFuncPtr_8UC1_RowColz, ptrStart) << "\n"
        << "ptrFuncPtr_8UC1_RowOnly = " << getPtrDiff(ptrFuncPtr_8UC1_RowOnly, ptrStart) << "\n"
        << banner << "\n"
        << "ptrFuncAt_32SC1_RowCol = " << getPtrDiff(ptrFuncAt_32SC1_RowCol, ptrStart) << "\n"
        << "ptrFuncPtr_32SC1_RowCol = " << getPtrDiff(ptrFuncPtr_32SC1_RowCol, ptrStart) << "\n"
        << banner << "\n"
        << "ptrFuncAt_32SC1_RowColz = " << getPtrDiff(ptrFuncAt_32SC1_RowColz, ptrStart) << "\n"
        << "ptrFuncPtr_32SC1_RowColz = " << getPtrDiff(ptrFuncPtr_32SC1_RowColz, ptrStart) << "\n"
        << "ptrFuncPtr_32SC1_RowOnly = " << getPtrDiff(ptrFuncPtr_32SC1_RowOnly, ptrStart) << "\n"
        << banner << "\n"
        << std::flush;
    //
    std::string unused;
    std::cout << banner << "\n"
        << "Done. Press enter key to quit.\n"
        << banner << "\n"
        << std::flush;
}
