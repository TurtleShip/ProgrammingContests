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
#define F first;
#define S second;
#define MP make_pair;
#define PB push_back;

typedef long long ll;
typedef pair<int,int> PII;

//const ll maxN = 100000000000000001ll;
  const ll maxN = 10000000000000000ll;
ll ans;
ll N, M;
ll Fac[maxN];
ll mac[maxN];
void setFac();
void process();
int main()
{
	cout<<"Setting start"<<endl;
	setFac();
	cout<<"Yo"<<endl;
    cout<<"maxN : "<<maxN<<endl;
    int T;
    cin>>T;
    

    for(int i=1; i <=T; i++)
    {
        process();
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}

ll getFac(ll num)
{
    set<ll> count;
    ll cap = sqrt(num);
    for(ll i = 2; i <= cap; i++)
    {
        if(i%num == 0)
        {
            count.insert(i);
            count.insert(num/i);
        }
    }
    return count.size();
}

void setFac()
{
    memset(Fac, -1, sizeof(Fac));
    memset(mac, -1, sizeof(mac));
    for(ll i=2; i <= maxN; i++)
    {
        for(ll j=1; (i*j) <= maxN; j++)
        {
			Fac[i*j] += 1ll;
            if(mac[i*j] == -1) mac[i*j] = min(i,j);
        }
    }
}

void process()
{
    cin>>N>>M;
    ans = 0;
   // cout<<"N : "<<N<<" , facNum : "<<Fac[N]<<endl;
    for(int i = N-1; i >=M; i--)
        if(Fac[i] == Fac[N] && mac[i] >= M) ans++;

}
