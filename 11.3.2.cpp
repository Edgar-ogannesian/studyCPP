#include <bits/stdc++.h>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

int main()
{

    std::map<std::string, size_t> word_count; // пустая карта

    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                           "the", "but", "and", "or", "an", "a"};
    std::string word;
    while (std::cin >> word)
    {
        if (exclude.find(word) == exclude.end())
        {
            int val = ++word_count[word];
            word_count.erase(word);
            word_count.insert({word, val});
        }
    }
    //-----------------------------------------
    std::vector<std::string> vec;
    std::multimap<std::string, std::vector<std::string>> family{{"name", vec}};
    auto it = family.find("name");
    if (it != family.end())
    {
        it->second = vec;
    }
    return 0;

}
