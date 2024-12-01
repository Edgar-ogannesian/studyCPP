
#include<map>

#include<string>


int main() {
    std::map<std::string, int> family;

    family["iupojo"] = 1;


    int children = family["iupojo"];
    return 0;
}
