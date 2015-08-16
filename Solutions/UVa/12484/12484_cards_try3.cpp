#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxN = 1e4 + 10;
int arr[maxN];
ll dp[maxN][maxN];

int main() {

    int N;
    
    while(scanf("%d",&N) != EOF) {
        for(int i=0; i < N; i++)
            scanf(" %d", &arr[i]);
        
        /*
         dp[i][j] = best outcome that albert can get if
         there are cards from [i,j)
         */
        
        //get base case
        for(int i=0; i <= N; i++)
            dp[i][i] = 0ll;
        
        //what we want : dp[0][N]
        for(int i=N-1; i >= 0; i--) {
            for(int j=i+1; j <= N; j++) {
                int len = j-i;
                if(len % 2 == 0) dp[i][j] = max(arr[i] + dp[i+1][j], arr[j-1] + dp[i][j-1]);
                else dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
            }
        }
       printf("%lld\n", dp[0][N]);
    }
    return 0;
}