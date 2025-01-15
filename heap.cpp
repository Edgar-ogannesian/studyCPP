#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>

template<typename T>
struct IHeap {
public:
    virtual T pop() =0;
    virtual void push(T num) =0;
    virtual T GetRoot() =0;
    virtual void Heapify() =0;
};

template<typename T>
struct HeapMin : IHeap<T> {
private:
    std::vector<T> heap;

    typename std::vector<T>::iterator FindPerent(typename std::vector<T>::iterator it) {
        int position = std::distance(heap.begin(), it);
        return (heap.begin() + position / 2);
    };
    auto FindPairChild(typename std::vector<T>::iterator& parent) {
        int position = std::distance(heap.begin(), parent) + 1;

        auto firstChild = (position * 2 <= heap.size()) ? heap.begin() + position * 2 - 1 : heap.end();
        auto secondChild = (position * 2 < heap.size()) ? heap.begin() + position * 2 : heap.end();
        std::pair<typename std::vector<T>::iterator,typename std::vector<T>::iterator> result={firstChild, secondChild};

        return result;
    };

    auto ReplaceParentChild(typename std::vector<T>::iterator& parent,typename std::vector<T>::iterator& child) {
        std::iter_swap(parent, child);
        return parent;
    }
    auto GetMinChaild(std::pair<typename std::vector<T>::iterator,typename std::vector<T>::iterator>& pairChaild) {
        if(pairChaild.second != heap.end()) {
            if(*pairChaild.first < *pairChaild.second) {return pairChaild.first;}
            else{return pairChaild.second;}
        }
        return pairChaild.first;
    }
    void Heapify() {
        auto parent=heap.begin();

        auto pairChaild=FindPairChild(parent);
        auto minChaild=GetMinChaild(pairChaild);

        while (minChaild != heap.end() && (minChaild < parent)) {
            parent=ReplaceParentChild(minChaild,parent);
            pairChaild=FindPairChild(parent);
            minChaild=GetMinChaild(pairChaild);
        }
    }


public:
    T GetRoot() final {
        if(!heap.empty()){return heap[0];}
    };
    bool IsEmpty() {
        return heap.empty();
    }
    void Show() const {
        for (T node : heap) {
            std::cout<<node<<" ";
        }
        std::cout<<std::endl;
    }

    T pop() final {
        T result = heap.front();
        heap.begin()=heap.end()-1;
        Heapify();
        heap.erase(heap.begin()+heap.size()-1);
        return result;
    }
    void push(T num) final {
        heap.push_back(num);

        auto elemIterator=heap.end()-1;
        auto parent = FindPerent(elemIterator);


        while (*parent > *elemIterator) {
            elemIterator = ReplaceParentChild(parent, elemIterator);
            parent = FindPerent(elemIterator);
        }
    };

    auto begin() {
        return heap.begin();
    }

    auto end() {
        return heap.end();
    }

    bool empty() const {
        return heap.empty();
    }
};

enum Operation {
    PUSH,
    POP
};

void test(HeapMin<int>& heap, std::vector<int>& expected_heap, Operation op, int val = 0)
{
    int expected_val;
    switch (op) {
        case PUSH:
            std::cout << "push " << val << std::endl;

            heap.push(val);
            assert(std::is_heap(std::begin(heap), std::end(heap), std::greater<>()) && "pop");

            expected_heap.push_back(val);
            std::push_heap(std::begin(expected_heap), std::end(expected_heap), std::greater<>());
            break;
        case POP:
            val = heap.pop();
            assert(std::is_heap(std::begin(heap), std::end(heap), std::greater<>()) && "pop");

            expected_val = expected_heap.front();
            std::pop_heap(std::begin(expected_heap), std::end(expected_heap), std::greater<>());
            expected_heap.pop_back();

            std::cout << "pop actual " << val << " vs expected " << expected_val << std::endl;
            assert(val == expected_val && "pop");
            break;
    }
}

int main() {
    {
        // Место для отладки на статичном наборе тестов

        HeapMin<int> heap;
        std::vector<int> expected_heap;

        test(heap, expected_heap, PUSH, 30);
        test(heap, expected_heap, PUSH, 35);
        test(heap, expected_heap, POP);
        test(heap, expected_heap, POP);
    }

    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> val_distrib(0, 100);
        std::uniform_int_distribution<> operation_distrib(0, 1);

        HeapMin<int> heap;
        std::vector<int> expected_heap;
        for (size_t i = 0; i < 1'000'000; ++i) {
            Operation op = heap.empty() ? PUSH : static_cast<Operation>(operation_distrib(gen));
            test(heap, expected_heap, op, val_distrib(gen));
        }
    }

    return 0;
}