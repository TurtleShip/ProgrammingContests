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

struct Edge
{
    int to;
    ll dist;
    Edge(int t, ll d) : to(t) , dist(d) {}
};

void process();

ll INF = 2147483648ll;
ll bestCity;

int main()
{
    int T;
    cin>>T;
    for(int idx=1; idx <= T; idx++)
    {
        process();
        if(bestCity == INF) bestCity = -1;
        cout<<"Case #"<<idx<<": "<<bestCity<<endl;
    }
    return 0;
}

void process()
{
    
    int N; // number of cities
    int P; // number of friends
    int M; // number of roads
    int X[201]; //X[i] = city number that a friend i starts
    int V[201]; //V[i] = time it takes for a friend to travel 1 distance
    
    ll best[10001]; //best[i] = the fastest time it takes for the current friend to get to city i
    ll ans[10001]; //ans[i] = the time it takes for all friends to gather to city i

    /*
     edges[i][j] = information on edges from city i to (j)th city connectet to city i.
     For example, let's say city 2 is connected to city 1, 3, 4, and 5.
     edges[2][0] = Edge(1, ??)
     edges[2][1] = Edge(3, ??)
     edges[2][2] = Edge(4, ??)
     edges[2][3] = Edge(5, ??)
     */
    vector<Edge>edges [10001];

    
    //Receiving input started
    cin>>N>>P>>M;
    
    for(int i=1;  i <= P; i++)
        cin>>X[i]>>V[i];
    
    for(int i=0; i < M; i++)
    {
        int D, L;
        cin>>D>>L;
        int prev = -1;
        for(int j=0; j < L; j++)
        {
            if(prev == -1)
            {
                cin>>prev;
            }
            else
            {
                int cur;
                cin>>cur;
                edges[prev].push_back(Edge(cur,D));
                edges[cur].push_back(Edge(prev,D));
                prev = cur;
            }
        }
    }
    //Receiving input ended
    
    /*
    //Check edge info
    for(int i=1; i <= N; i++)
        if(edges[i].size() > 0)
            for(int j=0; j < edges[i].size(); j++)
                cout<<"Edge from "<<i<<" to "<<edges[i][j].to<<" with distance "<<edges[i][j].dist<<endl;
     */
    
    //We begin by assuming that no city is valid
    for(int i=1; i <= N; i++)
        ans[i] = -1;
    
    //Use dijkstra algorithm
    for(int i=1; i <= P; i++)
    {
        //Figure out distance from each friend to each city
        for(int j=1; j <= N; j++)
            best[j] = INF;
        
        int start = X[i];
        int speed = V[i];
        
        best[start] = 0;
        /* S ia a set of erticies whose final shortest-path weights from the source s
         have already been determined. The algorithm repeatedly selects the vertex u from (all vertex - S)
         with the minimum shorest-path estimate, add u to S and relaxes all edges leaving u.
         */
        set< pair<ll,int> > S;
        S.insert( make_pair(best[start], start));
        
        while(!S.empty())
        {
            int curCity = S.begin()->second;
            int curCost = S.begin()->first;
            S.erase(S.begin());
            //Visit all cities connected to the current city
            for(int j=0; j < edges[curCity].size(); j++)
            {
                int newCity = edges[curCity][j].to;
                int newCost = curCost + edges[curCity][j].dist * speed;
                
                if(newCost < best[newCity])
                {
                    best[newCity] = newCost;
                    S.insert( make_pair(newCost, newCity));
                }
            }
        }
       
        /*
         cout<<"Friend #"<<i<<" info"<<endl;
        for(int j=1; j <= N; j++)
            cout<<"To city "<<j<<" : "<<best[j]<<endl;
        */
        for(int j=1; j <= N; j++)
            ans[j] = max(ans[j], best[j]);
    }
    
    bestCity = INF;
    for(int i=1; i <= N; i++)
        bestCity = min(bestCity, ans[i]);
}