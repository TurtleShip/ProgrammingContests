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
    int n, m;
    cin>>n;
    cin>>m;
    
    int score[n][m];
    
    int best[m];
    for(int i=0; i < m; i++)
        best[i] = 0;
    
    for(int i=0; i < n; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j < m; j++)
        {
            int cur = (str[j] - '0');
            score[i][j] = cur;
            best[j] = max(best[j], cur);
        }
    }
    
    int ans = 0;
    for(int i=0; i < n; i++)
    {
        bool suc = false;
        for(int j=0; j < m; j++)
        {
            if(score[i][j] >= best[j])
            {
                suc = true;
                break;
            }
        }
        if(suc) ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}