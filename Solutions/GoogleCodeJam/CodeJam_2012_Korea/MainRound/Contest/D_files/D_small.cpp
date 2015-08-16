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
#define F first;
#define S second;
#define MP make_pair;
#define PB push_back;

typedef long long ll;
typedef pair<int,int> PII;

const int maxN = 1000001;

ll ans;
ll N, M;
ll Fac[maxN];
ll mac[maxN]; //막내
void setFac();
void process();
int main()
{
	setFac();
    int T;
    cin>>T;
    

    for(int i=1; i <=T; i++)
    {
        process();
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}

void setFac()
{
    memset(Fac, -1, sizeof(Fac));
    memset(mac, -1, sizeof(mac));
    for(int i=2; i <= maxN; i++)
    {
        for(int j=1; (i*j) <= maxN; j++)
        {
			Fac[i*j] += 1;
            if(mac[i*j] == -1) mac[i*j] = min(i,j);
        }
    }
}

void process()
{
    cin>>N>>M;
    ans = 0;
   // cout<<"N : "<<N<<" , facNum : "<<Fac[N]<<endl;
    for(int i = N-1; i >=2; i--)
        if(Fac[i] == Fac[N] && mac[i] >= M) ans++;

}
