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
    
    vector<int> first(N, 0);
    vector<int> sec(N,0);
    bool chk[N];
    memset(chk, false, sizeof(chk));
    
    string str;
    cin>>str;
    
    REP(i,0,N)
    first[i] = (str[i] - '0');
    
    REP(i,0,N)
    sec[i] = (str[i+N] - '0');
    
    sort(first.begin(), first.end());
    sort(sec.begin(), sec.end());
    
    //strictly less
    bool isLess = true;
    bool isMore = true;
    REP(i,0,N)
    {
        if(first[i] >= sec[i])
            isLess = false;
        
        if(first[i] <= sec[i])
            isMore = false;
    }
    
    if(isLess || isMore) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}