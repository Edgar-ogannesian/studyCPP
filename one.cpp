#include <iostream>
#include<algorithm>
#include <vector>
#include<list>
using namespace std;
void count() {
    vector<int> vec{4,3,2,4,5,2,1,3,5};
    list<int> lis{4,3,2,3,3,5,3,2,5,5,3,1,3};
    cout<<count(vec.cbegin(),vec.cend(),4);
    cout<<count(lis.cbegin(),lis.cend(),2);
}


int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}
