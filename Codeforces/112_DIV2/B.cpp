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
int N;
ll K;

bool getN(ll);

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>N>>K;
    
    /*
     Initial guess
     V = N  
     */
    int up = N;
    int bot = 1;
int guess = -1;
    while(true)
    {
        guess = (up + bot) / 2;
        bool chk1 = getN(guess-1);
        bool chk2 = getN(guess);
        
        if( !chk1 && chk2) break;
        
        if(chk2)
        {
            up = guess;
        }
        else
        {
            bot = guess;
        }
        
    }
    
    
    
    cout<<(guess)<<endl;
    return 0;
}

bool getN(ll V)
{
    ll res = V;
    ll mul = K;
    while(res < N && mul <= V)
    {
        res += ceil(V / mul);
        mul *= K;
    }
    
    return res >= N;
}