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

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef long long ll;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

const int maxN = 1010;
bool isCol[maxN][maxN];
int vis[maxN][maxN][4];
int n,m;
int res;
int main()
{
    ios_base::sync_with_stdio(false);
    
    cin>>n>>m;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {
            char cur;
            cin>>cur;
            isCol[i][j] = (cur == '#');
        }
    
    res = -1;
    
    /*
     We need at least two magic curves
     
     */
    memset(vis, -1, sizeof(vis));
    queue<int> Q;
    Q.push(0);
    Q.push(0);
    Q.push(0);
    Q.push(RIGHT);
    vis[0][0][RIGHT] = 0;
    
    while(!Q.empty())
    {
        int r = Q.front(); Q.pop();
        int c = Q.front(); Q.pop();
        int col = Q.front(); Q.pop();
        int d = Q.front(); Q.pop();
        
        if(isCol[r][c])
        {
            for(int i=0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                int nCol = col;
                if(i != d) nCol++;
                
                if(0 <= nr && nr < n && 0 <= nc && nc <= m && (vis[nr][nc][i] == -1 || col < vis[nr][nc][i]))
                {
                    vis[nr][nc][i] = nCol;
                    Q.push(nr);
                    Q.push(nc);
                    Q.push(nCol);
                    Q.push(i);
                }
            }
        }
        else
        {
            int nr = r + dr[d];
            int nc = c + dc[d];
            
            if(0 <= nr && nr < n && 0 <= nc && nc <= m && (vis[nr][nc][d] == -1 || col < vis[nr][nc][d]))
            {
                vis[nr][nc][d] = col;
                Q.push(nr);
                Q.push(nc);
                Q.push(col);
                Q.push(d);
            }
        }
        
    }
    
    cout<<vis[n-1][m][RIGHT]<<endl;

    return 0;
}
