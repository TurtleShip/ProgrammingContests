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

int main()
{
    int N,M;
    cin>>N;
    cin>>M;
    
    int frd[N+1];
    memset(frd, 0, sizeof(frd));
    set<int> duo;
    set<int> bad;
    ll ans = 0ll;
    for(int i=0; i < M; i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        frd[a]++;
        frd[b]++;
        
        if(count(duo.begin(), duo.end(), a) == 0 && count(duo.begin(), duo.end(), b) )
        {
            duo.insert(a);
            duo.insert(b);
        }
        else
        {
            bad.insert(a);
            bad.insert(b);
        }
    }
    
    ans +=  duo.size() - bad.size();
    cout<<ans<<endl;
    ll noFriend = 0ll;
    ll allF = 0ll;
    for(int i=1; i <= N; i++)
    {
        if(frd[i] == 0) noFriend++;
        if(frd[i] == N-1) allF++;
    }
    
    ans += (noFriend * (noFriend-1))/2ll;
    ans += (allF * (allF-1))/2ll;
    
    cout<<ans<<endl;
    return 0;
}