#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;

	while(T--) {
		int L, M;
		cin>>L>>M;
		L *= 100; // convert cm to meter.

		vector< queue<int> > cars(2);
		int sz;
		string str;
		for(int i=0; i < M; i++) {
			cin>>sz>>str;
			if(str == "left") cars[0].push(sz);
			else cars[1].push(sz);
		}

		int res = 0;
		int side = 0;

		while(!cars[0].empty() || !cars[1].empty()) {
			int freeLen = L;
			while(!cars[side].empty() && freeLen >= cars[side].front()) {
				freeLen -= cars[side].front();
				cars[side].pop();
			}
			side = (side + 1) % 2;
			res++;
		}

		cout<<res<<endl;
	}
	
	return 0;
}