#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int P, N, M, C;
	cin>>P;

	while(P--) {
		cin>>C>>N;
		
		vector<int> V;
		int e;
		vector<int> res;
		for(int i=1; i <= N; i++) {
			cin>>e;
			V.push_back(e);
			if(i % 2 == 1) {
				sort(V.begin(), V.end());
				res.push_back(V[i/2]);
			}
		}
		int sz = res.size();
		int idx = 0;
		cout<<C<<" "<<sz<<endl;

		while(idx < sz) {
			cout<<res[idx];
			for(int i=idx+1; i < min(idx+10, sz); i++)
				cout<<" "<<res[i];
			cout<<endl;
			idx += 10;
		}
		
	}


	return 0;
}