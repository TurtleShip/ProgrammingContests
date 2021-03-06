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
    
    for(int idx=1; idx <=T; idx++)
    {
        ll M; //number of months in a year
        ll Mday; //number of days in a month
        ll Wday; //number of days in a week
        
        ll lines = 0ll; //lines required to print a calendar
        
        cin>>M;
        cin>>Mday;
        cin>>Wday;
        
        lines = ((Mday) / Wday) * M;
if(Mday % Wday != 0) lines += M;
        ll fac = ((Mday % Wday) == 0) ? 0 : 1;
        
        lines += fac * (M-1);
        

        cout<<"Case #"<<idx<<": "<<lines<<endl;
    }
    
    return 0;
}