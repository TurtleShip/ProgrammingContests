#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
dp[i][j] =
maximum match between A[0..i) and B[0..j)
*/
int dp[1555][1555];
string A,B;
int az, bz;

int getMax() {
	for(int i=0; i  < az; i++) {
		for(int j=0; j < bz; j++) {
			if(A[i] == B[j]) dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i][j+1], dp[i+1][j]));
			else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}
	return dp[az][bz];
}

int main() {
	while(cin>>A>>B) {
		if(A.size() > B.size()) swap(A,B);
		// A <= B
		az = A.size();
		bz = B.size();

		int res = 0;

		for(int i=0; i <= az; i++) {
			res = max(res , getMax());
			char tmp = A[0];
			for(int j=0; j < az-1; j++)
				A[j] = A[j+1];
			A[az-1] = tmp;
		}

		reverse(A.begin(), A.end());
		for(int i=0; i <= az; i++) {
			res = max(res , getMax());
			char tmp = A[0];
			for(int j=0; j < az-1; j++)
				A[j] = A[j+1];
			A[az-1] = tmp;
		}

		cout<<res*2<<endl;
	}

	return 0;
}