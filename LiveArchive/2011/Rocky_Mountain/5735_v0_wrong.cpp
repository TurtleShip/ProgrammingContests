#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// typedef struct Stock {
// 	int val;
// 	int day;
// 	Stock() {}
// 	Stock(int v, int d) {
// 		val = v;
// 		day = d;
// 	}
// } Stock;
const int MAXN = 1000010;

pair<int,int> stk[MAXN];

int main() { 
	int N,k1,k2;
	int cid = 1;
	while(cin>>N>>k1>>k2 && (N+k1+k2) != 0) {
		for(int i=0; i < N; i++) {
			stk[i].second = i+1;
			cin>>stk[i].first;
		}
		sort(stk, stk +  N);
		cout<<"Case "<<cid++<<endl;
		vector<int> res1;
		vector<int> res2;

		for(int i=0; i < k1; i++)
			res1.push_back(stk[i].second);
		sort(res1.begin(), res1.end());
		if(res1.size() > 0) cout<<res1[0];
		for(int i=1; i < res1.size(); i++)
			cout<<" "<<res1[i];
		cout<<endl;

		for(int i=0; i < k2; i++)
			res2.push_back(stk[N-1-i].second);
		sort(res2.begin(), res2.end());
		int sz = res2.size();
		if(sz > 0) cout<<res2[sz-1];
		for(int i=sz-2; i >= 0; i--)
			cout<<" "<<res2[i];
		cout<<endl;

	}
	return 0;
}