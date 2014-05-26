#include <iostream>
using namespace std;

int main() {
  int N;
  int a, b;
  while(cin>>N && N != 0) {
    a = b = 0;
    bool isA = true;
    for(int i=0; i < 31; i++) {
      int cur = 1<<i;
      if((N & cur) != 0) {
        if(isA) a += cur;
        else b += cur;
        isA = !isA;
      }
    }
    cout<<a<<" "<<b<<endl;
  }

  return 0;
}
