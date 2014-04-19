#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxN = 1e4 + 10;
int arr[maxN];
ll dp[maxN][maxN];
/*
 dp[i][j] = best outcome that albert can get if
 there are cards from [i,j)
 */

ll solve(int s, int t) {
    if(dp[s][t] != -1ll) return dp[s][t];
   // printf("solve(%d , %d)\n", s, t);
    ll& res = dp[s][t];
    res = 0ll;
    
    if(s == t) return res;
    
    int len = t - s;
    if(len % 2 == 0) res = max(arr[s] + solve(s+1,t), arr[t-1] + solve(s,t-1));
    else res = min(solve(s+1,t), solve(s,t-1));
    
    return res;
}

int main() {
    
    int N;
    
    while(scanf("%d",&N) != EOF) {
        for(int i=0; i < N; i++)
            scanf("%d", &arr[i]);
        
        for(int i=0; i < N; i++)
            for(int j=i; j <= N; j++)
                dp[i][j] = -1ll;
       
        solve(0,N);
        printf("%lld\n", dp[0][N]);
    }
     
    return 0;
}