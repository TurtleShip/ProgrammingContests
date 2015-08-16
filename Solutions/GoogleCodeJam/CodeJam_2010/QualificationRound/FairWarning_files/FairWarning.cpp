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
typedef unsigned long long int ulli;

ulli GCD(ulli a, ulli b)
{
    if(b==0ULL) return a;
    return GCD(b, a%b);
}

bool sortBig(ulli a, ulli b)
{
    return (a < b);
}
int main()
{
    int C;
    cin>>C;
    
    for(int idx=1; idx <= C; idx++)
    {
        int N;
        cin>>N;
        vector<ulli> big(N,0ULL);
        for(int i=0; i < N; i++)
        {
            cin>>big[i];
        }
        sort( big.begin(), big.end(), sortBig);
        ulli gcd = big[1] - big[0];
        for(int i=2; i < N; i++)
        {
            gcd = GCD(gcd,big[i] - big[i-1]);
        }
        
        ulli ans = (big[0] % gcd == 0) ? 0 : (gcd - (big[0] % gcd));
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    return 0;
}