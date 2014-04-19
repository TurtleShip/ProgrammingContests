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

ll Al,Ar,Bl,Br;
ll common(ll,ll,ll,ll);
ll tryAll();
vector< pair<ll,ll> > getPos(ll,ll,ll);

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin>>Al>>Ar>>Bl>>Br;
    
    cout<<tryAll()<<endl;

    return 0;
}

ll common(ll l1, ll r1, ll l2, ll r2)
{
    return max(0ll, min(r1,r2) - max(l1,l2) + 1);
}

ll tryAll()
{
    ll two = 1ll;
    ll ans = 0;
    for(int i=0; i < 30; i++)
    {
        two *= 2ll;
        
        vector< pair<ll,ll> > A = getPos(Al, Ar, two);
        vector< pair<ll,ll> > B = getPos(Bl, Br, two);


        for(int i=0; i < A.size(); i++)
            for(int j=0; j < B.size(); j++)
                ans = max(ans, common(A[i].first, A[i].second, B[j].first, B[j].second));

    }
    return ans;
}

vector< pair<ll,ll> > getPos(ll l, ll r, ll two)
{
    vector< pair<ll,ll> > res;
    if(l%two == 0) l++;
    if(r%two == 0) r--;
    if(l > r) return res;
    
    if( l/two == r/two )
    {
        res.push_back( make_pair(l%two,r%two) );
    }
    else
    {
        if( (l/two) + 1 == (r/two) )
        {
            res.push_back( make_pair(l%two, two - 1ll) );
            res.push_back( make_pair(1ll, r%two) );
        }
        else
        {
            res.push_back( make_pair(1ll, two - 1ll) );
        }
    }
    
    return res;
}