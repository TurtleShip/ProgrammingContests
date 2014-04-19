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

const int OFFSET = 1000;
vector<int> Y[1010 + OFFSET];
vector<int> X[1010 + OFFSET];
vector< pair<int,int> > pts(200);
int main()
{
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    REP(i,0,N)
    {
        int x,y;
        cin>>x>>y;
        x += OFFSET;
        y += OFFSET;
        Y[y].push_back(x);
        X[x].push_back(y);
        pts[i] = make_pair( x, y );
    }
    
    int ans = 0;
    REP(i,0,N)
    {
        int x = pts[i].first;
        int y = pts[i].second;
        
        bool l = false, r = false, u = false, d = false;
        REP(j,0,X[x].size())
        {
            if(X[x][j] < y)
                d = true;
            else if(X[x][j] > y)
                u = true;
            if(d && u) break;
        }
        
        REP(j,0,Y[y].size())
        {
            if(Y[y][j] < x)
                l = true;
            else if(Y[y][j] > x)
                r = true;
            if(l && r) break;
        }
        
        if(l && r && u && d)
            ans++;
    }
    
    cout<<ans<<endl;

    return 0;
}