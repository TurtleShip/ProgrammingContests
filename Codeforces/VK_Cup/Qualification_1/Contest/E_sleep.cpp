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

struct Sleep
{
    int begin;
    int end;
    int len;
    Sleep(int b, int e)
    {
        begin = b;
        end = e;
        len = (e - b) + 1;
    }
};

struct Call
{
    int begin;
    int end;
    Call(int b, int e)
    {
        begin = b;
        end = e;
    }
};

bool sleepSort(Sleep a, Sleep b)
{
    return a.len > b.len;
}

int main()
{
    int maxTime = 86400;
    int N;
    int K;//number of calls that can be ignored
    cin>>N>>K;
    
    vector<int> St;
    vector<int> End;
    vector<Call> calls;
    vector<Sleep> sleeps;
    REP(i,0,N)
    {
        int t,d;
        cin>>t;
        cin>>d;
        St.push_back(t+d);
        End.push_back(t-1);
        calls.push_back( Call(t,t+d-1) );
    }
    
    St.push_back(1); //beginning of the day
    End.push_back(maxTime);//end of the day
    
    //Handle special cases
    if(N == 0 || K == N)
    {
        cout<<maxTime<<endl;
        return 0;
    }
    
    sort(St.begin(), St.end());
    
    for(int s=0; s < N+1; s++)
        for(int e=0; e < N+1; e++)
        {
            if(End[e] <= St[s]) continue;
            sleeps.push_back( Sleep(St[s], End[e]) );
        }
    
    sort(sleeps.begin(), sleeps.end(), sleepSort);
    
    int S = sleeps.size();
    int C = calls.size();
    for(int i=0; i < S; i++)
    {
	cout<<"Sleep from "<<sleeps[i].begin<<" to "<<sleeps[i].end<<endl;
        bool valid = true;
        int ig = K;
        int work = 0;
        for(int j=0; j < C; j++)
        {
            int cS = calls[j].begin;
            int cE = calls[j].end;
            
            if(work > cS)
            {
                cS += work;
                cE += work; 
            }
            
            if( (sleeps[i].begin <= cE && cE <= sleeps[i].end) || (sleeps[i].begin <= cS && cS <= sleeps[i].end))
            {
                if(ig == 0)
                {
                    valid = false;
                    break;
                }
                else
                    ig--;
            }
            else if(work > calls[j].begin)
            {
                work += (calls[j].end - calls[j].begin + 1);
            }
        }
        if(valid)
        {
            cout<<sleeps[i].len<<endl;
            break;
        }
        
    }
    
        
        
    return 0;
}