#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define pb(x) push_back(x)

const int MOVE_TIME = 2;
const int LOADING_TIME = 1;
const int UNLOADING_TIME = 1;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int N, S, Q;
		cin>>N>>S>>Q;

		vector< queue<int> > stations;
		stack<int> cargo;
		int needToMove = 0;

		for(int i=0; i < N; i++) {
			int curQsize;
			cin>>curQsize;
			queue<int> curQ;
			for(int j=0; j < curQsize; j++) {
				int num;
				cin>>num;
				num--;
				curQ.push(num);
			}
			stations.pb(curQ);
			needToMove += curQsize;
		}

		int moved = 0;
		int curStation = 0;
		int totalTime = 0;

		while(moved < needToMove) {
			// attempt to unload cargo
			while(!cargo.empty()) {
				int container = cargo.top();
				if(container == curStation) {
					cargo.pop();
					totalTime += UNLOADING_TIME;
					moved++;
				} else if(stations[curStation].size() < Q) {
					cargo.pop();
					stations[curStation].push(container);
					totalTime += UNLOADING_TIME;
				} else {
					break;
				}
			}

			// attempt to load
			while(!stations[curStation].empty() && cargo.size() < S) {
				int container = stations[curStation].front();
				stations[curStation].pop();
				cargo.push(container);
				totalTime += LOADING_TIME;
			}

			if(moved < needToMove) {
				totalTime += MOVE_TIME;
				curStation = (curStation + 1) % N;
			}
		}

		cout<<totalTime<<endl;
	}

	return 0;
}