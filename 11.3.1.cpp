#include<vector>
#include<map>
#include<string>
#include<utility>
using namespace std;
#include<algorithm>

int main() {

  map<string,string> family{{"name","fdfa"}};
  auto g=family["name"]=9;
   //---------------------------------------------------------
  map<string, string>::iterator map_it = family.begin();
    
  return 0;

}
