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

const int maxM = 100010;
int chk[maxM];

int main()
{
    ios_base::sync_with_stdio(false);
    
    int a,b,m,r0;
    
    cin>>a>>b>>m>>r0;
    
    memset(chk, -1, sizeof(chk));
    
    int prev = (a*r0 + b) % m;
    int idx = 1;
    chk[prev] = idx;
    
    while(true)
    {
        idx++;
        int next = (a*prev + b) % m;
        prev = next;
        if(chk[next] != -1) break;
        chk[next] = idx;
    }

    cout<<(idx - chk[prev])<<endl;

    return 0;
}