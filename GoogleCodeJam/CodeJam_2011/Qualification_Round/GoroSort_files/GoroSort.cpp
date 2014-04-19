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
        int O = 0;
        for(int i=1; i <= N; i++)
        {
            int cur;
            cin>>cur;
            if(cur != i) O++;
        }
        
        cout<<"Case #"<<idx<<": "<<O<<".000000"<<endl;
    }
    return 0;
}