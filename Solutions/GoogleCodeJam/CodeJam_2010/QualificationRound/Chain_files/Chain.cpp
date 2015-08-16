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

int main()
{
    int T;
    cin>>T;
    
    for(int idx = 1; idx <= T; idx++)
    {
        int N, K;
        cin>>N;
        cin>>K;
        
        int dp[N+1];
        dp[1] = 1;
        
        for(int i=2; i <= N; i++)
            dp[i] = dp[i-1] + (1<<(i-1));
        
        int cycle = (1<<N);
        
        string state ="ERROR";
        if(K < dp[N] || (K - dp[N]) % cycle != 0)
            state = "OFF";
        else state = "ON";
        
        cout<<"Case #"<<idx<<": "<<state<<endl;
    }
    return 0;
}