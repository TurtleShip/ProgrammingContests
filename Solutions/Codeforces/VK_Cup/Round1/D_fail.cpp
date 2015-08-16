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


set< pair<int,int> >path;
set < pair<int,int> >ans;
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
        
        path.insert( make_pair( min(a,b) , max(a,b) ));
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
            if(K == deg)
            {
                ans.insert( make_pair( min(cur,a), max(cur,a) ) );
                continue;
            }
         
            
            for(int i=1; i <= N; i++)
            {
                if(!visited[i] && path.count( make_pair( min(cur,i), max(cur,i) )))
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
            if(K == deg)
            {
                ans.insert( make_pair( min(cur,b), max(cur,b) ) );
                continue;
            }


            for(int i=1; i <= N; i++)
            {
                if(!visited[i] && path.count( make_pair( min(cur,i), max(cur,i) )))
                {
                    Q.push(i);
                    Q.push(deg+1);
                }
            }
        }
    }
    
    cout<<ans.size()<<endl;
    
       
    return 0;
}