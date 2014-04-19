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

//a and b cannot both be 0
int GCD(int a, int b)
{
    if(a == -1) return b;
	if(b==0) return a;
	return GCD(b, a%b);
}

vector<bool> sieve(int n)
{
	vector<bool> primes(n+1);
	fill(primes.begin(), primes.end(), true);
	primes[0] = false;
	primes[1] = false;
	int m = (int)sqrt(n);
	
	for(int i=2; i <=m; i++)
		if(primes[i])
			for(int k= i*i; k <= n; k+=i)
				primes[k] = false;
	
	return primes;
}

int main()
{
    string suc = "Success";
    string aOn = "Already on";
    string conflict = "Conflict with ";
    string aOff = "Already off";
    
    int N,M;
    
    cin>>N;
    cin>>M;
    
    vector<int> onList;
    bool on[N+1];
    int gcd = -1;
    vector<bool> primes = sieve(N);
    memset(on, false, sizeof(on));
    
    bool isNumber = false;
    bool act;
    
    for(int i=0; i < M*2; i++)
    {
        if(isNumber)
        {
            int num;
            cin>>num;
            if(act)
            {
                if(on[num])
                {
                    cout<<aOn<<endl;
                }
                else
                {
                    //turn it on
                    bool okay = true;
                    int conf = -1;
                    for(int j=0; j < onList.size(); j++)
                    {
                        if( GCD(num,onList[j]) != 1)
                        {
                            conf = onList[j];
                            okay = false;
                            break;
                        }
                    }
                    
                    if(okay)
                    {
                        on[num] = true;
                        onList.push_back(num);
                        cout<<suc<<endl;
                    }
                    else
                    {
                        cout<<conflict<<conf<<endl;
                    }
                }
               
            }
            else
            {
                if(on[num])
                {
                    //remove factors
                    vector<int>::iterator itr = onList.begin();
                    for(itr = onList.begin(); itr != onList.end(); itr++)
                    {
                        if( num == (*itr))
                        {
                            onList.erase(itr);
                            break;
                        }
                    }
                    on[num] = false;
                    cout<<suc<<endl;
                }
                else
                {
                    cout<<aOff<<endl;
                }
            }
            
            isNumber = false;
            
        }
        else
        {
            string test;
            cin>>test;
            if(test == "+")
                act = true;
            else act = false;
            isNumber = true;
        }
        
    }
    
    return 0;
}