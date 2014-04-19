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

const int maxCh = 26; //number of charactersr
const int OFFSET = 30;
//int mod = 1000000007;
ll mod = 100000000000ll;
int N;
int arr[100];
int mem[100][26][100];

int rec(int,int,int);

int main()
{
    int T;
    cin>>T;
    
    for(int t=0; t<T; t++)
    {
		string str;
        cin>>str;
        N = str.size();
		
        memset(mem, -1, sizeof(mem));
        if(N == 1)
        {
            cout<<0<<endl;
        }
        else
        {
            for(int i=0; i < N; i++)
            {
                arr[i] = (str[i] - 'a');
            }
            cout<<(rec(0,0,0) - 1)<<endl;
        }
    }
    
    
    return 0;
}

int rec(int idx, int prev, int diff)
{
    int& res = mem[idx][prev][diff+OFFSET];
    if(res != -1)
        return res;
    
    res = 0;
    if(idx == N-1)
    {
        if( 0 <= (diff + arr[idx]) && (diff+ arr[idx]) < maxCh)
            res = 1;
        return res;
    }
    else
    {
        int val = arr[idx] + diff;
        if(val < 0 || val >= maxCh) return 0;
        
        for(int i=0; i < val; i++)
        {
            res = (res + rec(idx+1, i, val - i)) % mod;
        }
        for(int i = val + 1; i < maxCh; i++)
        {
            res = (res + rec(idx+1, i, val - i)) % mod;
        }
        
        //if(val == arr[idx])
        res = (res + rec(idx+1, val, 0)) % mod;

    }
    return res;
}