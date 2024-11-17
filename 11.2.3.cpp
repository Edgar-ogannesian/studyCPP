#include<vector>
#include<map>
#include<utility>
#include <bits/stdc++.h>
#include<utility>
using namespace std;
#include<algorithm>

int main() {

    vector<pair<string,int>> vec;
    
    string word;
    int num;
    cin>>word;
    cin>>num;
    pair<string,int> p{word,num};
    vec.push_back(p);

    //----------------------------------------------------------
    pair<int,int> p0{4,9};
    pair<int,int>p1;
    p1.first=1;
    p1.second=1;
    pair<int,int>p2(3,3);
    //----------------------------------------------------------
    vector<pair<string,string>> vec1;
    map<string,vector<pair<string,string>>> family{{"name",vec1}};
    auto it = family.find("name");
    if (it != family.end()) {
        it->second=vec1;
    }
}
