#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int N;
	while(cin>>N) {
		bool isStack = true;
		bool isQueue = true;
		bool isPQ = true;
		stack<int> S;
		queue<int> Q;
		priority_queue<int> PQ;
		int cmd, num;
		for(int i=0; i < N; i++) {
			cin>>cmd>>num;
			if(cmd == 1) {
				S.push(num);
				Q.push(num);
				PQ.push(num);
			} else {
				// This is not good
				if(S.empty()) {
					isStack = isQueue = isPQ = false;
				} else {
					isStack &= num == S.top(); S.pop();
					isQueue &= num == Q.front(); Q.pop();
					isPQ    &= num == PQ.top(); PQ.pop();	
				}
			}
		}
		if(!isStack && !isQueue && !isPQ) cout<<"impossible"<<endl;
		else if(isStack && !isQueue && !isPQ) cout<<"stack"<<endl;
		else if(!isStack && isQueue && !isPQ) cout<<"queue"<<endl;
		else if(!isStack && !isQueue << isPQ) cout<<"priority queue"<<endl;
		else cout<<"not sure"<<endl;
	}

	return 0;
}