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
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;

string sen;




int main()
{
    int T;
    cin>>T;
    cin.ignore(250, '\n');
    
    int mod = 10000;
    string target = "welcome to code jam";
    int targetLen = target.size();

    for(int idx=1; idx <= T; idx++)
    {
        string sen;
        getline(cin, sen);
        
        int N = sen.size();
        int dp[N+1][targetLen];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i <= N; i++)
        {
            for(int j=0; j < targetLen; j++)
            {
                if(sen[i-1] == target[j])
                {
                    if(j==0) dp[i][j] = (dp[i-1][j] + 1) % mod;
                    else
                    {
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                        dp[i][j] %= mod;
                    }
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        int ans = dp[N][targetLen-1];
        string str;
        stringstream ss;
        ss<<ans;
        ss>>str;
        int S = str.size();
        if(S < 4)
        {
            if(S == 0) str = "0000";
            if(S == 1) str = "000" + str;
            if(S == 2) str = "00" + str;
            if(S == 3) str = "0" + str;
        }
        cout<<"Case #"<<idx<<": "<<str<<endl;
    }
    return 0;
}