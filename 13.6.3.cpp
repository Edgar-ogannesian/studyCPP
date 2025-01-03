//
// Created by donsimon on 1/3/25.
//
#include<vector>
#include<iostream>
#include<algorithm>

class Foo {
public:
    Foo sorted() &&;

    Foo sorted() const &;

    private:
    std::vector<int> data;
};


Foo Foo::sorted() && {
    std::sort(data.begin(), data.end());
    std::cout<<"r-value";

    return *this;
}
Foo Foo::sorted() const & {
    Foo ret(*this);
    sort(ret.data.begin(),ret.data.end());
    std::cout<<"l-value";

    return ret;
    }
int main() {
    return 0;
}