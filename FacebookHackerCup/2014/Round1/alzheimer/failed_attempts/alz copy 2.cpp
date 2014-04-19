#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }

bool isCoPrime(int x, int y) {

	if(x == 0 && y == 0) return false;
	if(x == 1 || y == 1) return true;
	if(x == 0 || y == 0) return false;
	if(x == y) return false;
	return gcd(x,y) == 1;
}

int main() {
	int T,N,K,A;

	cin>>T;
	for(int cid=1; cid <= T; cid++) {
		cin>>N>>K;
		vector<int> V;
		for(int i=0; i < N; i++) {
			cin>>A;
			V.push_back(A);
		}

		int phase0 = 0, phase1 = 0;

		for(int i=0; i < N; i++) {
			if(V[i] % K != 0) {
				int need = K - V[i] % K;
				V[i] += need;
				phase0 += need;

			}
		}
		sort(V.begin(), V.end());

		for(int i=0; i < N; i++)
			V[i] /= K;

		// check boundary conditions
		int numZeros = 0;
		int numOverOne = 0;
		for(int i=0; i < N; i++) {
			numZeros += (V[i] == 0) ? 1 : 0;
			numOverOne += (V[i] > 1) ? 1 : 0;
		}

		if(numZeros > 0 && numOverOne > 0) {
			for(int i=0; i < N; i++) {
				if(V[i] == 0) {
					V[i]++;
					phase1++;
				} else {
					break;
				}
			}
		}


		for(int i=1; i < N; i++) {
			while(true) {
				bool isGood = true;
				for(int j=0; j < i; j++) {
					if(!isCoPrime(V[j],V[i])) {
						isGood = false;
						break;
					} 
				}
				if(isGood) break;
				V[i]++;
				phase1++;
			}
		}
		cout<<"Case #"<<cid<<": "<<(phase0 + K*phase1)<<endl;

	}

}