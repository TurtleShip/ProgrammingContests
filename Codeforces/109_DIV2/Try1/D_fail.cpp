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

int prime[100001];
bool on[100001];
int GCD(int , int);
int turnOn(int);
void turnOff(int);

int main()
{
    int N; //the number of collidors
    int M; //the number of requests
    
    cin>>N>>M;

    memset(prime, 0, sizeof(prime));
    memset(on, 0, sizeof(on));


    bool isNumber = false;
    bool activate = false;
    for(int m=0; m < M*2; m++)
    {
        if(isNumber)
        {

            int C;
            cin>>C;
            if(activate)
            {
                if(on[C]) cout<<"Already on"<<endl;
                else
                {
                    int chk = turnOn(C);
                    if(chk == -1)
                    {
                        on[C] = true;
                        cout<<"Success"<<endl;
                    }
                    else
                    {
                        cout<<"Conflict with "<<chk<<endl;
                    }
                }
            }
            else
            {
                if(!on[C]) cout<<"Already off"<<endl;
                else
                {
                    on[C] = false;
                    turnOff(C);
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

int GCD(int a, int b)
{
    if(b == 0) return a;
    return GCD(b, a%b);
}

int turnOn(int num)
{
	int ori = num;
    set<int> curFac;
    
    while(num > 1)
    {
        if(num%2 == 0)
        {
            if(prime[2]) return prime[2];
            curFac.insert(2);
            num /= 2;
        }
        else
        {
            int div = 3;
            while(num%div != 0)
                div+=2;
            
            if(prime[div]) return prime[div];

            curFac.insert(div);
            num /= div;
        }
    }
    
    set<int>::iterator itr;
    for(itr = curFac.begin(); itr != curFac.end(); itr++)
        prime[(*itr)] = ori;
    
    return -1;
}

void turnOff(int num)
{
    while(num > 1)
    {
        if(num%2 == 0)
        {
            prime[2] = 0;
            num /= 2;
        }
        else
        {
            int div = 3;
            while(num % div != 0)
                div += 2;
            
            prime[div] = 0;
            num /= div;
        }
    }
}
