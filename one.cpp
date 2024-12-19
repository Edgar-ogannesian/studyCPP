#include <iostream>
#include<algorithm>
#include <vector>
#include<list>
#include<numeric>
void count() {
    std::vector<int> vec{4,3,2,4,5,2,1,3,5};
    std::list<int> lis{4,3,2,3,3,5,3,2,5,5,3,1,3};
    std::cout<<count(vec.cbegin(),vec.cend(),4);
    std::cout<<count(lis.cbegin(),lis.cend(),2);
}

void accumulateQest(){
    std::vector<int> vec{4,3,2,4,5,2,1,3,5};
    accumulate(vec.cbegin(),vec.cend(),0);

}

void elimDups(std::vector<std::string> &words) {
    sort(words.begin(), words.end());

    auto end_unique=unique(words.begin(),words.end());
    words.erase(end_unique, words.end());
}

void fillQest(){
     std::vector<int> vec{4,3,2,4,5,2,1,3,5};
     std::fill_n(vec.begin(),vec.size(),0);
     std::cout<<vec[3];
}

void reversIter(){
    std::vector<int> vec {3,2,3,2,1,5,6,7};
	auto iterReverse=vec.crbegin();
	for(int i=0;i<vec.size();i++)
    {
	    std::cout<<*iterReverse;
	    iterReverse++;
	}
    auto iter=vec.cbegin();
	for(int i=0;i<vec.size();i++)
    {
	    std::cout<<*iter;
	    iter++;
	}
	auto iterForFind=find(vec.crbegin(),vec.crend(),0);
	std::cout<<*iterForFind;
}
void copyReverse(){
    std::vector<int> vec{1,2,2,2,4,2,1,5,6,7};
    std::vector<int> vec1(10);
    copy(vec.crbegin()+3,vec.crend()-3,vec1.begin());
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
