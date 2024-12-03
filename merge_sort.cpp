#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int mergeAndCount(std::vector<int>& arr, int left, int right) {
    int mid=left+(right-left)/2;
    int n1=mid-left+1;
    int n2=right-mid;

    std::vector<int> L(n1), R(n2);

    std::copy(arr.begin()+left, arr.begin()+mid+1, L.begin());
    std::copy(arr.begin()+mid+1, arr.begin()+right+1, R.begin());

    int i=0, j=0, k=left;
    int inv_count=0;

    while (i<n1 && j<n2) {
        if (L[i]<=R[j]) {
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=R[j];
            inv_count+=(n1-i);
            j++;
        }
        k++;
    }

    std::copy(L.begin()+i,L.end(),arr.begin()+k);
    std::copy(R.begin()+j,R.end(),arr.begin()+k+n1-i);

    return inv_count;
}

int mergeSortAndCount(std::vector<int>& arr, int left, int right) {
    int inv_count=0;

    if (left<right) {
        int mid=left+(right-left)/2;
        inv_count+=mergeSortAndCount(arr,left,mid);
        inv_count+=mergeSortAndCount(arr, mid+1,right);
        inv_count+=mergeAndCount(arr, left, right);
    }
    return inv_count;
}

int mergeSortAndCount(std::vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size()-1);
}

bool testMergeSort(std::vector<int> arr)
{
    auto expected=arr;
    std::sort(std::begin(expected), std::end(expected));
    mergeSortAndCount(arr);

    return arr==expected;
}

int main() {
    assert(testMergeSort(std::vector<int>{}));
    assert(testMergeSort(std::vector<int>{1}));
    assert(testMergeSort(std::vector<int>{1, 2, 3}));
    assert(testMergeSort(std::vector<int>{1, 3, 5, 2, 4, 6}));
    assert(testMergeSort(std::vector<int>{9,8,7,6,5,4,3,2,1}));
    return 0;
}
