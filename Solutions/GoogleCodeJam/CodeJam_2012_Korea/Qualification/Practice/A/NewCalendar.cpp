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
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;

ll M;// number of month
ll Mday; //number of days in a month
ll Wday; //number of ways in a week
ll res;

void process();

int main()
{
    int T;
    cin>>T;
    
    for(int idx=1; idx <= T; idx++)
    {
        cin>>M>>Mday>>Wday;
        process();
        cout<<"Case #"<<idx<<": "<<res<<endl;
    }

    return 0;
}

void process()
{
    ll cycleLen = 0ll; //how many lines in a cycle
    ll cycleMon = 0ll; //how many months in a cycle
    ll prev = 0;
    do {
        cycleLen += (prev + Mday) / Wday;
        cycleLen += ((prev + Mday) % Wday == 0) ? 0 : 1ll;
        prev = (prev + Mday) % Wday;
        cycleMon += 1ll;
    } while (prev != 0 && cycleMon < M);
    
    if(cycleMon == M)
    {
        res = cycleLen;
    }
    else
    {
        res = (M / cycleMon) * cycleLen;
        for(int i=0; i < (M%cycleMon); i++)
        {
            res += (prev + Mday) / Wday;
            res += ((prev + Mday) % Wday == 0) ? 0 : 1ll;
            prev = (prev + Mday) % Wday;
        }
    }
}