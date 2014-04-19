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
    int N;
    cin>>N;
    
    vector<int> V(5,0);
    
    for(int i=0; i < N; i++)
    {
        int cur;
        cin>>cur;
        V[cur]++;
    }
    
    int ans = V[4];
    int two = V[2]/2;
    ans += two;
    V[2] = V[2] - 2 * two;
    int odd = min(V[1], V[3]);
    V[1] -= odd;
    V[3] -= odd;
    ans += odd;
    
    if(V[1] > 0)
    {
        ans += V[1] / 4;
        
        if(V[2] == 0)
        {
            if(V[1] % 4 != 0)
                ans++;
        }
        else
        {
            if(V[1] % 4 != 0)
            {
                if(V[1] % 4 <= 2)
                    ans++;
                else
                    ans += 2;
            }
            else
            {
                ans++;
            }
        }
    }
    
    if(V[3] > 0)
    {
        ans += V[3];
        if(V[2] > 0)
            ans++;
    }
    
    if(V[1] == 0 && V[3] == 0 && V[2] > 0)
        ans++;
    
    cout<<ans<<endl;
    return 0;
}