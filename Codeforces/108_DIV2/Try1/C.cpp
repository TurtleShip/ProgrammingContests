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

int mod = 1000000007;

int main()
{
    int N,M;
    cin>>N>>M;
    
    set<char> S[101];
    
    for(int i=0; i < N; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j < M; j++)
            S[j].insert(str[j]);
    }
    ll ans = 1ll;
    for(int j=0; j < M; j++)
        ans = (ans * S[j].size()) % mod;
    
    cout<<(ans%mod)<<endl;
    
    return 0;
}