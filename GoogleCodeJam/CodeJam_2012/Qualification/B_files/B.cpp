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

int getNorm(int);
int getSurprise(int);

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    
    cin>>T;
    for(int idx=1; idx <= T; idx++)
    {
        int N,S,p;
        cin>>N>>S>>p;
        
        int best = getNorm(p);
        int surp = getSurprise(p);
        int res = 0;
        
        for(int i=0; i < N; i++)
        {
            int cur;
            cin>>cur;
            if(cur >= best)
            {
                res++;
            }
            else if(S > 0 && cur >= surp)
            {
                S--;
                res++;
            }
        }
        
        cout<<"Case #"<<idx<<": "<<res<<endl;
    }

    return 0;
}

int getNorm(int p)
{
    if(p <= 1) return p;
    return p + (p-1) * 2;
}

int getSurprise(int p)
{
    if(p <= 2) return p;
    return p + (p-2) * 2;
}