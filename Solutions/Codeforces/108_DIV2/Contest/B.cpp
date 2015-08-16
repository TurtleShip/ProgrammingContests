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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
\
#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;

int main()
{
    ll N, M;
    cin>>N;
    cin>>M;
    
    ll x, y;
    cin>>x; cin>>y;
    
    int K;
    cin>>K;
    ll step = 0ll;
    
    for(int i=0; i < K; i++)
    {
        ll dx; ll dy;
        cin>>dx;
        cin>>dy;
        ll curStepX = -1ll;
        ll curStepY = -1ll;
        ll curStep;
        
        if(dx != 0)
        {
            if(dx > 0) curStepX = (N-x)/dx;
            else curStepX = (1ll-x)/dx;
        }
        
        if(dy != 0)
        {
            if(dy > 0) curStepY = (M-y)/dy;
            else curStepY = (1ll-y)/dy;

        }
        
        if(dx != 0 && dy != 0)
        {
            curStep = min(curStepX, curStepY);
        }
        else if(dx != 0) curStep = curStepX;
        else if(dy != 0) curStep = curStepY;

        x += dx * curStep;
        y += dy * curStep;
        step += curStep;
    }
    
    cout<<step<<endl;
    
    return 0;
}