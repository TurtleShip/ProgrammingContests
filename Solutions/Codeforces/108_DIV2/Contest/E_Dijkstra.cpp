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

struct Node
{
    int row;
    int col;
    int point;
    Node(int r=-1, int c=-1, int p=-1)
    {
        row = r;
        col = c;
        point = p;
    }
};

int main()
{
    int N, M, K;
    cin>>N;
    cin>>M;
    cin>>K;
    
    Node nodes[101][101];

     int pt[N+1][M+1];
     bool chk[N+1][M+1];
    
    for(int i=1; i <= N; i++)
    {
        for(int j=1; j <= M; j++)
        {
            int cur;
            cin>>cur;
            pt[i][j] = cur;
 
            chk[i][j] = false;
        }
    }
    
    int sr, sc;
    
    vector< pair<int,int> > imp;
    
    for(int i=0; i < K; i++)
    {
        int r ,c;
        cin>>r; cin>>c;
        imp.push_back( make_pair(r,c) );
    }
    sr = imp[0].first;
    sc = imp[0].second;
    
    queue<int> Q;
    Q.push(sr);
    Q.push(sc);
    Q.push(0);
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    while(!Q.empty())
    {
        int curR = Q.front(); Q.pop();
        int curC = Q.front(); Q.pop();
        int curP = Q.front(); Q.pop();
        
        for(int i=0; i < 4; i++)
        {
            int nr = curR + dx[i];
            int nc = curC + dy[i];
            
            if(1<= nr && nr <= N && 1 <= nc && nc <= M)
            {
                int newPoint = curP + pt[curR][curC];
                if(nodes[nr][nc].point == -1 || newPoint < nodes[nr][nc].point)
                {
                    nodes[nr][nc].row = curR;
                    nodes[nr][nc].col = curC;
                    nodes[nr][nc].point = newPoint;
                    Q.push(nr);
                    Q.push(nc);
                    Q.push(newPoint);
                }
            }
        }
    }
    
    chk[sr][sc] = true;
    int ans = 0;
    for(int i=1; i < K; i++)
    {
        int er = imp[i].first;
        int ec = imp[i].second;
   
        Q.push(er);
        Q.push(ec);
        while(!Q.empty())
        {
            int curR = Q.front(); Q.pop();
            int curC = Q.front(); Q.pop();
			if(chk[curR][curC]) break;
            chk[curR][curC] = true;
            
            if(curR == sr && curC == sc)
                break;
            
            Q.push(nodes[curR][curC].row);
            Q.push(nodes[curR][curC].col);
        }

    }
    
    for(int i=1; i <= N; i++)
    {
        for(int j=1; j <= M; j++)
        {
            if(chk[i][j]) ans += pt[i][j];
        }
    }
    
    cout<<ans<<endl;

      
    for(int i=1; i <= N; i++)
    {
        for(int j=1; j <= M; j++)
        {
            if(chk[i][j]) cout<<'X';
            else cout<<'.';
        }
        cout<<endl;
    }
    
    return 0;
}