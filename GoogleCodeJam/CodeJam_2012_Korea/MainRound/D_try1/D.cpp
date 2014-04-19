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

ll minmul[20001];
bool isPrime[primeLim];
ll pList[primeLim]; //pList[i] = (i)th prime, 0-based index. ex> pList[0] = 2 

ll pLen;

ll N;
ll M;
ll ans;


void initPrime();
void proceed();
ll rec(ll,ll,ll);
ll getNumFac(ll);
int main()
{
    //cout<<"Init start"<<endl;
    initPrime();
    
//cout<<"Init Done"<<endl;
   // cout<<"pLen : "<<pLen<<endl;
    int T;
    cin>>T;
    
    for(int idx=1; idx<=T; idx++)
    {
        proceed();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    return 0;
}

void proceed()
{
    cin>>N>>M;
    int pos = lower_bound( pList, pList + pLen, M) - pList;
    int nF = getNumFac(N);
    //cout<<"nF : "<<nF<<endl;
    if(nF == 2)
    {
        ans = 0;
    }
    else
    {
        ans = rec(1, pos,getNumFac(N));
    }
    
}

void initPrime()
{
   /* pLen = 0;
    pList[pLen++] = 2;
    pList[pLen++] = 3;
    for(ll cur = 5ll; cur < primeLim; cur+=2ll)
    {
        bool isValid = true;
        for(int i=1;  i < pLen && pList[i]*pList[i] < primeLim; i++)
        {
            if(cur % pList[i] == 0)
            {
                isValid = false;
                break;
            }
        }
        if(isValid)
            pList[pLen++] = cur;
    }
    */
    
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    
    ll cap = (ll)sqrt(primeLim);
    
    for(ll i = 2ll; i <= cap; i++)
        if(isPrime[i])
            for(ll k = i*i; k < primeLim; k += i)
                isPrime[k] = false;
    
    //cout<<"isPrime done"<<endl;
    pLen = 0;
    pList[pLen++] = 2;
    
    for(ll i = 3ll; i < primeLim; i++)
        if(isPrime[i])
            pList[pLen++] = i;
    
    
    for (int i = 2; i <= 20000; ++i) {
        minmul[i] = i - 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                if (minmul[i] > minmul[j] + minmul[i / j]) {
                    minmul[i] = minmul[j] + minmul[i / j];
                }
            }
        }
    }
}

ll rec(ll curN, ll pos, ll nF)
{
   // cout<<"rec("<<curN<<" , "<<pList[pos]<<" , "<<nF<<")"<<endl;
    if(nF == 1) return 1ll;
    
    //we can use one more prime number
    if(nF == 2)
    {
        ll maxM = ceil(N/curN);
        if(maxM == pList[pos]) return 0;
        //answer will be all primes such that pList[pos] <= prime < N/curN
        ll ans =  max(0, int(upper_bound(pList, pList + pLen, maxM) - lower_bound(pList, pList + pLen, pList[pos]) ) );
    //    cout<<"maxM : "<<maxM<<" , ans : "<<ans<<endl;
        return ans;
    }
    
    ll res = 0;
    
    for(ll i=1, curPrime = pList[pos]; i < nF; i++, curPrime *= pList[pos])
    {
        //we use (i) number of current prime
        if( nF % (i+1) != 0) continue;
        if(curN * curPrime >= N) break;
        res += rec(curN * curPrime, pos+1, nF/(i+1));
    }
    
    /*
     Do not use prime pList[pos].
     If next prime is small enough, move on to the next prime.
     Else, do not proceed any further
     */
    if( curN * pow((double)pList[pos+1], (int)minmul[nF]) < N)
    {
        res += rec(curN, pos+1, nF);
    }
    
    return res;
}

ll getNumFac(ll num)
{
    ll ans = 1;
   // cout<<"Handling "<<num<<endl;
    int iLim = upper_bound(pList, pList + pLen, sqrt(num) ) - pList;
    iLim++;
  //  cout<<"iLim : "<<iLim<<" , and its element : "<<pList[iLim]<<endl;
    for(int i=0; 1 < num && i <= iLim; i++)
    {
        ll cur = 1ll;
        bool chk = (num % pList[i] == 0);
        while(num % pList[i] == 0)
        {
            num /= pList[i];
            cur++;
        }
       // if(chk)
        //{
            //cout<<pList[i]<<" is a factor. cur : "<<cur<<endl;
        //}
        ans *= cur;
    }
    if(ans == 1) return 2;
    return ans;
}