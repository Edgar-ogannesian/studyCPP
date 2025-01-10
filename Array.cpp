//
// Created by donsimon on 1/10/25.
//
#include <algorithm>
#include <cstddef>
#include<iostream>
#include <utility>

template<typename T>
struct Array {
public:
    Array(T *array, size_t size): _array(array), _size(size) {
    };

    Array(const Array &arr) {
        this->_size = arr._size;
        this->_array = arr._array;
    }

    Array(Array &&arr) noexcept: _array(std::move(arr._array)), _size(std::move(arr._size)) {
        arr._array = nullptr;
        arr._size = 0;
    }

    ~Array() {
        delete[] _array;
    }

    Array &operator=(const Array &arr) {
        if (this != &arr) {
            delete[] _array;
            _size = arr._size;
            _array = new int[_size];
        }

        return *this;
    }

    Array &operator=(Array &&arr) {
        if (this != &arr) {
            delete[] _array;
            _array = std::move(arr._array);
            _size = std::move(arr._size);
            arr._array = nullptr;
            arr._size = 0;
        }
        return *this;
    }

private:
    T *_array;
    size_t _size;
};

int main() {
    int *Arr0 = new int[9];
    int *Arr1 = new int[2];
    Array<int> test0(Arr0, 9);
    Array<int> test1(Arr1, 2);
    test1 = std::move(test0);

    return 0;
}
