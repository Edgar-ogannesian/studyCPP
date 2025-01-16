#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>

template<typename T>
struct IHeap {
public:
    virtual T Pop() =0;
    virtual void Push(T num) =0;
    virtual T GetRoot() =0;
    virtual void Heapify() =0;
};

template<typename T>
struct HeapMin : IHeap<T> {
public:
    T Pop() {
        int result = heap.front();
        if (heap.size() > 1) heap.front() = heap.back();
        heap.pop_back();
        Heapify();

        return result;
    }

    void Heapify() {
        int i = 0;
        while (true) {
            size_t largest = i;
            size_t jl = FindLeftChildIndex(i);
            size_t jr = FindRightChildIndex(i);

            if (jl < heap.size() && heap[largest] > heap[jl]) {
                largest = jl;
            }
            if (jr < heap.size() && heap[largest] > heap[jr]) {
                largest = jr;
            }
            if (largest == i) break;
            Swap(i, largest);

            i = largest;
        }
    }

    void Push(T num) {
        heap.push_back(num);

        int parentPosition = FindParentIndex(heap.size() - 1);
        int chaildPosition = heap.size() - 1;

        while (heap[parentPosition] > heap[chaildPosition]) {
            Swap(parentPosition, chaildPosition);

            chaildPosition = parentPosition;
            parentPosition = FindParentIndex(chaildPosition);
        }
    }

    void Show() const {
        for (T node: heap) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    auto begin() {
        return heap.begin();
    }

    auto end() {
        return heap.end();
    }

    bool Empty() const {
        return heap.empty();
    }
    T GetRoot() {
        return *heap.begin();
    }

private:
    std::vector<T> heap;

    void Swap(int paretnPosition, int chaildPosition) {
        T parent = heap[paretnPosition];
        heap[paretnPosition] = heap[chaildPosition];
        heap[chaildPosition] = parent;
    }

    int FindLeftChildIndex(int parentIndex) {
        return 2 * parentIndex + 1;
    }

    int FindRightChildIndex(int parentIndex) {
        return 2 * parentIndex + 2;
    }

    int FindParentIndex(int ChaildIndex) {
        return ChaildIndex / 2 - (ChaildIndex % 2 == 0) + (ChaildIndex == 0);
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

            heap.Push(val);
            assert(std::is_heap(std::begin(heap), std::end(heap), std::greater<>()) && "pop");

            expected_heap.push_back(val);
            std::push_heap(std::begin(expected_heap), std::end(expected_heap), std::greater<>());
            break;
        case POP:
            val = heap.Pop();
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
            Operation op = heap.Empty() ? PUSH : static_cast<Operation>(operation_distrib(gen));
            test(heap, expected_heap, op, val_distrib(gen));
        }
    }

    return 0;
}

