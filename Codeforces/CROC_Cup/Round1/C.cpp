#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

#define UP 0
#define DOWN 1
#define LEFT 2 
#define RIGHT 3

typedef long long ll;

const int maxN = 510;

int arr[maxN][maxN];
int dp[maxN][maxN];
int save[2][maxN][maxN];

int rec(int,int,int);
int getSquare(int,int,int);

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin>>arr[i][j];
    
    memset(dp,0,sizeof(dp));
    memset(save, 0, sizeof(save));
    for(int i=1; i <= n; i++)
        for(int j=1; j <= m; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i-1][j-1];
 
    int flag = 0;
    int res = -1000 * 500 * 500;
    
    //get size 3
    for(int i=0; i <= n-3; i++)
        for(int j=0; j <= m-3; j++)
            res = max(res, save[flag][i][j] = getSquare(i,j,3) - arr[i+1][j+1]);
    
    flag = !flag;
    
    for(int k=5; k <= min(n,m); k+=2, flag = !flag)
        for(int i=0; i <= n-k; i++)
            for(int j=0; j <= m-k; j++)
            {
                save[flag][i][j] = getSquare(i,j,k) - save[!flag][i+1][j+1];
                res = max(res, save[flag][i][j]);
            }

    
    cout<<res<<endl;
    
    return 0;
}

int getSquare(int r, int c, int k)
{
    return dp[r+k][c+k] - dp[r][c+k] - dp[r+k][c] + dp[r][c] - arr[r+1][c];
}
                                      