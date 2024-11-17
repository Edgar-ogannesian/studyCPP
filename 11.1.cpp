#include<vector>
#include <сctype>
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
    while (cin >> word)

        if (exclude.find(tolower(word)) == exclude.end())
            ++word_count[tolower(word)];
    return 0;

}
