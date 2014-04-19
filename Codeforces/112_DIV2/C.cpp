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
vector<ll> num0(1000010);
int main()
{
    ios_base::sync_with_stdio(false);

    int K;
    string S;
    cin>>K;
    cin>>S;
    
    //speical case
    if( K == 0)
    {
        ll ans = 0ll;
        ll zr = 0ll;
        for(int i=0; i < S.size(); i++)
        {
            if(S[i] == '0')
                zr++;
            else
            {
                ans += (zr * (zr + 1ll)) / 2ll;
                zr = 0ll;
            }
            
        }
        if(zr != 0)
            ans += (zr * (zr + 1ll)) / 2ll;
        cout<<ans<<endl;
        
        return 0;
    }
	fill(num0.begin(), num0.end(), 0ll);

    ll ans = 0ll;
    int ones = 0;
    for(int i=0; i < S.size(); i++)
    {
        if(S[i] == '1')
        {
            ones++;
        }
        else
        {
            num0[ones]++;
        }
            
    }
    
    for(int i=0; i + K  <= ones; i++)
    {
        ans+= num0[i+K] + 1ll;
        ans += num0[i] * (num0[i+K] + 1ll);
    }
    
    cout<<ans<<endl;
    
    return 0;
}