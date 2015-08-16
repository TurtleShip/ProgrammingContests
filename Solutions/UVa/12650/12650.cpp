#include <iostream>
using namespace std;

#define MAXN 10010

bool isAlive[MAXN];

int main() {
	int N, R, cur;
	while(cin>>N>>R) {
		for(int i=1; i <= N; i++)
			isAlive[i] = false;

		for(int i=0; i < R; i++) {
			cin>>cur;
			isAlive[cur] = true;
		}

		if(N == R) {
			cout<<"*"<<endl;
		} else {
			for(int i=1; i <= N; i++) {
				if(!isAlive[i])
					cout<<i<<" ";
			}
			cout<<endl;
		}

	}
	return 0;
}