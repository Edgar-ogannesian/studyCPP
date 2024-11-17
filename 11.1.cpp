#include<vector>
#include<cctype>
#include<map>
#include<utility>
#include <bits/stdc++.h>
using namespace std;
#include<algorithm>

int main() {

    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or","An", "A","the", "but", "and", "or","an", "a"};
    string word;
    while (cin >> word)

        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    //------------------------------------------------------------------------------------------------------
    string word1;
    while (cin >> word1)
        transform(word1.cbegin(),word1.cend(),word1.begin(),[](char symbols) {return tolower(symbols);});
        if (exclude.find(word1) == exclude.end())
            ++word_count[word1];
    return 0;

}
