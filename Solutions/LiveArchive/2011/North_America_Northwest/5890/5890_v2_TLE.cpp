#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
dp[i][j] =
maximum match between A[0..i) and B[0..j)
*/
int dp[1555][1555];
string A,B, AA;
int az, bz;

int getMax(int offset) {
	for(int i=1; i <= az; i++) {
		for(int j=1; j <= bz; j++) {
			if(AA[i-1+offset] == B[j-1]) dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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
		AA = A + A;

		int res = 0;

		for(int offset = 0; offset < az; offset++)
			res = max(res , getMax(offset));

		reverse(AA.begin(), AA.end());

		for(int offset = 0; offset < az; offset++)
			res = max(res , getMax(offset));
		
		cout<<res*2<<endl;
	}

	return 0;
}