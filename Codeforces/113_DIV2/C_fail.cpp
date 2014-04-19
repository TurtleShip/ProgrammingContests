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
    int INF = 1000000;
    ios_base::sync_with_stdio(false);
    
    int N,X;
    cin>>N>>X;
    
    vector<int> arr(N);
    
    REP(i,0,N)
        cin>>arr[i];
    
    sort(arr.begin(), arr.end());
    
    vector<int>::iterator low = lower_bound(arr.begin(), arr.end(), X);
    
    int pos = (low - arr.begin()) + 1;
    
    //X exists
    if(pos != (N+1) && (*low) == X)
    {
        int mid = (N+1)/2;
        if(mid == pos)
        {
            cout<<0<<endl;
            return 0;
        }
        
        if(pos < mid)
        {
            int ans = (N- 2*pos);
            if(ans%2 == 0) ans--;
            cout<<ans<<endl;
        }
        else
        {
            int ans = pos * 2 - N;
            if(ans%2 == 0)ans--;
            cout<<ans<<endl;
        }
        return 0;
    }

    //No X exists. We have to make one.
    int mid = (N+2)/2;
    
    
    if(pos < mid)
    {
        int ans = ((N+1) - 2 * pos);
        if(ans%2 == 0) ans--;
        cout<<(ans+1)<<endl;
    }
    else
    {
        int ans = pos*2 - N;
        if(pos == N+1) ans--;
        if(ans%2 == 0) ans--;
        cout<<(ans+1)<<endl;
    }
    
    return 0;
}