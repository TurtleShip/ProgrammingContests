#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
dp[i][j] =
maximum match between A[0..i) and B[0..j)
*/
int dp[3010][1555];
string A,B, AA;
int az, bz;

int getMax(int offset) {
	// initialize
	for(int i=offset; i < az+offset; i++)
		for(int j=0; j < bz; j++)
			dp[i][j] = 0;
	for(int i=offset; i  < az+offset; i++) {
		for(int j=0; j < bz; j++) {
			if(AA[i] == B[j]) dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i][j+1], dp[i+1][j]));
			else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}
	return dp[az+offset][bz];
}

int main() {
	while(cin>>A>>B) {
		if(A.size() > B.size()) swap(A,B);
		// A <= B
		az = A.size();
		bz = B.size();
		AA = A + A;

		int res = 0;

		for(int offset = 0; offset < az; offset++) {
			res = max(res , getMax(offset));
		}

		reverse(AA.begin(), AA.end());

		// AA = A + A;
		for(int offset = 0; offset < az; offset++) {
			res = max(res , getMax(offset));
		}
		
		cout<<res*2<<endl;
	}

	return 0;
}