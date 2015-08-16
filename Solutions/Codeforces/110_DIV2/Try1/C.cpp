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
    string S,U;
    cin>>S>>U;
    
    int lenU = U.size();
    
    string extra(lenU, '?');
    
    S = extra + S + extra;
    int lenS = S.size();
    
    int best = 2001;
    REP(i,0, lenS)
    {
        int cur = 0;
        REP(j,0,lenU)
        {
            if(S[i+j] != U[j]) cur++;
        }
        best = min(best, cur);
    }
    
    cout<<best<<endl;
    
    return 0;
}