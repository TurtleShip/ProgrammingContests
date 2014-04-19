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

int main()
{
    int N;
    int K;//number of calls that can be ignored
    cin>>N>>K;
    
    int T[N];
    int D[N];
    int maxTime = 86400;
    REP(i,0,N)
    {
        cin>>T[i];
        cin>>D[i];
    }
    
    //Handle special cases
    if(N == 0 || K == N)
    {
        cout<<maxTime<<endl;
        return 0;
    }

    int W[N];//W[i] = time when (i)th phone call conversation ends if all previous calls were answered
    W[0] = T[0] + D[0] - 1;
    for(int i=1; i < N; i++)
    {
        if(W[i-1] < T[i])
        {
            W[i] = T[i] + D[i] - 1;
        }
        else
            W[i] = W[i-1] + D[i];
    }

    if(K==0)
    {
        int ans = T[0] - 1;
        for(int i=1; i < N; i++)
        {   
            ans = max(ans, T[i] - W[i-1] - 1);
        }
        ans = max(ans, maxTime - W[N-1]);
        cout<<ans<<endl;
        return 0;
    }
    
    //0 < K < N
    int ans = T[K] - 1; //beginning ~ before work
    
    
    //in-between works
    for(int st = 0; (st + K) < N; st++)
    {
		if(st > 0)
        	ans = max(ans, T[st+K] - W[st-1] - 1);
        
        int work = (st > 0) ? W[st-1] : 0;
        
        for(int up = st+K; up < N; up++)
        {
            ans = max(ans , T[up] - work - 1);
         
            if(work < T[up])
            {
                work = T[up] + D[up] - 1;
            }
            else
            {
                work += D[up];
            }
        }
        ans = max(ans, maxTime - work);
    }
    
    //after work ~ end
    ans = max(ans, maxTime - W[N-K-1]);
    cout<<ans<<endl;
    
    return 0;
}