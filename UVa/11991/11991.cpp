#include <vector>
#include <iostream>
using namespace std;

#define pb(x) push_back(x)

const int maxElm = 1000000;
vector<int> res[maxElm + 10]; // I hate to declare global variable.. but need to meet memory limit

int main() {
	int N, M;
	
	while(cin>>N>>M) {
		
		for(int i=1; i <= maxElm; i++)
			res[i].clear();

		int num, ord;
		for(int idx=1; idx <= N; idx++) {
			cin>>num;
			res[num].pb(idx);
		}
		
		while(M--) {
			cin>>ord>>num;
			ord--;
			if(ord < res[num].size()) cout<<res[num][ord]<<endl;
			else cout<<0<<endl;
		}
	}

	return 0;
}