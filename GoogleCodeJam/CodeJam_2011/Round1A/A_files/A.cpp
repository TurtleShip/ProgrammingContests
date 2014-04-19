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

ll N, PD, PG;
string ans;

void process();
int GCD();

int main()
{
    int T;
    cin>>T;
    for(int idx=1; idx <= T; idx++)
    {
        cin>>N>>PD>>PG;
        process();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    return 0;
}

int GCD(int a, int b)
{
	if(b == 0) return a;
	return GCD(b, a%b);
}

void process()
{
    //not a possible scenario
    if((PG == 100 && PD != 100) || (PG == 0 && PD != 0))
    {
        ans = "Broken";
        return;
    }
    
    ll gcd = (ll)GCD(PD, 100);
    ll possD = 100 / gcd;
    
    if(possD <= N) ans = "Possible";
    else ans = "Broken";
        
}