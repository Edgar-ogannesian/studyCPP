#include<vector>
#include<map>
#include<utility>
#include <bits/stdc++.h>

#include<algorithm>

int main() {

    std::multimap<std::string,std::string> authors{{"name","value"},{"name","antivalue"}};
    auto it=authors.find("name");
    if(it!=authors.end()){
        std::cout<<it->first;
        while(it!=authors.end()){
            authors.erase(it++);
        }
    }
    std::multimap<std::string,std::string> authors1{{"aname","value"},{"name","value"},{"name","antivalue"},{"m","e"}};
    for(auto begin=authors1.begin();begin!=authors1.end();begin++){
        std::cout << begin->first<<begin->second << std::endl;
    }
    
    return 0;

}
