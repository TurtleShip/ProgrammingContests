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

ll GCD(ll a, ll b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}

int main()
{
    int N; //the number of collidors
    int M; //the number of requests
    
    cin>>N>>M;
    ll total = 1ll;
    bool on[N+1];
    memset(on, false, sizeof(on));
    
    
    bool isNumber = false;
    bool activate = false;
    for(int m=0; m < M*2; m++)
    {
        if(isNumber)
        {
	cout<<"total : "<<total<<endl;
            int C;
            cin>>C;
            if(activate)
            {
                if(on[C]) cout<<"Already on"<<endl;
                else
                {
                    if(GCD(total, C) == 1)
                    {
                        total *= (ll)C;
                        on[C] = true;
                        cout<<"Success"<<endl;
                    }
                    else
                    {
                        //find conflict
                        int j = 0;
                        for(int i=1; i <= N; i++)
                        {
                            if(on[i] && GCD(i,C) != 1)
                            {
                                j = i;
                                break;
                            }
                        }
                        cout<<"Conflict with "<<j<<endl;
                    }
                }
            }
            else
            {
                if(!on[C]) cout<<"Already off"<<endl;
                else
                {
                    total /= (ll)C;
                    on[C] = false;
                    cout<<"Success"<<endl;
                }
                
            }
            
            isNumber = false;
        }
        else
        {
            char sign;
            cin>>sign;
            activate = (sign == '+');
            
            isNumber = true;
        }
        
    }
    
    return 0;
}