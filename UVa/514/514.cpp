#include <iostream>
#include <stack>
using namespace std;

int order[1100];

int main() {
  int N;
  int cur;
  while(cin>>N && N != 0) {
    bool isDone = false;

    while(!isDone) {

      for(int i=0; !isDone && i < N; i++) {
        cin>>cur;
        if(cur == 0) {
          isDone = true;
        } else {
          order[i] = cur;
        }
      }

      if(isDone) break;

      stack<int> station;
      int pos = 0;
      for(int i=1; i <= N; i++) {
        station.push(i);
        bool canSend = true;
        while(canSend && !station.empty() && pos < N) {
          if(station.top() == order[pos]) {
            station.pop();
            pos++;
          } else {
            canSend = false;
          }
        }
      }

      if(pos == N) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
    cout<<endl;
  }
  return 0;
}
