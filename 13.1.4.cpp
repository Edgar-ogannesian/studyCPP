//
// Created by donsimon on 12/30/24.
//
#include<vector>
#include<iostream>
#include<unordered_set>

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

HasPtr f(HasPtr hp)

{
    HasPtr ret = hp;
    return ret;
}

int main() {
    return 0;
}