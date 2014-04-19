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

ll N,A,B,C,D,E,F;
ll ans;

void process();

int main()
{
    int T;
	cin>>T;
    
    for(int idx=1; idx <=T; idx++)
    {
        process();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    return 0;
}

void process()
{
    bool chk = true;
    ans = 0;
    cin>>N>>A>>B>>C>>D>>E>>F;

    //vector<Bat> battle(9);
    ll battle[3][3];
    for(int i=0; i < 3; i++)
    {
        for(int j=0; j < 3; j++)
        {
            cin>>battle[i][j];
        }
    }
    
    
    for(ll AD = 0; AD <= A; AD++)
    {
        for(ll AE = 0; AE <= (A-AD); AE++)
        {
            for(ll BD = 0; BD <= B; BD++)
            {
                for(ll BE = 0; BE <= (B-BD); BE++)
                {
                    for(ll CD = 0; CD <= C; CD++)
                    {
                        for(ll CE =0; CE <= (C-CD); CE++)
                        {
                            ll AF = A - AD - AE;
                            ll BF = B - BD - BE;
                            ll CF = C - CD - CE;
                            
                            if( (AD + BD + CD) != D || (AE + BE + CE) != E || (AF + BF + CF) != F )
                                continue;
           
                            ll cur = 0;
                            cur += battle[0][0] * AD;
                            cur += battle[0][1] * AE;
                            cur += battle[0][2] * AF;
                            
                            cur += battle[1][0] * BD;
                            cur += battle[1][1] * BE;
                            cur += battle[1][2] * BF;
                            
                            cur += battle[2][0] * CD;
                            cur += battle[2][1] * CE;
                            cur += battle[2][2] * CF;
                            
                            if(chk)
                            {
                                ans = cur;
                                chk = false;
                            }
                            
                            ans = max(ans,cur);

                        }
                    }
                    
                }
            }
        }
    }

}