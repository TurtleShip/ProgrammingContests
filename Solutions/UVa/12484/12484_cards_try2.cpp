#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxN = 1e4 + 10;
int arr[maxN];
ll dp[maxN][maxN];
/*
 dp[pos][len] = best outcome that albert can get if
 there are cards at [pos, pos+len)
 */

ll solve(int pos, int len) {
    if(dp[pos][len] != -1) return dp[pos][len];
    ll& res = dp[pos][len];
    res = 0ll;
    
    if(len == 0) return res;
    
    if(len % 2 == 0) res = max(arr[pos] + solve(pos+1,len-1), arr[pos+len-1] + solve(pos,len-1));
    else res = min(solve(pos+1,len-1), solve(pos,len-1));
    
    return res;
}

int main() {
    
    int N;
    while(scanf("%d",&N) != EOF) {
        for(int i=0; i < N; i++)
            scanf("%d", &arr[i]);
        
        for(int i=0; i < N; i++)
            for(int j=0; j <= N-i; j++)
                dp[i][j] = -1ll;
       
        solve(0,N);
        printf("%lld\n", dp[0][N]);
    }
    return 0;
}