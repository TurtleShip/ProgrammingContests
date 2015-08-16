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

int main()
{
    int N;
    cin>>N;
    
    int init;
    cin>>init;
    int minV = init;
    int maxV = init;
    int ans = 0;
    for(int i=1; i < N; i++)
    {
        int cur;
        cin>>cur;
        if(cur < minV)
        {
            minV = cur;
            ans++;
        }
        else if(cur > maxV)
        {
            maxV = cur;
            ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}