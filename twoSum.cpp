#include <vector>
#include <iostream>
#include <unordered_set>
#include <array>
#include <map>
#include <cassert>
// Дан массив чисел и число - сумма двух элементов. Найти любые два элемента,
// сумма которых равна введенному числу

//1	2,1	8,2
//2	1,1	3,1
//3	2,1	4,1
//4	3,1	5,1
//5	4,1	6,1
//6	5,1	7,1
//7	6,1	8,1
//8	7,1	1,2

std::map<int,int> twoSum(std::vector<int> arr,int t)
{
    std::unordered_set<int> arrHash;
    std::map<int,int> result;

    for(int i=0;i<arr.size();i++)
    {
        arrHash.emplace(arr[i]);
    }

    for(int i=0;i<arr.size();i++)
    {
        int y=t-arr[i];
        if(arrHash.count(y))
        {
            result.emplace(std::pair<int,int>{arr[i],y});
        }
    }

    return result;
}

bool testTwoSum(std::vector<int> arr,int t) {
    std::map<int,int> expected;
    std::map<int,int> result=twoSum(arr,t);

    for(int i:arr)
    {
        for(int j:arr)
        {
            if((i+j)==t) {
                expected.emplace(std::pair<int,int>{i,j});
            }
        }
    }

    return expected==result;
}

int main() {
    assert(testTwoSum(std::vector<int>{},1));
    assert(testTwoSum(std::vector<int>{1},1));
    assert(testTwoSum(std::vector<int>{3,2,5,4,2,5,1,1,5,6},5));

    return 0;
}