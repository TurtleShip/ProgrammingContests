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
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    
    string ans = "";
    cin>>ans;
    
    //It is guranteed that 2 <= N
    for(int i=1; i < N; i++)
    {
        string cur;
        cin>>cur;
        int j = 0;
        while(j < ans.size() && ans[j] == cur[j])
            j++;
        
        ans = ans.substr(0,j);
    }
    
    cout<<ans.size()<<endl;

    return 0;
}