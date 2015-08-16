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

int main()
{
    int INF = numeric_limits<int>::max();
    int N, M, K;
    cin>>N>>M;
    
    int x,y;
    cin>>x>>y;
    cin>>K;
    ll ans = 0ll;
    for(int k=0; k < K; k++)
    {
        int dx, dy;
        cin>>dx>>dy;
        
        int xStep = INF, yStep = INF;
        
        if(dx != 0)
            xStep = (dx < 0) ? (x-1)/abs(dx) : (N-x)/dx;
        
        if(dy != 0)
            yStep = (dy < 0) ? (y-1)/abs(dy) : (M-y)/dy;
        
        int step = min(xStep, yStep);

        x += dx * step;
        y += dy * step;
        ans += step;
    }
    
    cout<<ans<<endl;
    
    return 0;
}