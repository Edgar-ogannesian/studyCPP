//
// Created by donsimon on 1/12/25.
//
#include <atomic>

template<typename T>
class AtomicSharedPointer {
private:
    T *ptr;
    std::atomic<int> *refCount;

public:
    AtomicSharedPointer(T *p = nullptr)
        : ptr(p), refCount(new std::atomic<int>(1)) {
    }

    AtomicSharedPointer(const AtomicSharedPointer<T> &sp) {
        ptr = sp.ptr;
        refCount = sp.refCount;
        (*refCount)++;
    }

    AtomicSharedPointer &operator=(const AtomicSharedPointer<T> &sp) {
        if (this != &sp) {
            if (--(*refCount) == 0) {
                delete ptr;
                delete refCount;
            }

            ptr = sp.ptr;
            refCount = sp.refCount;
            (*refCount)++;
        }
        return *this;
    }

    ~AtomicSharedPointer() {
        if (--(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }
    }

    T *Get() const { return ptr; }

    int UseCount() const { return refCount->load(); }
};

int main() {
    return 0;
}