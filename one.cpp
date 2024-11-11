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

void accumulateQest(){
    vector<int> vec{4,3,2,4,5,2,1,3,5};
    accumulate(vec.cbegin(),vec.cend(),0);

}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());

    auto end_unique=unique(words.begin(),words.end());
    words.erase(end_unique, words.end());
}

void fillQest(){
     vector<int> vec{4,3,2,4,5,2,1,3,5};
     fill_n(vec.begin(),vec.size(),0);
     cout<<vec[3];
}


int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}
