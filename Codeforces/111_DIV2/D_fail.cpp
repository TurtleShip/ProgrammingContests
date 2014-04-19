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

struct Edge
{
    int A;
    int B;
    int cost;
    int idx;
    Edge(int a, int b, int c, int id)
    {
        A = a;
        B = b;
        cost = c;
        idx = id;
    }
};

bool sortEdge(Edge a, Edge b)
{
    return a.cost < b.cost;
}

int main()
{
    int N,M;
    cin>>N>>M;
    string any = "any";
    string least = "at least one";
    string none = "none";
    
    vector<string> ans(M,none);
    vector<Edge> edges;
    
    
    REP(i,0,M)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back( Edge(a,b,c,i) );
    }
    
    int prevCost = -1;
    int prevID = -1;
    sort(edges.begin(), edges.end(), sortEdge);
    
    int id[N+1];
    REP(i,1,N+1)
    {
        id[i] = i;
        //cout<<"id["<<i<<"] : "<<id[i]<<endl;
    }

    int verts = 0;
    REP(i,0,M)
    {
        int A = edges[i].A;
        int B = edges[i].B;
        int cost = edges[i].cost;
       // cout<<"checking edge from "<<A<<" to "<<B<<endl;
        if(id[A] == id[B])
        {
           // cout<<"id["<<A<<"] : "<<id[A]<<endl;
          //  cout<<"id["<<B<<"] : "<<id[B]<<endl;
            if(prevCost == cost)
            {
                ans[edges[i].idx] = least;
//cout<<"start at "<<edges[i].idx<<"th edge"<<endl;
                for(int j = i-1; j >=0 && edges[j].cost == prevCost; j--)
                {

                    int oldA = id[edges[j].A];
//cout<<"oldA : "<<oldA<<endl;
                    if(oldA == id[A])
                    {
	//cout<<"changing "<<edges[j].idx<<"th edge"<<endl;
                        ans[edges[j].idx] = least;
                    }
                        
                }
                
            }
        }
        else
        {
            if(verts == N-1 && prevCost != cost) break;
         //   cout<<"picking edge from "<<A<<" to "<<B<<endl;
          //  cout<<"id["<<A<<"] : "<<id[A]<<endl;
          //  cout<<"id["<<B<<"] : "<<id[B]<<endl;
            int newId = min(id[A], id[B]);
            int oldId = max(id[A], id[B]);
            
           // cout<<"newId : "<<newId<<endl;
           // cout<<"oldId : "<<oldId<<endl;
            REP(j,1,N+1)
            if(id[j] == oldId)
                id[j] = newId;
            
           // cout<<"id["<<A<<"] : "<<id[A]<<endl;
           // cout<<"id["<<B<<"] : "<<id[B]<<endl;
            ans[edges[i].idx] = any;
            verts++; 
            prevCost = cost;
            prevID = newId;
        }
        
        
    }
    
    

    REP(i,1,N+1)
    if(id[i] != 1)
    {
        REP(j,0,M)
        ans[j] = none;
        break;
    }

    //cout<<"\n checked "<<endl;
    REP(i,0,M)
    cout<<ans[i]<<endl;
    return 0;
}