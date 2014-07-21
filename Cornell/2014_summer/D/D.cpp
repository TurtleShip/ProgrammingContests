#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
	int N;
	cin>>N;

	vector<bool> removed(N, false);
	vector<LL> ori(N); // original array
	vector< pair<LL, int> > V(N);
	// Need to keep track of left and right element of each idx.
	// I tried to find them on the fly, and got TLE.
	vector<int> leftElm(N);
	vector<int> rightElm(N);

	for(int i=0; i < N; i++) {
		cin>>ori[i];
		V[i].first = ori[i];
		V[i].second = i;
		leftElm[i] = i-1;
		rightElm[i] = i+1;
	}

	sort(V.begin(), V.end());
	LL res = 0ll;
	for(int i=0; i < N-2; i++) {
		int idx = V[i].second;
		
		if(leftElm[idx] == -1 || rightElm[idx] == N) {
			// the extreme ends. They need to survive until the end.
			res += V[i].first;
			if(leftElm[idx] == -1) { // far left
				leftElm[rightElm[idx]] = -1;
			} else { // far right
				rightElm[leftElm[idx]] = N;
			}
		} else {
			res += min(ori[leftElm[idx]], ori[rightElm[idx]]);
			leftElm[rightElm[idx]] = leftElm[idx];
			rightElm[leftElm[idx]] = rightElm[idx];
		}
	}
	
	cout<<res<<endl;

	return 0;
}