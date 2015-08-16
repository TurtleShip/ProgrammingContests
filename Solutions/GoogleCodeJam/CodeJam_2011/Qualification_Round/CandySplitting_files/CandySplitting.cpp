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
    int T;
    cin>>T;
    
    for(int idx = 1; idx <= T; idx++)
    {
        int N;
        cin>>N;

        int chk = 0;
        int small = 1000009;
        int sum = 0;
        for(int i=0; i < N; i++)
        {
            int cur;
            cin>>cur;
            chk = chk ^ cur;
            sum += cur;
            small = min(small, cur);
        }
        
        string ans;
        stringstream ss;
        ss<<(sum - small);
        ss>>ans;
        
        if(chk != 0) ans = "NO";
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    return 0;
}