#include <iostream>
#include <set>
using namespace std;

int main() {
	int N, M, cur, res;
	while(cin>>N>>M && !(N == 0 && M == 0)) {
		res = 0;
		set<int> S;
		while(N--) {
			cin>>cur;
			S.insert(cur);
		}
		while(M--) {
			cin>>cur;
			if(S.count(cur) != 0) res++;
		}
		cout<<res<<endl;
	}
	return 0;
}