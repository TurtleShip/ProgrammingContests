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

int dp[maxN][maxK];
vector<int> edges[maxN];
int N,K,ans;

void dfs(int,int);

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin>>N>>K;
    
    for(int i=0; i < N-1; i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    ans = 0;
    dfs(-1, 1);
    
    cout<<ans<<endl;
    
    return 0;
}

/*
 dfs moves from the root(1) to a leaf.
 When dfs reaches leaf, it moves upward, doing following operation.
 1. For 0 <= j < K, 
  A = number of vertices that can REACH ITS PARENT using j edges
  B = number of vertices that can BE REACHED BY THE CURRENT NODE using (K-j-1) edges.
 Let's call
  x = a vertice that can reach the current node's parent using j edges.
  y = a vertice that can be reched by the current node using (K-j-1) edges.
 
 Note that it takes one edge from its parent to the current node.
 So from x to y, it takes (j + 1 + (K-j-1)) = K edges.
 So our answer is sum of |A| * |B|, which is number of vertices that can reach each other
 using K edges.
 
 2. Update its parent's dp info.
 
 Note that doing step #1 before step #2 ensures that we do not allow duplicates.
 To illustrate, 
 */
void dfs(int prev, int cur)
{
    dp[cur][0] = 1;
    
    for(int i=0; i < edges[cur].size(); i++)
    {
        if(edges[cur][i] == prev) continue;
        
        int next = edges[cur][i];
        
        dfs(cur, next);
        
        //it takes one edge to go from cur to next
        for(int j=0; j < K; j++)
            ans += dp[cur][j] * dp[next][K-j-1];
        
        for(int j=1; j <= K; j++)
            dp[cur][j] += dp[next][j-1];
    }
}