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
    
    vector<int> vec;
    for(int i=0; i < N; i++)
    {
        int cur;
        cin>>cur;
        vec.push_back(cur);
    }
    
    int minV = vec[0];
    int maxV = vec[0];
    int ans = 0;
    for(int i=1; i < N; i++)
    {
        if(vec[i] < minV)
        {
            ans++;
            minV = vec[i];
        }
        else if(vec[i] > maxV)
        {
            ans++;
            maxV = vec[i];
        }
    }
    
    cout<<ans<<endl;
    return 0;
}