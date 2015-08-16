#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

ll common(ll a, ll b, ll c, ll d){
    ll high = min(b,d);
    ll low = max(a,c);
    if(low > high) return 0;
    return high - low + 1;
}

vector <pair <ll, ll> > func(ll a, ll b, ll two){
    if(a%two == 0) a++;
    if(b%two == 0) b--;
    
    vector <pair <ll, ll> > v;
    if(a > b) return v;
    
    if(a/two == b/two){
        v.push_back(make_pair(a,b));
    } else {
        v.push_back(make_pair(a,(a/two)*two+two-1));
        v.push_back(make_pair((b/two)*two+1,b));
        if(a/two + 1 < b/two) v.push_back(make_pair(1ll,two-1));
    }
    
    int i;
    REP(i,v.size()){
        v[i].first %= two;
        v[i].second %= two;
    }
    
    return v;
}

ll fast(ll a, ll b, ll c, ll d){
    ll ans = 0;
    ll two = 1;
    
    int i,j,k;
    
    REP(i,30){
        two *= 2;
        vector <pair <ll, ll> > v1 = func(a,b,two);
        vector <pair <ll, ll> > v2 = func(c,d,two);
        
        REP(j,v1.size()) REP(k,v2.size()){
            ll tmp = common(v1[j].first,v1[j].second,v2[k].first,v2[k].second);
            ans = max(ans,tmp);
        }
    }
    
    return ans;
}

int main(void){
    ll a,b,c,d;
    
    cin >> a >> b >> c >> d;
    cout << fast(a,b,c,d) << endl;
    
    return 0;
}