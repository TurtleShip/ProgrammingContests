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

bool descend(int a, int b)
{
    return a >  b;
}

int main()
{
    int N;
    cin>>N;
    int sum = 0;
    vector<int> coins;
    REP(i,0,N)
    {
        int cur;
        cin>>cur;
        coins.push_back(cur);
        sum += cur;
    }
    
    sort(coins.begin(), coins.end(), descend);
    
    int take = 0;
    int cur = 0;
    REP(i,0,N)
    {
        cur += coins[i];
        sum -= coins[i];
        take++;
        if(sum < cur)
            break;
    }
    
    cout<<take<<endl;
    
    return 0;
}