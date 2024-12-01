#include <vector>

#include <iostream>
#include <set>

#include <queue>

//1	2,1	8,2
//2	1,1	3,1
//3	2,1	4,1
//4	3,1	5,1
//5	4,1	6,1
//6	5,1	7,1
//7	6,1	8,1
//8	7,1	1,2

int findMedianHeap(std::vector<int> numVec)
{
    int result;
    std::priority_queue<int> minNum;

    for(int i:numVec)
    {
        minNum.push(i);
    }
    for(int i=0;i<numVec.size()/2+numVec.size()%2;i++)
    {
        result=minNum.top();
        minNum.pop();
    }
    return result;
}

int findMedianSet(std::vector<int> numVec)
{
    int result;
    std::set<int> minNum;

    for(int i:numVec)
    {
        minNum.emplace(i);
    }
    for(int i=0;i<numVec.size()/2+numVec.size()%2;i++)
    {
        result=*minNum.cend();
        minNum.erase(--minNum.end());
    }
    return result;
}

int main() {
    std::vector<int> test{3,7,2,1};
    std::cout<<findMedianSet(test);
    std::cout<<findMedianHeap(test);
    return 0;
}