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

ll want[maxN];
bool chk[maxN];
vector<int> have[maxN];
int group[maxN];
pair<int,int> ans[maxN];
bool sortGroup(int a, int b)
{
    return have[a].size() < have[b].size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    memset(chk, false, sizeof(chk));
    
    int N, M, X, Y;
    cin>>N>>M>>X>>Y;
    
    REP(i,0,N)
    cin>>want[i];
    
    REP(i,0,M)
    {
        ll cur;
        cin>>cur;
        int low = int( lower_bound(want, want+N, cur - Y) - want);
        int up = int( upper_bound(want, want+N, cur + X) - want );
        
        for(int j=low; j < up; j++)
            have[i].push_back(j);
        
        group[i] = i;
    }
    
    sort(group, group+M, sortGroup);
    
    int K = 0; //the maximum number of soldiers equipped with bulletproof vests
    
    for(int i=0; i < M; i++)
    {
        int id = group[i];
        for(int j=0; j < have[id].size(); j++)
        {
            if(!chk[ have[id][j] ])
            {
                chk[ have[id][j] ] = true;
                ans[K] = make_pair( have[id][j] + 1, id + 1 );
                K++;
                
                break;
            }
        }
    }
    
    cout<<K<<endl;
    REP(i,0,K)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    

    return 0;
}