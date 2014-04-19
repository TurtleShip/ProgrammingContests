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

struct Student
{
    int time;
    int loc;
    int id;
};

const int maxS = 100100;
Student stu[maxS];
ll ans[maxS];

bool sortByLoc(Student a, Student b)
{
    return a.loc < b.loc;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int S,P;
    cin>>S>>P;
    
    for(int i=0; i < S; i++)
    {
        cin>>stu[i].time;
        cin>>stu[i].loc;
        stu[i].id = i;
    }

    ll curTime = 0LL;
    int idx = 0;
    while(idx < S)
    {
        int last = min(idx + P - 1, S - 1);
        //The bus leaves when the last student arrives
        curTime = max(curTime, ll(stu[last].time));

        //The bus drops off student who lives closer to 0 first
        sort(stu + idx, stu + (last + 1), sortByLoc);

        int prevStop = 0;
        while(idx <= last)
        {
            int k = 0;
            int curStop = stu[idx].loc;
            curTime += (curStop - prevStop);
            while(idx<= last && stu[idx].loc == curStop)
            {
				ans[stu[idx].id] = curTime;
                idx++;
                k++;
            }
            prevStop = curStop;
            curTime += 1LL + (k/2);
        }
        
        //The bus goes back to position 0
        curTime += stu[idx-1].loc;
    }
    
    
    cout<<ans[0];
    for(int i=1; i < S; i++)
        cout<<" "<<ans[i];
    cout<<endl;
    
    return 0;
}