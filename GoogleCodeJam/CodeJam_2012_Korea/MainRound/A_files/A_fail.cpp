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

ll N,A,B,C,D,E,F;
ll us[3];
ll enemies[3];
ll ans;
vector< pair<ll,int> > aFight;
vector< pair<ll,int> > bFight;
vector< pair<ll,int> > cFight;

void process();

struct Bat
{
    int F;
    int E;
    ll point;
    Bat(int f=-1, int e=-1, ll p=-1)
    {
        F = f;
        E = e;
        point = p;
    }
};

bool sortBat(Bat a, Bat b)
{
    if(a.point != b.point) return a.point > b.point;
    return enemies[a.E] > enemies[b.E];
}

int main()
{
    int T;
	cin>>T;
    
    for(int idx=1; idx <=T; idx++)
    {
        process();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    return 0;
}

void process()
{
    ans = 0;
    cin>>N>>us[0]>>us[1]>>us[2]>>enemies[0]>>enemies[1]>>enemies[2];

    vector<Bat> battle(9);
    for(int i=0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            ll p;
            cin>>p;
            battle[3*i+j] = Bat(i,j,p);
        }
    }
    
    sort(battle.begin(), battle.end(), sortBat);
    
    for(int i=0; i < 9 && 0 < N; i++)
    {
        if(us[battle[i].F] == 0 || enemies[battle[i].E] == 0)
            continue;
        //cout<<battle[i].F<<" vs "<<battle[i].E<<" : "<<battle[i].point<<endl;
        ll die = min(us[battle[i].F], enemies[battle[i].E]);
        us[battle[i].F] -= die;
        enemies[battle[i].E] -= die;
        ans += die * battle[i].point;
        N -= die;
    }
    if(N > 0) cout<<"WRONG!!!!!!!!"<<endl;
}