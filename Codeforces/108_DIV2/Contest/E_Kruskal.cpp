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

bool sortNode(Node a, Node b)
{
    return (a.point > b.point);
}

int main()
{

    int N,M,K;
    cin>>N; cin>>M; cin>>K;
    vector<Node> nodes;
    int pt[N+1][M+1];
    bool chk[N+1][M+1];
    
    for(int i=1; i <= N; i++)
    {
        for(int j=1; j <= M; j++)
        {
            int cur;
            cin>>cur;
            pt[i][j] = cur;
            nodes.push_back( Node(i,j,cur) );
        }
    }
    vector< pair<int,int> >imp;
    for(int i=0; i < K; i++)
    {
        int r; int c;
        cin>>r; cin>>c;
        imp.push_back( make_pair(r,c) );
    }

    //Add nodes
    sort(nodes.begin(), nodes.end(), sortNode);
    
    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};
    memset(chk, true, sizeof(chk));
    
    for(int i=0; i < nodes.size(); i++)
    {
        if(nodes[i].row == imp[0].first && nodes[i].col == imp[0].second) continue;
        chk[nodes[i].row][nodes[i].col] = false;
        
        //check if it is okay to remove the current node
        bool visited[N+1][M+1];
        memset(visited, false, sizeof(visited));
        queue<int> Q;
        Q.push(imp[0].first);
        Q.push(imp[0].second);
        
        while(!Q.empty())
        {
            int curR = Q.front(); Q.pop();
            int curC = Q.front(); Q.pop();
            visited[curR][curC] = true;
            
            for(int i=0; i < 4; i++)
            {
                int nr = curR + dr[i];
                int nc = curC + dc[i];
                
                if(1 <= nr && nr <= N && 1 <= nc && nc <= M && !visited[nr][nc] && chk[nr][nc])
                {
                    Q.push(nr);
                    Q.push(nc);
                }
            }
        }
        
        bool isOkay = true;
        for(int i=0; i < K; i++)
        {
            if(!visited[imp[i].first][imp[i].second])
            {
                isOkay = false;
                break;
            }
        }
        if(!isOkay)
        {
            chk[nodes[i].row][nodes[i].col] = true;
        }
    }
    
    int ans = 0;
    for(int i=1; i <= N; i++)
        for(int j=1; j <= M; j++)
            if(chk[i][j]) ans += pt[i][j];
    
    cout<<ans<<endl;
    
    for(int i=1; i <= N; i++)
    {
        for(int j=1; j <= M; j++)
        {
            if(chk[i][j]) cout<<"X";
            else cout<<".";
        }
        cout<<endl;
    }
        
    
    return 0;
}