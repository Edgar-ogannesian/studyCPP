//
// Created by donsimon on 12/19/24.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main()
{
    using childrens_type = std::vector<std::string>;

    childrens_type vec;
    std::map<std::string, childrens_type> family{{"name", vec}};
    auto it = family.find("name");
    if (it != family.end())
    {
        it->second = vec;
    }
    //---------------------------------------------------------------------------------------------------------------------
    std::map<std::string, size_t> word_count; // пустая карта

    std::vector<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                              "the", "but", "and", "or", "an", "a"};
    std::string word;
    while (std::cin >> word)
    {
        const auto exclude_it = find(exclude.cbegin(), exclude.cend(), word);
        if (exclude_it == exclude.cend())
        {
            ++word_count[word];
        }
    }
}