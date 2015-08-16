#include <vector>
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;

	for(int cid=1; cid<=T; cid++) {
		int res = 0;
		int N;
		cin>>N;
		vector<int> V(N);
		for(int i=0; i < N; i++) {
			cin>>V[i];
		}

		int l = 0;
		int r = N-1;
		while(l < r) {
			int minElm = V[l];
			int minIdx = l;
			for(int i=l+1; i <= r; i++) {
				if(V[i] < minElm) {
					minElm = V[i];
					minIdx = i;
				}
			}
			if((minIdx-l) < (r-minIdx)) {
				// move it to left
				res += minIdx - l;
				for(int i=minIdx; i > l; i--) {
					V[i] = V[i-1];
				}
				V[l] = minElm;
				l++;
			} else {
				// move it to right
				res += r - minIdx;
				for(int i=minIdx; i < r; i++) {
					V[i] = V[i+1];
				}
				V[r] = minElm;
				r--;
			}
		}

		printf("Case #%d: %d\n", cid, res);
	}

	return 0;
}
