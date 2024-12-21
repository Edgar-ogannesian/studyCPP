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

std::pair<int,int> twoSum(std::vector<int> arr,int t)
{
    std::unordered_set<int> arrHash;
    std::pair<int,int> result{};

    for(int i=0;i<arr.size();i++)
    {
        arrHash.emplace(arr[i]);
    }

    for(int i=0;i<arr.size();i++)
    {
        int y=t-arr[i];

        if(arrHash.count(y))
        {
            result=std::pair<int,int>{arr[i],y};
            break;
        }
    }

    return result;
}

bool testTwoSum(std::vector<int> arr,int t) {
    std::pair<int,int> twoNum=twoSum(arr,t);
    bool result=0;

    if((arr.size()<2) || (twoNum.first==0 && twoNum.second==0))
    {
            result=true;
    }

    for(int i:arr)
    {
        for(int j:arr)
        {
            if((i+j)==t)
            {
                if((i==twoNum.first && j==twoNum.second) || (i==twoNum.second && j==twoNum.first))
                {
                    result=true;
                }
            }
        }
    }

    return result;
}

int main() {
    assert(testTwoSum(std::vector<int>{},1));
    assert(testTwoSum(std::vector<int>{1},1));
    assert(testTwoSum(std::vector<int>{3,2,5,4,2,5,1,1,5,6},5));

    return 0;
}