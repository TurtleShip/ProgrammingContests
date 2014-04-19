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

ll rec(vector<ll>);

//hair done = 14:27
int main()
{
    int N;
    cin>>N;
    
    vector<ll> V(N,0);
    REP(i,0,N)
        cin>>V[i];
    
	cout<<rec(V)<<endl;
    
    return 0;
}

ll rec(vector<ll> V)
{
    int N = V.size();
    if(N <= 2) return 0;
    if(N <= 4 || N%2 != 0)
    {
        ll sum = 0;
        REP(i,0,N) sum += V[i];
        return sum;
    }
    
    vector<ll> O;
    vector<ll> E;
    ll ans = 0;
    REP(i,0,N)
    {
        ans += V[i];
        if(i%2 == 0)
            E.push_back(V[i]);
        else
            O.push_back(V[i]);
    }
    
    ans = max(ans,rec(E));
    ans = max(ans,rec(O));
    return ans; 
}