//
// Created by donsimon on 12/19/24.
//
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main()
{

    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
                                     "the", "but", "and", "or", "an", "a"};
    std::string word;
    while (std::cin >> word)
    {
        if (exclude.find(word) == exclude.end())
        {
            ++word_count[word];
        }
    }
    //------------------------------------------------------------------------------------------------------
    std::string word1;
    while (std::cin >> word1)
    {
        std::transform(word1.cbegin(), word1.cend(), word1.begin(),
                       [](char symbols) { return tolower(symbols); });
    }
    if (exclude.find(word1) == exclude.end())
    {
        ++word_count[word1];
    }
    return 0;
}