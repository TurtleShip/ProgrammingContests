#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int T, N, num;

	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V(N,0);
		for(int i=0; i < N; i++)
			cin>>V[i];
		sort(V.begin(), V.end());
		cout<<((V[N-1] - V[0]) * 2)<<endl;
	}
	return 0;
}