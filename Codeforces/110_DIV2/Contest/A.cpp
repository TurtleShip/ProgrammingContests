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
    int board[N][N];
    
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            cin>>board[i][j];
        }
    }
    
    int col[N];
    int row[N];
    
    for(int i=0; i < N; i++)
    {
        int curC = 0;
        int curR = 0;
        for(int j=0; j < N; j++)
        {
            curC += board[j][i];
            curR += board[i][j];
        }
        col[i] = curC;
        row[i] = curR;
    }
    
    int ans = 0;
    REP(i,0,N)
    {
        REP(j,0,N)
        {
            if(col[j] > row[i])
                ans++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}