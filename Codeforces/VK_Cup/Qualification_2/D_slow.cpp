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

typedef long long ll;


string S;

//return true is S[i]..S[j] are palindrome
bool isPalin(int i, int j)
{
    while(i < j)
    {
        if(S[i] != S[j]) return false;
        i++;
        j--;
    }
    return true;
}
bool chk[2000][2000];
ll dp[2000][2000];  //dp[i][j] = number of palindromes in [i,j]

//test with 2000 character long string
int main()
{
    cin>>S;
    int N = S.size();
cout<<"N : "<<N<<endl;

    if(N == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    
  
	memset(chk, sizeof(chk), false);
    
    for(int i=0; i < N; i++)
        for(int j=i; j < N; j++)
            if(isPalin(i,j))
                chk[i][j] = true;
 
    for(int i=0; i < N; i++)
    {
       ll cur = 0;
        dp[i][i] = (chk[i][i]) ? 1 : 0;
        
        for(int j=i+1; j < N; j++)
        {
            dp[i][j] = dp[i][j-1];
            for(int k=i; k <= j; k++)
                dp[i][j] += (chk[k][j]) ? 1 : 0;
        }
    }

    ll ans = 0;
    for(int mid = 0; mid < N-1; mid++)
    {
        ll newVal = (mid > 0) ? ( dp[0][mid] - dp[0][mid-1] ) : dp[0][mid];
        ans += newVal * dp[mid+1][N-1];
      //  cumul += dp[0][mid];
    }
        

    cout<<ans<<endl;
    
    return 0;
}