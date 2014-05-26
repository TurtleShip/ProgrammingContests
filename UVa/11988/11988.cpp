#include <iostream>
#include <string>
#include <list>
using namespace std;

#define pb(x) push_back(x)

int main() {

  string str;
  while(getline(cin, str)) {
    list<char> res;

    auto itr = res.begin();

    for(int i=0; i < str.size(); i++) {
      if(str[i] == '[') {
        itr = res.begin();
      } else if(str[i] == ']') {
        itr = res.end();
      } else {
        res.insert(itr, str[i]);
      }
    }

    for(char ch : res)
      cout<<ch;
    cout<<endl;
  }

  return 0;
}
