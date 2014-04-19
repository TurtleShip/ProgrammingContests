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

int main()
{
    int N,K;
    cin>>N>>K;
    
    vector<int> V(N,0);
    REP(i,0,N)
    cin>>V[i];
    
    int cut = V[K-1];
    
    int ans = 0;
    for(int i=0; i < N; i++)
    {
        if(V[i] < 1 || V[i] < cut)
            break;
        else ans++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}