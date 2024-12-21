//
// Created by donsimon on 12/19/24.
//
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

struct IHeap
{
public:
    virtual void Pop(std::vector<int>::iterator parent)=0;
    virtual void Pop(int num)=0;
    virtual void Append(int num)=0;
    virtual int GetRoot()=0;
};

struct HeapMin : IHeap
{
private:
    std::vector<int> heap;
    std::vector<std::vector<int>::iterator> holes;

    std::vector<int>::iterator FindPerent(std::vector<int>::iterator it)
    {
        int position=std::distance(heap.begin(),it);

        return (heap.begin() + position/2);
    };
    std::pair<std::vector<int>::iterator,std::vector<int>::iterator> FindChild(std::vector<int>::iterator parent) {
        int position=std::distance(heap.begin(),parent)+1;

        std::vector<int>::iterator firstChild = (position*2 <= heap.size()) ? heap.begin() + position*2 - 1 : parent;
        std::vector<int>::iterator secondChild = (position*2 < heap.size()) ? heap.begin() + position*2 : parent;

        return {firstChild,secondChild};
    };
    std::vector<int>::iterator ReplaceParentChild(std::vector<int>::iterator parent,std::vector<int>::iterator child)
    {
        std::iter_swap(parent,child);
        return parent;
    }

public:
    int GetRoot() final
    {
        return heap[0];
    };
    void Show() const {
        for(int i:heap) std::cout<<i<<"  ";
    }
    std::vector<int>::iterator GetIterator(int num)
    {
        std::vector<int>::iterator it = heap.begin();

        while (it!=heap.end())
        {
            if(*it==num)
            {
                return it;
            }else
            {
                it++;
            }
        }

        return it;
    }

    void Pop(std::vector<int>::iterator parent) final
    {
        std::pair<std::vector<int>::iterator,std::vector<int>::iterator> child=FindChild(parent);
        std::vector<int>::iterator minChild = (*child.second<*child.first && child.second!=parent) ? child.second : child.first;
        while (minChild!=parent)
        {
            parent=ReplaceParentChild(minChild,parent);
            child=FindChild(parent);
            minChild = (*child.second<*child.first && child.second!=parent) ? child.second : child.first;        }

        holes.push_back(parent);
        *parent=NULL;
    }
    void Pop(int num) final
    {
        std::vector<int>::iterator parent=GetIterator(num);

        if(parent==heap.end())
        {
            return;
        };

        std::pair<std::vector<int>::iterator,std::vector<int>::iterator> child=FindChild(parent);
        std::vector<int>::iterator minChild = (*child.second<*child.first && child.second!=parent) ? child.second : child.first;

        while (minChild!=parent)
        {
            parent=ReplaceParentChild(minChild,parent);
            child=FindChild(parent);
            minChild = (*child.second<*child.first && child.second!=parent) ? child.second : child.first;        }

        holes.push_back(parent);
        *parent=NULL;
    }
    void Append(int num) final
    {
        std::vector<int>::iterator elemIterator;

        if(holes.size()) {
            **(holes.begin())=num;
            elemIterator=*holes.begin();
            holes.erase(holes.begin());
        }else
        {
            heap.push_back(num);
            elemIterator=heap.end()-1;
        }

        std::vector<int>::iterator parent=FindPerent(elemIterator);
        std::pair<std::vector<int>::iterator,std::vector<int>::iterator> child = FindChild(elemIterator);
        std::vector<int>::iterator minChild = (*child.first<=*child.second) ? child.first : child.second;

        while(*elemIterator>*minChild)
        {
            elemIterator = ReplaceParentChild(minChild,elemIterator);
            child = FindChild(elemIterator);
            minChild = (*child.first<=*child.second) ? child.first : child.second;
        }

        while(*parent>*elemIterator)
        {
            elemIterator = ReplaceParentChild(parent,elemIterator);
            parent = FindPerent(elemIterator);
        }
    };

    };
int main()
{
    return 0;
}