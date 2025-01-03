//
// Created by donsimon on 1/3/25.
//
#include <iostream>
#include <vector>

unsigned int testWhile() {
    unsigned int start_time =  clock();
    unsigned long i=1;
    while(i<10000000) {
        i=i+1*2-4+3;
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    return search_time;
}

unsigned int testFor() {
    unsigned int start_time =  clock();

    for(unsigned long i=1;i<10000000;i=i+1*2-4+3) {}

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    return search_time;
}
unsigned int findMidValue(std::vector<unsigned int>& arr) {
    unsigned int result=0;
    for(auto i: arr) {
        result+=i;
    }
    return result/arr.size();
}
int main() {
    std::vector<unsigned int>resultWhile;
    std::vector<unsigned int>resultFor;

    for(int i=0;i<500;i++) {
        resultFor.push_back(testFor());
    }
    for(int i=0;i<500;i++) {
        resultWhile.push_back(testWhile());
    }

    unsigned int midValueFor=findMidValue(resultFor);
    unsigned int midValueWhile=findMidValue(resultWhile);

    std::cout<<"whille - "<<midValueWhile<<std::endl;
    std::cout<<"for - "<<midValueFor<<std::endl;

    return 0;
}
//whille - 39446
//for - 39482
//----------------------------------------------
//
//