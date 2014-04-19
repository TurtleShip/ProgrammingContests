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

vector<int> candies;
int maxVal;
int N;

void rec(int idx, int Sean, int Pat, int SeanReal)
{
    if(idx == N)
    {
        if(Sean == Pat && Pat != 0)
            maxVal = max(maxVal, SeanReal);
    }
    else
    {
        rec(idx+1, Sean ^ candies[idx], Pat, SeanReal + candies[idx]);
        rec(idx+1, Sean, Pat ^ candies[idx], SeanReal);
    }
}

int main()
{
    int T;
    cin>>T;
    
    for(int idx = 1; idx <= T; idx++)
    {
        cin>>N;
        candies.clear();
        maxVal = -1;
        
        for(int i=0; i < N; i++)
        {
            int cur;
            cin>>cur;
            candies.push_back(cur);
        }
        
        rec(0,0,0,0);
        string ans;
        stringstream ss;
        ss<<maxVal;
        ss>>ans;
        if(maxVal== -1) ans = "NO";
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    return 0;
}