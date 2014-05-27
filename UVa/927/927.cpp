#include <iostream>
using namespace std;

typedef long long LL;

LL deg[50];

LL getNum(LL& n, int& maxDeg) {
	LL res = 0ll;
	LL multN = 1ll;
	for(int i=0; i <= maxDeg; i++) {
		res += deg[i] * multN;
		multN *= n;
	}
	return res;
}

int main() {
	int T, maxDeg, D, K;
	cin>>T;
	while(T--) {
		cin>>maxDeg;
		for(int i=0; i <= maxDeg; i++)
			cin>>deg[i];
		cin>>D>>K;

		int curIdx = 0;
		int n = 0;
		while(curIdx < K) {
			n++;
			curIdx += n*D;
			
		}
		LL N = LL(n);
		cout<<getNum(N, maxDeg)<<endl;
	}
	return 0;
}