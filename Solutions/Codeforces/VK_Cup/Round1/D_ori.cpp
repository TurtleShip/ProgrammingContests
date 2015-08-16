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

const int maxN = 50010;
const int maxK = 510;

bool adj[50001][50001];

int main()
{
    ios_base::sync_with_stdio(false);

    
    //memset(adj, 0, sizeof(adj));
    
    
    int N; //number of vertices
    int K; //required distance
    cin>>N>>K;
    
    REP(i,0, N-1)
    {
        int a, b;
        cin>>a>>b;
        
        adj[a][b] = adj[b][a] = 1;
        
        //update
        queue<int> Q;
        bool visited[N+1];
        memset(visited, false, sizeof(visited));
        
        
        Q.push(a);
        Q.push(0);
        
        while(!Q.empty())
        {
            int cur = Q.front(); Q.pop();
            int deg = Q.front(); Q.pop();
            
            visited[cur] = true;
            adj[a][cur] = adj[cur][a] = deg;
            
            for(int i=1; i <= N; i++)
            {
                if(!visited[i] && adj[cur][i] == 1)
                {
                    Q.push(i);
                    Q.push(deg+1);
                }
            }
        }
        
        memset(visited, false, sizeof(visited));
        Q.push(b);
        Q.push(0);
        
        while(!Q.empty())
        {
            int cur = Q.front(); Q.pop();
            int deg = Q.front(); Q.pop();
            
            visited[cur] = true;
            adj[b][cur] = adj[cur][b] = deg;
            
            for(int i=1; i <= N; i++)
            {
                if(!visited[i] && adj[cur][i] == 1)
                {
                    Q.push(i);
                    Q.push(deg+1);
                }
            }
        }
    }
    
    
    
    int ans = 0;
 
                
    for(int i=1; i <=N; i++)
    {
        for(int j=(i+1); j <= N; j++)
        {
            if(adj[i][j] == K) 
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}