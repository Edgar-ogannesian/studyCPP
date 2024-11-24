#include<vector>
#include<map>
#include<utility>
#include <bits/stdc++.h>
using namespace std;
#include<algorithm>

int main() {

    multimap<string,string> authors{{"name","value"},{"name","antivalue"}};
    auto it=authors.find("name");
    if(it!=authors.end()){
        cout<<it->first;
        while(it!=authors.end()){
            authors.erase(it++);
        }
    }
    multimap<string,string> authors1{{"aname","value"},{"name","value"},{"name","antivalue"},{"m","e"}};
    for(auto begin=authors1.begin();begin!=authors1.end();begin++){
        std::cout << begin->first<<begin->second << std::endl;
    }
    
    return 0;

}
