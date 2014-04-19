#include <iostream>
#include <algorithm>
using namespace std;

int F[1010];
int D[1010];

const int maxGlobalF = 20*1000+10;
const int maxL = 300000;
int dp[1010][maxGlobalF];

int main() {
	int N,K,L;
	dp[0][0] = 0;
	for(int j=1; j <= maxGlobalF; j++)
			dp[0][j] = maxL + 1;

	while(cin>>N>>K>>L && (N+K+L) != 0) {
		
		for(int i=0; i < N; i++)
			cin>>F[i]>>D[i];
		int res = 0;
		int maxF = 0;
		for(int i=0; i < N; i++) maxF += F[i];
		
		for(int i=1; i <= N; i++)
			for(int j=0; j <= maxF; j++)
				dp[i][j] = maxL+1;

		for(int i=1; i <= N; i++) {
			for(int j=0; j <= maxF; j++) {
				// keep eyes open
				if(j >= F[i-1]) dp[i][j] = min(dp[i][j], dp[i-1][j-F[i-1]] + D[i-1]);
				
				// keep eyes closed
				if(dp[i-1][j] <= L) dp[i][j] = min(dp[i][j], max(dp[i-1][j] - K, 0));
			}
		}
		
		for(int i=1; i <= maxF; i++)
			if(dp[N][i] <= L) res = i;

		cout<<res<<endl;
	}
	return 0;
}