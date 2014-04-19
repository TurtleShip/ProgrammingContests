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
#define MP make_pair;
#define PB push_back;

typedef long long ll;
typedef pair<int,int> PII;

int ans;

void process();

int main()
{
    int T;
    cin>>T;
    
    for(int idx=1; idx <= T; idx++)
    {
        process();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    return 0;
}

void process()
{
    int N;
    cin>>N;
    
    int P[N];
    int S[N];
    
    REP(i,0,N)
    {
        cin>>P[i];
        cin>>S[i];
    }
    
    // N <= 10  brute force
    
    vector<int> order(N,0);
    for(int i=0; i < N; i++)
        order[i] = i;
    ans = 0;
    do
    {
        int time = 0;
        
        for(int i=0; i < N; i++)
        {
            if(P[order[i]] < time) break;
            time += S[order[i]];
        }
        ans = max(ans, time);
        
    }while(next_permutation(order.begin(), order.end()));
}