//
// Created by donsimon on 1/12/25.
//
#include<iostream>
#include<vector>
#include<random>

template<typename T>
struct IHeap {
public:
    virtual void PopRoot() = 0;
    virtual void Append(T num) = 0;
    virtual T GetRoot() = 0;
    virtual void Heapify() = 0;
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
        std::pair<typename std::vector<T>::iterator, typename std::vector<T>::iterator> result = { firstChild, secondChild };

        return result;
    };

    auto ReplaceParentChild(typename std::vector<T>::iterator& parent, typename std::vector<T>::iterator& child) {
        std::iter_swap(parent, child);
        return parent;
    }

    auto GetMinChaild(std::pair<typename std::vector<T>::iterator, typename std::vector<T>::iterator>& pairChaild) {
        if(pairChaild.second != heap.end()) {
            if(*pairChaild.first < *pairChaild.second) {
                return pairChaild.first;
            }
            else {
                return pairChaild.second;
            }
        }
        return pairChaild.first;
    }

    void Heapify() {
        auto parent = heap.begin();

        auto pairChaild = FindPairChild(parent);
        auto minChaild = GetMinChaild(pairChaild);

        while (minChaild != heap.end() && (minChaild < parent)) {
            parent = ReplaceParentChild(minChaild, parent);
            pairChaild = FindPairChild(parent);
            minChaild = GetMinChaild(pairChaild);
        }
    }

public:
    T GetRoot() final {
        if(!heap.empty()) {
            return heap[0];
        }
    };

    bool IsEmpty() {
        return heap.empty();
    }

    void Show() const {
        for (T node : heap) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    void PopRoot() final {
        heap.begin() = heap.end() - 1;
        Heapify();
        heap.erase(heap.begin() + heap.size() - 1);
    }

    void Append(T num) final {
        heap.push_back(num);

        auto elemIterator = heap.end() - 1;
        auto parent = FindPerent(elemIterator);

        while (*parent > *elemIterator) {
            elemIterator = ReplaceParentChild(parent, elemIterator);
            parent = FindPerent(elemIterator);
        }
    };
};

bool testHeapMin() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for(int j = 0; j < 1445; j++) {
        std::uniform_real_distribution<> distrib(-99999, 9999);
        std::uniform_real_distribution<> boolDistrib(0, 1);
        HeapMin<int> heap;

        for(int i = 0; i < 1343; i++) {
            int num = distrib(gen);
            heap.Append(num);
        }

        for (int i = 0; i < 1235; i++) {
            heap.PopRoot();
        }

        for(int i = 0; i < 1431; i++) {
            int num = distrib(gen);
            heap.Append(num);
        }

        int min = heap.GetRoot();
        int result = heap.GetRoot();

        while (!heap.IsEmpty()) {
            if(heap.GetRoot() < min) {
                min = heap.GetRoot();
            }
            heap.PopRoot();
        }

        if(min != result){
            return 0;
        }
    }
    return 1;
}

int main() {
    std::cout << testHeapMin();
    return 0;
}