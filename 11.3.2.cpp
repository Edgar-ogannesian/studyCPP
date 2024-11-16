#include<vector>
#include<map>
#include<utility>
#include <bits/stdc++.h>
using namespace std;
#include<algorithm>

int main() {

    map<string, size_t> word_count; // пустая карта

    set<string> exclude = {"The", "But", "And", "Or",
"An", "A",
"the", "but", "and", "or",
"an", "a"};
    string word;
    while (cin >> word){
// подсчитать только не исключенные слова
        if (exclude.find(word) == exclude.end()){
            int val=++word_count[word];
            word_count.erase(word);
            word_count.insert({word,val});
        }
    }
    return 0;

}
