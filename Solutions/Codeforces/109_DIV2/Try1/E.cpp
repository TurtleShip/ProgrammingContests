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

const int maxN = 1000001;
ll poly[maxN], notF[maxN], F[maxN];
int main()
{
	int N,M;
	
    cin>>N>>M;
    
    poly[0] = 1ll;
    for(int i=1; i <= N; i++)
        poly[i] = poly[i-1] * 3ll;
    
    memset(notF, 0ll, sizeof(notF));
    memset(F, 0ll, sizeof(F));
    
    for(int i=0; i < M; i++)
    {
        int x,y;
        cin>>x>>y;
        
        notF[x] += poly[y];
        notF[y] += poly[x];
    }
    
    ll ans = 0;
    for(int i=1; i <= N; i++)
	F[i] = notF[i] + poly[i];
	
    //pair(x,y) are not friends
	sort(notF+1, notF+N+1);
    for(int i=1, cnt = 0; i <= N; i++)
        if(notF[i] == notF[i-1]) ans += cnt++;
        else cnt = 1;
    
    //pair(x,y) are freinds
    sort(F+1, F+N+1);
    for(int i=1, cnt=0; i <= N; i++)
        if(F[i] == F[i-1]) ans += cnt++;
        else cnt = 1;
    
    cout<<ans<<endl;
    
    return 0;
}