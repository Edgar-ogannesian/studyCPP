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
    std::string *ps;
private:
    int i;
};

int main() {
    HasPtr test0("34234");
    HasPtr test1(test0);
    test0.ps=new std::string("424");
    std::cout<<*test1.ps;
    return 0;
}