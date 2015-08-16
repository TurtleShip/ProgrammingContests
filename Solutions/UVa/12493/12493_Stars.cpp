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

//Returns Thi(N)
ll getThi(ll val) {
    ll res = val;
    ll cur = 3ll;
    if(val % 2ll == 0) {
        res /= 2ll;
        while(val % 2ll == 0)
            val /= 2ll;
    }
    ll sqVal = sqrt(val) + 1ll;

    while(val != 1ll) {
        if(cur > sqVal) break;
        
        if(val % cur == 0) {
            res /= (cur);
            res *= (cur-1ll);
            while(val % cur == 0)
                val /= cur;
        }
        cur += 2ll;
    }
    
    if(val != 1) {
        res /= val;
        res *= (val-1ll);
    }
    return res;
}
    
int main()
{
    ll N;
    
    while( scanf("%lld", &N) != EOF) {
        printf("%lld\n", getThi(N)/2ll);
    }
    
    return 0;
}