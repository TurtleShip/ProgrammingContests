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

const int maxN = 100001;
bool isPrime[maxN];
bool on[maxN];
int fac[maxN]; //factors
set<int> eachFac[maxN]; //factors of each number
int N;
int M;
void fillPrimes();
void fillFac();
int turnOn(int);
void turnOff(int);

int main()
{
    cin>>N>>M;
    
    memset(on, false, sizeof(on));
    memset(fac, 0, sizeof(fac));
    fillPrimes();
    fillFac();
    bool isNumber = false;
    bool activate = false;
    
    for(int m=0; m < M*2; m++)
    {
        if(isNumber)
        {
            int C;
            cin>>C;
            isNumber = false;
            if(activate)
            {
                if(on[C])
                    cout<<"Already on"<<endl;
                else
                {
                    int res = turnOn(C);
                    if(res == 0)
                    {
                        cout<<"Success"<<endl;
                        on[C] = true;
                    }
                    else
                        cout<<"Conflict with "<<res<<endl;
                }
                
            }
            else
            {
                if(on[C])
                {
                    turnOff(C);
                    on[C] = false;
                    cout<<"Success"<<endl;
                }
                else
                {
                    cout<<"Already off"<<endl;
                }
            }
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

void fillPrimes()
{
    //sieve of Eratostenes
    fill(isPrime, isPrime + N+1, true);
    
    isPrime[0] = isPrime[1] = false;
    int cap = (int)sqrt(N);
    for(int i=2; i <= cap; i++)
        if(isPrime[i])
            for(int k=i*i; k <= N; k +=i)
                isPrime[k] = false;
    
}

void fillFac()
{
    for(int i=2; i <= N; i++)
    {
        if(isPrime[i]) eachFac[i].insert(i);
        else
        {
            int num = i;
            while(num > 1)
            {
                if(num%2 == 0)
                {
                    eachFac[i].insert(2);
                    num/=2;
                }
                else
                {
                    int div = 3;
                    while(num % div != 0)
                        div+=2;
                    eachFac[i].insert(div);
                    num/=div;
                }
            }
        }
    }
}

int turnOn(int C)
{
    set<int> curFac = eachFac[C];
    if(isPrime[C])
    {
        if(fac[C]) return fac[C];
        fac[C] = C;
        return 0;
    }
    
    set<int>::iterator itr;
    for(itr = curFac.begin(); itr != curFac.end(); itr++)
        if(fac[(*itr)]) return fac[(*itr)];
    
    for(itr = curFac.begin(); itr != curFac.end(); itr++)
        fac[(*itr)] = C;
    
    return 0;
}

void turnOff(int C)
{
    set<int> curFac = eachFac[C];
    set<int>::iterator itr;
    for(itr = curFac.begin(); itr != curFac.end(); itr++)
        fac[(*itr)] = 0;
}