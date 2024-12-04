#include <iostream>
#include <vector>
#include <cassert>

auto binarySearch(std::vector<int>& arr,int num){
    int left=0,mid,right=arr.size()-1;

    while(left<=right){
        mid=left+(right-left)/2;

        if(arr[mid]==num)
        {
            return arr.begin()+mid;
        }
        if(arr[mid]<num)
        {
            left=mid+1;
        }else {
            right=mid-1;
        }
    }
    return arr.end();
}

bool testBinarySerch(std::vector<int>arr,int num)
{
    auto expexted=arr.end();
    auto result=binarySearch(arr,num);

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==num)
        {
            expexted=arr.begin()+i;
            break;
        }
    }

    return expexted==result;
}

int main(){
    std::vector<int> arr={1,2,3,4,5,6,7,8,9};

    assert(testBinarySerch(std::vector<int>{},6));
    assert(testBinarySerch(std::vector<int>{1},1));
    assert(testBinarySerch(std::vector<int>{1},6));
    assert(testBinarySerch(std::vector<int>{-4,-3,0,6,7,8,9},-3));
    assert(testBinarySerch(std::vector<int>{1,2,3,4,5,6,7,8,9},0));
    assert(testBinarySerch(std::vector<int>{1,2,3,4,5,6,7,8,9},6));

    return 0;
}