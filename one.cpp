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

void reversIter(){
    std::vector<int> vec {3,2,3,2,1,5,6,7};
	auto iterReverse=vec.crbegin();
	for(int i=0;i<vec.size();i++)
    {
	    cout<<*iterReverse;
	    iterReverse++;
	}
    auto iter=vec.cbegin();
	for(int i=0;i<vec.size();i++)
    {
	    cout<<*iter;
	    iter++;
	}
	auto iterForFind=find(vec.crbegin(),vec.crend(),0);
	cout<<*iterForFind;
}
void copyReverse(){
    vector<int> vec{1,2,2,2,4,2,1,5,6,7};
    vector<int> vec1(10);
    copy(vec.crbegin()+3,vec.crend()-3,vec1.begin());
}
int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}
