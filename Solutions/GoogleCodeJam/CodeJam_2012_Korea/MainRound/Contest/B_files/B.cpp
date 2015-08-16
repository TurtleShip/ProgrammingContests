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
#define F first;
#define S second;
#define MP make_pair;
#define PB push_back;

typedef long long ll;
typedef pair<int,int> PII;
double ans = 0;
int board[10][10];
int N,M,K,s4,s3,s2;

void process();

int main()
{
    int T;
    cin>>T;
    
    for(int i=1; i <=T; i++)
    {
        process();
        cout.precision(15);
        cout<<fixed<<"Case #"<<i<<": "<<ans<<endl;
        
    }
    
    return 0;
}

void process()
{
    cin>>N>>M>>K>>s4>>s3>>s2;
    
    vector< pair<int,int> > ques;
    
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < M; j++)
        {
            char cur;
            cin>>cur;
            board[i][j] = (cur == '?') ? 0 : (cur - '0');
            if(cur == '?')
            {
                ques.push_back( make_pair(i,j) );
            }
        }
    }
    
    int sum = 0;
    int poss = pow((double)ques.size() , K);
    int Q = ques.size();
    for(int i=0; i <= poss; i++)
    {
        //int conf = toDecimal(i, K);
        int conf = i;
        
        for(int j=0; j < Q; j++)
        {
            int cur = conf % K + 1;
            conf /= K;
            board[ ques[j].first ][ ques[j].second ] = cur;
        }
        
        /* print board
        for(int r=0; r < N; r++)
        {
            for(int c= 0; c< M; c++)
            {
                cout<<board[r][c]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
        
        
        
    }
    
    ans = double(sum) / double(poss);
}

int getSum()
{
    
}

