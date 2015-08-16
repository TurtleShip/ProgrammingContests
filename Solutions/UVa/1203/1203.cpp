#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define mp(x,y) make_pair(x,y)

typedef long long LL;
typedef pair<LL, LL> pLL;
typedef pair<LL, pLL> ppLL;

int main() {
	string cmd;
	int K;
	LL queryID, period;

	// we want to order it so that queries with the smallest
	// query time comes to the top. If there are multiple ones,
	// we want to get the one with smaller id.
	priority_queue< ppLL, vector<ppLL>, greater<ppLL> > Q;

	while(cin>>cmd && cmd != "#") {
		cin>>queryID>>period;
		Q.push( mp(period, mp(queryID, period) ) );
	}
	cin>>K;
	while(K--) {
		auto cur = Q.top(); Q.pop();
		cout<<cur.second.first<<endl;
		cur.first += cur.second.second;
		Q.push(cur);
	}

	return 0;
}