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
    
    for(int idx=1; idx <= T; idx++)
    {
        int N;
        cin>>N;
        int time = 0;
        
        int oran_prev_loc = 1;
        int oran_prev_time = 0;
        int blue_prev_loc = 1;
        int blue_prev_time = 0;
        
        bool isNumber = false;
        bool isBlue;

        for(int i=0; i < N*2; i++)
        {
            if(isNumber)
            {
                int num;
                int now;
                cin>>num;
                if(isBlue) 
                {
                    now = (blue_prev_time + abs(blue_prev_loc - num) + 1);
                    blue_prev_loc = num;
                    time = max(time + 1, now);
                    blue_prev_time = time;
                }
                else
                {
                    now = (oran_prev_time + abs(oran_prev_loc - num) + 1);
                    oran_prev_loc = num;
                    time = max(time + 1, now);
                    oran_prev_time = time;
                }
                
                isNumber = false;
            }
            else
            {
                char ch;
                cin>>ch;
                isBlue = (ch == 'B');
                isNumber = true;
            }

        }
        
        cout<<"Case #"<<idx<<": "<<time<<endl;
    }
    return 0;
}