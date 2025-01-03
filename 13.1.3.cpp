//
// Created by donsimon on 12/30/24.
//
#include<iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0){}
    HasPtr(const HasPtr& ptr) {
        this->i=i;
        this->ps=new std::string(*ptr.ps);
    }
    HasPtr operator=(const HasPtr& ptr) {
        this->i=i;
        this->ps=new std::string(*ptr.ps);
        return *this;
    }
    ~HasPtr () {
        delete(this->ps);
    }
    std::string *ps;
private:
    int i;
};

struct X {
    X() {
        std::cout << "X()" << std::endl;
    }
    X(const X& other) {
        std::cout << "X(const X&)" << std::endl;
    }
    X& operator=(const X& other) {
        std::cout << "operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() {
        std::cout << "~X()" << std::endl;
    }
};

int main() {

    X x1;

    X x2(x1);

    x2 = x1;

    auto func_by_value=[](X x) {
        std::cout << "func_by_value" << std::endl;
    };
    func_by_value(x1);

    auto func_by_ref=[](X& x) {
        std::cout << "func_by_ref" << std::endl;
    };
    func_by_ref(x1);

    X* x3 = new X();

    delete x3; //
    return 0;
}