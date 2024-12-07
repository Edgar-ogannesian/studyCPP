#include <iostream>
#include <vector>
#include <cassert>
#include<cmath>

template<typename T>
typename std::vector<T>::iterator binarySearch(std::vector<T>& arr,T num){
    int n=arr.size()/2 + arr.size()%2;
    int flag=0;
    typename std::vector<T>::iterator pointer=arr.begin() + arr.size()/2 - (arr.size()%2==0);

    if(arr.empty())
    {
        return arr.end();
    }

    do{
        flag++;
        n=n/2 + (n%2) - (n==3);

        if(*pointer==num)
        {
            return pointer;
        }else if(num>*pointer && pointer!=arr.end())
        {
            pointer+=n;
        }else if(num<*pointer && pointer!=arr.begin())
        {
            pointer-=n;
        }
    }while(flag<std::log2(arr.size()));

    return arr.end();
}

template<typename T>
bool testBinarySerch(typename std::vector<T>arr,T num)
{
    typename std::vector<T>::iterator expexted=arr.begin();
    typename std::vector<T>::iterator result=binarySearch(arr,num);

    while (expexted!=arr.end())
    {
        if(num==*expexted)
        {
            break;
        }
        expexted++;
    }

    return expexted==result;
}

int main(){

    assert(testBinarySerch(std::vector<int>{},6));
    assert(testBinarySerch(std::vector<int>{1},1));
    assert(testBinarySerch(std::vector<int>{1},6));
    assert(testBinarySerch(std::vector<int>{-4,-3,0,6,7,8,9},-9));
    assert(testBinarySerch(std::vector<int>{1,2,3,4,5,6,7,8,9},0));
    assert(testBinarySerch(std::vector<int>{1,2,3,4,5,7,8,9},7));
    assert(testBinarySerch(std::vector<double>{1.4,2.4,3.3,4.2,5.1,6.1,7.5,8.43,9.2},6.8));

    return 0;
}