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

const ll primeLim = 1000000000ll; //10^9
ll prime_total; //total prime numbers less than primeLim
//ll pList[primeLim]; //pList[i] = (i)th prime ex> primes[0] = 2
bool isPrime[primeLim];
int pList[primeLim];
ll ans;

void initPrime();
ll rec(ll,int,int);
ll getNumFac(ll);
void process();

int main()
{
    int T;
    cin>>T;
    
//cout<<"program start"<<endl;
    initPrime();
    
    for(int idx=1;idx<=T;idx++)
    {
        process();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    return 0;
}

void initPrime()
{
	//cout<<"init start"<<endl;
    //bool isPrime[primeLim];
//bool isPrime[10];
//cout<<"YO"<<endl;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    
    ll cap = (ll)sqrt(primeLim);
    
    for(ll i = 2ll; i <= cap; i++)
        if(isPrime[i])
            for(ll k = i*i; k < primeLim; k += i)
                isPrime[k] = false;
    
//cout<<"isPrime done"<<endl;
    prime_total = 0;
    pList[prime_total++] = 2;
    
    for(ll i = 3ll; i < primeLim; i++)
        if(isPrime[i])
            pList[prime_total++] = i;

//cout<<"initPrime done"<<endl;
}

ll getNumFac(ll N)
{
    if(N == 1) return 1ll;
    
    ll ans = 1ll;
    for(ll i = 0; 1 < N && i < prime_total; i++)
    {
        ll cur = 1ll;
        while(N % pList[i] == 0)
        {
            N /= pList[i];
            cur++;
        }
        ans *= cur;
    }
    
    if(ans == 1) return 2ll;
    return ans;
    
}

int numPrime(int a, int b)
{
    return max( 0, int(upper_bound(pList, pList + prime_total, b) - upper_bound(pList, pList + prime_total, a - 1)) );
}

/*
 Returns total number of numbers that satisfy below conditions
 1) 2 <= X <= N
 2) pList[pos] <= smallest factor of X
 3) numFac = number of factors of X
*/
ll rec(ll N, int pos, int numFac)
{
	//cout<<"rec( "<<N<<" , "<<pos<<" , "<<numFac<<")"<<endl;
	
	if(numFac == 1) return 1;
	
    if(numFac == 2) return numPrime(pList[pos], int(N));
    
//if(pos == prime_total) return 0;
    if(N < pList[pos]) return 0;
	
    ll res = 0;
    /*
     Let P = pList[pos] = the smallest prime available.
     Try using P. "i" represnts how many P we will use.
     Also note that since next call is (pos + 1), 
     so next prime used is larger than P. 
	(Try exploiting this fact
     to speed up the process by not calling rec in certain cases)
	IF we use "i" number of P now, we need to have 
	(numFac/(i+1)) primes later.
     */
	ll powPrime = pList[pos];
    for(int i=1; i < numFac; i++)
    {
        if(numFac % (i+1) != 0)
            continue;
        int nextFac = numFac / (i+1);
        int nextN = N / powPrime;
//cout<<endl;
//cout<<N<<" / "<<powPrime<<endl;
		powPrime *= pList[pos];
        

        if(N < powPrime) break;
        if(nextFac > 1 && nextN < pList[pos+1])
            break;
    //    cout<<N<<" / "<<powPrime<<endl;
        res += rec(nextN, pos + 1, nextFac);
//cout<<endl;
    }
    
    //do not use P
    res += rec(N, pos + 1, numFac);
    
    return res;
}

/*
 Find a number of A that satisfy following conditions
 1) 2 <= A < N
 2) Number of factors of A == Number of factors of N
 3) M <= smallest factor of A
 */
void process()
{
    ll N,M;
    cin>>N>>M;
    
    ll numFac = getNumFac(N);
    ll pos = lower_bound(pList, pList + prime_total, M) - pList; 
    
//cout<<"numFac : "<<numFac<<endl;
//cout<<"pos : "<<pos<<endl;
	if(numFac == 2 || M*M >= N) 
	{
		/*
		N is a prime, so N's sisters are also primes.
		All primes do not have a brother. So M does not exist for primes.
		*/
		ans = 0; 
	}else
	{
		ans = rec(N-1, pos, numFac);
	}
    
}