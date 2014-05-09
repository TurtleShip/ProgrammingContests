#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int T, N;
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V(N);
		for(int i=0; i < N; i++) {
			cin>>V[i];
		}
		map<int, int> M;
		int res = 0;
		int curRes = 0;
		int lastUnique = 0;
		for(int i=0; i < N; i++) {
			if(M.count(V[i]) == 0) {
				M[V[i]] = i;
				curRes++;
			} else {
				res = max(res, curRes);
				lastUnique = max(lastUnique, M[V[i]]);
				curRes = i - lastUnique;
				M[V[i]] = i;
			}
		}
		res = max(res, curRes);
		cout<<res<<endl;
		
	}
	return 0;
}