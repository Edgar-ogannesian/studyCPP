#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main()
{
    std::vector<std::pair<std::string, int>> vec;

    std::string word;
    int num;
    std::cin >> word;
    std::cin >> num;
    std::pair<std::string, int> p{word, num};
    vec.push_back(p);

    //----------------------------------------------------------
    std::pair<int, int> p0{4, 9};
    std::pair<int, int> p1;
    p1.first = 1;
    p1.second = 1;
    std::pair<int, int> p2(3, 3);
    //----------------------------------------------------------
    std::vector<std::pair<std::string, std::string>> vec1;
    std::map<std::string, std::vector<std::pair<std::string, std::string>>>
        family{{"name", vec1}};
    auto it = family.find("name");
    if (it != family.end())
    {
        it->second = vec1;
    }
}
