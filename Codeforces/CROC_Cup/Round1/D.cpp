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

const int maxN = 100010;


set<int> group[maxN];
int id[maxN];

bool sortGroup(set<int> a, set<int> b)
{
    return a.size() > b.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n,m;
    cin>>n>>m;
    memset(id, -1, sizeof(id));
    int G = 0;//number of groups
    int req = 0;
    for(int i=0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        bool isA = id[a] != -1;
        bool isB = id[b] != -1;
        
        if(isA && isB)
        {
            
            group[id[a]].insert(group[id[b]].begin(), group[id[b]].end());
            id[b] = id[a];
        }
        else
        {
            if(isA)
            {
                group[id[a]].insert(b);
                id[b] = id[a];
            }
            else if(isB)
            {
                group[id[b]].insert(a);
                id[a] = id[b];
            }
            else
            {
                group[G].insert(a);
                group[G].insert(b);
                id[a] = id[b] = G;
                cout<<"G : "<<G<<" : sz : "<<group[G].size()<<endl;
                G++;
            }
        }
    }
    cout<<"G : "<<G<<endl;
    sort(group, group+G, sortGroup);
    if( group[0].size() > n/3 )
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0; i < G; i++)
        {
            set<int>::iterator itr;
            cout<<"i : "<<i<<" , sz : "<<group[i].size()<<endl;
            for(itr = group[i].begin(); itr != group[i].end(); itr++)
                cout<<(*itr)<<" ";
            cout<<endl;
        }
        
    }
    
    return 0;
}