#include <iostream>
#include <vector>
#include <cassert>
#include<cmath>
#include <algorithm>

template<typename Iterator,typename Num>
Iterator binarySearch(Iterator itBegin, Iterator itEnd, Num value) {
    while (itEnd - itBegin) {
        auto pointerMid = itBegin + (itEnd - itBegin) / 2;

        if (*pointerMid == value) {
            return pointerMid;
        }
        if (value < *pointerMid) {
          itEnd = pointerMid;
        } else if (value > *pointerMid) {
          itBegin = pointerMid + 1;
        }
    }

    return itEnd;
}

template<typename T>
bool testBinarySerch(typename std::vector<T> arr, T num) {
    auto result = binarySearch(std::begin(arr), std::end(arr), num);
    auto expexted = std::find(arr.cbegin(), arr.cend(), num);
    return expexted == result;
}

int main() {
    assert(testBinarySerch(std::vector<int>{},6));
    assert(testBinarySerch(std::vector<int>{1},1));
    assert(testBinarySerch(std::vector<int>{1},6));
    assert(testBinarySerch(std::vector<int>{-4,-3,0,6,7,8,9},-9));
    assert(testBinarySerch(std::vector<int>{1,2,3,4,5,6,7,8,9},0));
    assert(testBinarySerch(std::vector<int>{1,2,3,4,5,7,8,9},7));
    assert(testBinarySerch(std::vector<double>{1.4,2.4,3.3,4.2,5.1,6.1,7.5,8.43,9.2},6.8));

    return 0;
}
