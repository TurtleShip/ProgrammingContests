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
const int maxN = 100000;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N,M,X,Y;
    
    cin>>N>>M>>X>>Y;
    
    ll sol[N];
    ll vest[M];
    
    REP(i,0,N)
        cin>>sol[i];
    
    REP(i,0,M)
        cin>>vest[i];
    
    int K = 0;
    int j=0;
    pair<int,int> ans[maxN];
    for(int i=0; i < N && j < M; i++)
    {
        while( j < M && !(sol[i] - X <= vest[j]) )
            j++;
        
        if(j < M && vest[j] <= sol[i] + Y)
        {
            ans[K++] = make_pair((i+1),(j+1));
            j++;
        }
    }
    
    cout<<K<<endl;
    for(int i=0; i < K; i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;

    return 0;
}