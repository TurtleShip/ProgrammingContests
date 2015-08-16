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

const int maxN = 10010;

struct obj
{
    ll cost;
    int sz;
    int id;
    obj(ll c=-1, int s=-1, int i=-1) : cost(c), sz(s), id(i) {}
};

/*
 dp[i][j] = best result considering customer 1 ... (i-1) and shoes (j-1)
 */
ll dp[maxN][maxN];
obj shoes[maxN];
obj cus[maxN];
int N, M;
bool compSize(obj a, obj b)
{
    return a.sz < b.sz;
}

ll rec(int,int);
bool canBuy(int,int);
int main()
{
    ios_base::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0; i < N; i++)
    {
        cin>>shoes[i].cost>>shoes[i].sz;
        shoes[i].id = i;
    }
    
    cin>>M;
    for(int i=0; i < M; i++)
    {
        cin>>cus[i].cost>>cus[i].sz;
        cus[i].id = i;
    }

    sort(shoes, shoes + N, compSize);
    sort(cus, cus + M, compSize);
    
    vector< pair<int,int> >ans;
    
    ll total = 0;
    for(int i=0; i < M; i++)
        for(int j=0; j < N; j++)
            dp[i][j] = -1ll;
    
    cout<<rec(0,0)<<endl;
    
    
    return 0;
}

ll rec(int cID, int sID, int numShoe)
{
	cout<<"rec("<<cID<<","<<sID<<")"<<endl;
    ll& res = dp[cID][sID];
    
   // if(res != -1ll)
      //  return res;
    
    res = 0ll;
    //base case
    if(cID == M || sID == N) //the last customer
    {
        return res;
    }
    
    //current customer does not buy
    res = rec(cID+1, sID);
    
    //current customer skips the current shoe
    res = max(res, rec(cID, sID+1));
    
    //current customer buys
    if( canBuy(cID, sID) )
{
	cout<<cus[cID].cost<<" buys "<<shoes[sID].cost<<endl;
        res = max(res, shoes[sID].cost + rec(cID+1, sID+1));
}
    
    return res;
}

bool canBuy(int cID, int sID)
{
    return ( cus[cID].cost >= shoes[sID].cost && (cus[cID].sz == shoes[sID].sz || (cus[cID].sz -1) == shoes[sID].sz) );
}