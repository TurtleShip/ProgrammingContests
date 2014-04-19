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

const int maxN = 10000001;
ll arr[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    
    ll res = 0ll;
    
    ll A,N;
    cin>>A>>N;
    
    for(int i=0; i < N; i++)
    {
        arr[i] = -1ll;
    }
    
    ll last = A+N-1ll;
    ll lim = sqrt(last);
    ll sq = 1ll;
    
    while(sq <= lim)
    {
        ll cur = sq*sq;
        
        ll idx = (cur * (A/cur) ) - A;
		if(idx < 0) idx += cur;
		
        while(idx < N)
        {
            arr[int(idx)] = cur;
            idx += cur;
        }
        sq++;
    }
    
    for(int i=0; i < N; i++)
        res += (A+i) / arr[i];
    
    cout<<res<<endl;
    return 0;
}
