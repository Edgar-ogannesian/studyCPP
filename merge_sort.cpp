#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int mergeAndCount(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> tmp;
    tmp.reserve(right - left);

    std::copy(arr.begin() + left, arr.begin() + right, std::back_inserter(tmp));

    int tmp_mid = mid - left;

    int i = 0;
    int j = tmp_mid;
    int k = left;
    int inv_count = 0;

    while (i < tmp_mid && j < tmp.size())
    {
        if (tmp[i] <= tmp[j])
        {
            arr[k] = tmp[i];
            i++;
        }
        else
        {
            arr[k] = tmp[j];
            inv_count += (tmp_mid - i);
            j++;
        }
        k++;
    }

    std::copy(tmp.begin() + i,tmp.begin() + tmp_mid,arr.begin() + k);
    k += tmp_mid - i;
    std::copy(tmp.begin() + j, tmp.begin() + tmp_mid, arr.begin() + k);

    return inv_count;
}

int mergeSortAndCount(std::vector<int>& arr, int left, int right)
{
    int inv_count = 0;

    if (right - left < 2)
    {
        return inv_count;
    }

    int mid = left + (right - left) / 2;
    inv_count += mergeSortAndCount(arr, left, mid);
    inv_count += mergeSortAndCount(arr, mid, right);
    inv_count += mergeAndCount(arr, left, mid, right);

    return inv_count;
}

int mergeSortAndCount(std::vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size());
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
    //12455
}
