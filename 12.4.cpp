#include <vector>
#include <iostream>
#include <unordered_set>


//1	2,1	8,2
//2	1,1	3,1
//3	2,1	4,1
//4	3,1	5,1
//5	4,1	6,1
//6	5,1	7,1
//7	6,1	8,1
//8	7,1	1,2

std::vector<int> twoSum(int arr[],int t)
{
    std::unordered_set<int> arrHash;
    std::vector<int> result;
    for(int i=0;i<sizeof(arr);i++)
    {
        arrHash.emplace(arr[i]);
    }

    for(int i=0;i<sizeof(arr);i++)
    {
        int y=t-arr[i];

        if(arrHash.count(y))
        {
            result.emplace_back(arr[i]);
        }
    }

    return result;
}

int main() {
    int arr[]{4,1,2,3,7,8,9,10,11,14};

    std::vector<int> result=twoSum(arr,5);
    for(int i:result)
    {
        std::cout<<i<<std::endl;
    }

    return 0;
}