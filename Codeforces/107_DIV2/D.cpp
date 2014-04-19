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
ll mod = 1000000007;

int main()
{
	ll n,m,k;
	
	cin>>n; cin>>m; cin>>k;
	
	if(k == 1 || k > n)
	{
		ll ans = 1ll;
		for(int i=0; i < n; i++)
		{
			ans = (ans * m) % mod;
		}
		cout<<(ans % mod)<<endl;
		return 0;
	}
	
    if(k == n)
	{
		ll ans = 1ll;
		ll cap = (k%2ll) + k/2ll;
		
		for(int i=0; i < cap; i++)
		{
			ans = (ans * m) % mod;
		}
		cout<<(ans % mod)<<endl;
		return 0;
	}
    
	if(k%2 == 1)
	{
		ll ans = (m * m) % mod;

		cout<<(ans % mod)<<endl;
		return 0;
	}

	cout<<m<<endl;

    return 0;
}