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

    int T;
    cin>>T;
    
    for(int idx=1; idx <=T; idx++)
    {
        int N; //number of cities
        int P; //number of friends
        int M; //number of roads
        
        cin>>N;
        cin>>P;
        cin>>M;
        
        int dist[N+1][N+1];
        memset(dist, -1, sizeof(dist));
        
        int ans = 0;
        vector< pair<int,int> >frds;
        for(int i=0; i < P; i++)
        {
            int x; //city number where a friends starts
            int v; //time it takes a friend to move 1 distance
            cin>>x;
            cin>>v;
            frds.push_back( make_pair(x,v) );
        }
        
        for(int i=0; i < M; i++)
        {
            int d; //distance between cities using this road
            int l; //number of cities that a road passes
            cin>>d;
            cin>>l;
            int prev;
            cin>>prev;
            for(int j=1; j < l; j++)
            {
                int next;
                cin>>next;
                dist[prev][next] = dist[next][prev] = d;
                prev = next;
            }
        }
        
       
        bool canGo[N+1];
        memset(canGo, false, sizeof(canGo));
        
        int start = frds[0].first;
        canGo[start] = true;
        queue<int> Q;
        Q.push(start);
        while(!Q.empty())
        {
            int cur = Q.front(); Q.pop();
            for(int i=1; i <= N; i++)
            {
                if(dist[cur][i] != -1 && !canGo[i])
                {
                    canGo[i] = true;
                    Q.push(i);
                }
            }
        }
        
        bool valid = true;
        for(int i=1; i < P; i++)
        {
            if(!canGo[frds[i].first])
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
            //all cities where friends start are conncted. They can meet.
            //Find the best place to meet.

            ll frdDist[P][N+1];
            memset(frdDist, 0, sizeof(frdDist));
            
            for(int i=0; i < P; i++)
            {
                int start = frds[i].first;
                ll curDist = 0;
                queue<int> Q;
                Q.push(start);
                Q.push(curDist);
                
                while(!Q.empty())
                {
                    int curLoc = Q.front(); Q.pop();
                   ll curDist = Q.front(); Q.pop();
                    for(int j=1; j <= N; j++)
                    {
                        if(j == start) continue;
                        ll newDist = curDist + frds[i].second * ll(dist[curLoc][j]);

                        if( (frdDist[i][j] == 0 || newDist < frdDist[i][j]) && dist[curLoc][j] != -1 ) 
                        {
                            frdDist[i][j] = newDist;
                            Q.push(j);
                            Q.push(newDist);
                        }
                    }
                }
            }
            
            
            //try all cities
            ll best = -1;
            for(int i=1; i <= N; i++)
            {
                if(!canGo[i]) continue;
                ll cur = 0;
                
                for(int j=0; j < P; j++)
                {
                    cur = max(cur, frdDist[j][i]);
                }
                if(best == -1 || cur < best)
                    best = cur;
            }
            
            
            cout<<"Case #"<<idx<<": "<<best<<endl;
        }
        else
        {
            cout<<"Case #"<<idx<<": "<<-1<<endl;
        }

    }
    return 0;
}