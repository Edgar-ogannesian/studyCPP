#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>

int main() {

  std::map<std::string,std::string> family{{"name","fdfa"}};
  auto g=family["name"]=9;
   //---------------------------------------------------------
  std::map<std::string, std::string>::iterator map_it = family.begin();
    
  return 0;

}
