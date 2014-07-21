#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool canProduce(const int& st, const int& N, const int& K, const string& letters) {
	bool isPossible = true;
	for(int i=0; isPossible && i < N; i++) {
		int matchIdx = st + i + N;
		if(matchIdx >= letters.size()) {
			isPossible &= (matchIdx) < (letters.size() + K);
		} else if(st >= letters.size()) {
			isPossible &= st < (letters.size() + K);
		} else {
			isPossible &= letters[st + i] == letters[matchIdx];
		}
	}
	return isPossible;
}

int main() {
	string letters;
	int K, res = 0;

	cin>>letters>>K;

	// brute-force.
	for(int N=1; N <= letters.size()+K; N++) { // at most 400
		bool found = false;
		for(int st = 0; !found && st < letters.size() + K - N; st++) { // at most 400
			found |= canProduce(st, N, K, letters); // at most 400
		}
		if(found && res < N) res = N;
	}
	cout<<res*2<<endl;

	return 0;
}