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

struct Call
{
    int begin;
    int end;
    int len;
    int idx;
    Call(int b, int e, int i)
    {
        begin = b;
        end = e;
        idx = i;
        len = end - begin + 1;
    }
};

bool callSortByEnd(Call a, Call b)
{
    if(a.end != b.end) return a.end < b.end;
    return a.begin < b.begin;
}


int main()
{
    int maxTime = 86400;
    int N;
    int K;//number of calls that can be ignored
    cin>>N>>K;
    vector<Call> St;
    vector<Call> End;
    REP(i,0,N)
    {
        int b,d;
        cin>>b>>d;
        St.push_back( Call(b,(b+d-1),i) );
    }
    
    int W[N];//W[i] = time that (i)th phone call ends if all previous calls were answered
    W[0] = St[0].end;
    
    for(int i=1; i < N; i++)
    {
        if( W[i-1] > St[i].begin)
        {
            W[i] = W[i-1] + St[i].len;
        }
        else
        {
            W[i] = St[i].begin + St[i].len - 1;
        }
           
    }
  /*  
REP(i,0,N)
cout<<"W["<<i<<"] : "<<W[i]<<endl;
    */
    if(N == 0 || N == K)
    {
        cout<<maxTime<<endl;
        return 0;
    }
    
    int ans = St[K].begin - 1; //begin ~ work start
    cout<<"Begin ans : "<<ans<<endl;
    End = St;
    sort(End.begin(), End.end(), callSortByEnd);
    ans = max(ans, maxTime - W[ End[N-1-K].idx ]  ); //work end ~ end of the day
   cout<<"idx : "<<End[N-1-K].idx<<endl;
    /*
     In between works.
     We need to pick 
     A = the earliest finishing phone call,
     B = the latest starting phone call,
     and cancel all phone calls in between.
     */
    
    for(int i=0; i < N; i++)
    {
        for(int j=N-1; j >= 0; j--)
        {
            if(End[i].idx < St[j].idx && ( (St[j].idx - End[i].idx - 1) <= K) )
            {
	cout<<"between "<<End[i].idx<<" and "<<St[j].idx<<endl;
                ans = max(ans, (St[j].begin-1) - (W[End[i].idx]+1) + 1);
            }
        }
    }
    cout<<ans<<endl;
        
        
    return 0;
}