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
    
    for(int idx=1; idx <= N; idx++)
    {
        int C, R;
        cin>>C;
        cin>>R;
        vector<string> field;
        
        for(int i=0; i < R; i++)
        {
            string str;
            cin>>str;
            field.push_back(str);
        }
        
        /*
         Okay : G, S
         Not okay : W, R, T
         */
        bool chk[R][C];
        for(int i=0; i < R; i++)
        {
            for(int j=0; j < C; j++)
            {
                if(field[i][j] == 'G' || field[i][j] == 'S') chk[i][j] = true;
                else chk[i][j] = false;
            }
        }
        int ans = 0;
        for(int sr=0; sr < R; sr++)
        {
            for(int sc=0; sc < C; sc++)
            {
                int best = 0;
                int rowNum = 0;
                int colNum = 51;
                for(int er = sr; er < R; er++)
                {
                    int curCol = 0;
                    for(int ec = sc; ec < C; ec++)
                    {
                        if(chk[er][ec])
                        {
                            curCol++;
                        }
                        else break;
                    }
                    colNum = min(colNum, curCol);
                    if(colNum == 0) break;
                    rowNum++;
                    
                    best = max(best, colNum * rowNum);
                }
                ans = max(ans, best);
            }
        }
        cout<<"Case #"<<idx<<": "<<ans<<endl;
        
    }
    return 0;
}