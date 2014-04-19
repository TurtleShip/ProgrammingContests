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
ll ans;
ll pascal[21][21];
int mod = 32749;
void process();
void combiPascal();
ll permu[21];
int main()
{
    int T;
    cin>>T;
    
    combiPascal();
    for(int idx=1; idx <=T; idx++)
    {
        process();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    return 0;
}


void process()
{
    int B,W,K,I;
    cin>>B>>W>>K>>I;
    
    ans = 1ll;
    int Low = (K-I+1);
    int Up = I-1;
    int BLim = min(B, I);
    int WLim = min(W, I);
    int BLow = min(B, Low);
    int WLow = min(W, Low);
    int BUp = min(B, Up);
    int WUp = min(W, Up);
    
    for(int BL=0; BL <= BLow; BL++)
    {
        for(int BH = 0; BH <= BUp; BH++)
        {
            
            int WL = Low - BL;
            int WH = Up - BH;
            if( WL > WLow || WH > WUp) continue;
            if( (WL+WH) > WLim || (BL + BH) > BLim) continue;
            if( (
            
            if(! (BL == BLim || WL == WLim) ) continue; //I should be able to guess
            if( (BL+BH) == BLim || (WL + WH) == WLim)
            
            
            cout<<"BH : "<<BH<<endl;
            cout<<"WH : "<<WH<<endl;
            cout<<"BL : "<<BL<<endl;
            cout<<"WL : "<<WL<<endl;
            cout<<endl;
            ans = (ans * pascal[Low][BL]) % mod;
            ans = (ans * pascal[Up][BH]) % mod;
            
        }
    }

}


//makes pascal table. It can be used to get a combination.
//For example, pascal[10][5] is the same as number of ways to pick 5 items out of 10 items
void combiPascal()
{
	memset(pascal, 0, sizeof(pascal));
	
	pascal[0][0] = 1;
	for(int i=0; i <=20; i++)
		pascal[i][0] = 1;
	
	for(int i=1; i <= 20; i++)
		for(int j=1; j <= 20; j++)
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
}