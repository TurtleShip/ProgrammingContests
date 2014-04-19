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

/*
 This code belongs to Avalenche.
 I only placed comments and change variable names 
 to help me better understand his code.
 */
const int maxN = 100010;

struct obj
{
    int cost, size, id;
    obj(int c = -1, int sz = -1, int idx = -1): cost(c), size(sz), id(idx) {}
};

bool compSize(obj a, obj b)
{
    return a.size < b.size;
}

bool compCost(obj a, obj b)
{
    return a.cost > b.cost;
}


//waitList[i] = waiting list of customer ids who can buy shoe i
vector<int> waitList[maxN];

//purchase[i] = shoe id that customer i actually purchased
//It is -1 if customer i did not purchase anything
int purchase[maxN];

//sold[i] = true if shoe i is sold
bool sold[maxN]; 

//returns true if shoe x is successfully purchased
bool buy(int x)
{
    //you cannot buy what is already sold
    if(sold[x]) return false;
    
    //Shoe is x is now being sold to...
    sold[x] = true;
    
    //Let's decide who buys this shoe
    for(int i=0; i < waitList[x].size(); i++)
    {
        int pot = waitList[x][i]; //potential customer id
        
        /*
         If the potential customer has not made any purchases,
         or if somebody else can buy what he previously bought
         (there is another person who can buy he has already purchased
         */
        if( purchase[pot] == -1 || buy( purchase[pot] ))
        {
            //the current potential customer takes this shoe
            purchase[pot] = x;
            return true; //successful purchase
        }
    }
    //Every already bought other shoes
    return false;
}

obj shoes[maxN]; //info on shoes
obj cus[maxN]; //info on customers
ll cost[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N;
    for(int i=0; i < N; i++)
    {
        cin>>shoes[i].cost>>shoes[i].size;
        shoes[i].id = i;
        cost[i] = shoes[i].cost;
    }

    sort(shoes, shoes+N, compSize);
    
    cin>>M;
    for(int i=0; i < M; i++)
    {
        cin>>cus[i].cost>>cus[i].size;
        cus[i].id = i;
    }
    
    for(int i=0; i < M; i++)
    {
        int idx = int(lower_bound(shoes, shoes+N, obj(-1,cus[i].size,-1), compSize) - shoes);
        
        while( shoes[idx].size == cus[i].size || shoes[idx].size == (cus[i].size + 1) )
        {
            if(shoes[idx].cost <= cus[i].cost)
                waitList[shoes[idx].id].push_back( cus[i].id );
            idx++;
        }
    }
    
    sort(shoes, shoes + N, compCost);
    
    memset(purchase, -1, sizeof(purchase));
    
    for(int i=0; i < N; i++)
    {
        memset(sold, false, sizeof(sold));
        buy( shoes[i].id );
    }
    
    ll total = 0LL;
    vector< pair<int,int> >ans;
    
    for(int i=0; i < M; i++)
    {
        if(purchase[i] == -1)
            continue;
        
        total += cost[ purchase[i] ];
        ans.push_back( make_pair( i+1, purchase[i] + 1) );
    }
    
    cout<<total<<endl;
    cout<<ans.size()<<endl;
    
    for(int i=0; i < ans.size(); i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    
    return 0;
}