#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

// Maximum Number ,10^9
#define MAXNUM 1000000000
// MAXNUM2 = MAXNUM/2
#define MAXNUM2 500000000
// SQRTMAXNUM = SQRT(MAXNUM)
#define SQRTMAXNUM 31622
// SQRTMAXNUM2 = SQRT(MAXNUM)/2
#define SQRTMAXNUM2 15811
// ARRAYSIZE = MAXNUM/2/32 + 1
#define ARRAYSIZE MAXNUM/2/32 + 1
#define MAXM 316227766

#define getbit(n) (prime[((n)>>5)]&(1<<((n)&0x1F)))
#define setbit(n) (prime[((n)>>5)]|=(1<<((n)&0x1F)))

// isPrime() MACRO version
#define isPrime(n) (( (((n)&1) && !(getbit((n)>>1))) || ((n)==2)) ? 1 : 0)

unsigned int prime[ARRAYSIZE];
int p[51000000];
// MINimum MULtiplier
int minmul[20001];
int pn;

// 소수 구하는 부분
void initPrime() {
    setbit(0);
    for (int i = 1 ; i <= SQRTMAXNUM2 ; i++) {
        if (getbit(i) == 0) {
            for ( int j = ((i*i + i)<<1) ; j <= MAXNUM2 ; j += ((i<<1)|1))
                setbit(j);
        }
    }
    p[0] = 2;
    pn = 1;
    for (int i = 3; i < MAXNUM; i += 2) {
        if ( getbit((i - 1) / 2) == 0 ) {
            p[pn++] = i;
        }
    }
}

// 약수가 몇개인지 구하는 부분
int numDivisor(long long n) {
    int ret = 1;
    int maxi = sqrt(n * 1.0);
cout<<"maxi : "<<maxi<<endl;
    for (int i = 0; i <= maxi; ++i) {
        if (n % p[i] == 0) {
            int pp = 1;
            while (n % p[i] == 0) {
                n /= p[i];
                pp++;
            }
            ret *= pp;
        }
    }
    if (n != 1) ret *= 2;
    return ret;
}

// a 이상 b 이하의 소수의 개수를 구한다.
// 이미 p 배열에는 10^9 이하의 모든 소수가 순서대로 저장되어 있기 때문에
// upper_bound를 사용하면 ~O(lg n)만에 구할 수 있다.
int numPrime(int a, int b) {
    return max(0, int(upper_bound(p, p + pn, b) - upper_bound(p, p + pn, a - 1)));
}

// mpos는 앞으로 사용할 제일 작은 prime number의 index를 가지고 있다.
// nd는 약수의 개수를 의미한다.
long long find_sol(long long n, int mpos, int nd) {
    // n, mpos에 관계없이 nd = 1인 경우에는 답이 존재한다.
    if (nd == 1) return 1;
    // nd가 2인 경우에는 p[mpos] 이상 n 이하의 모든 소수가 답이 될 수 있다.
    if (nd == 2) return numPrime(p[mpos], (int)n);
    // p[mpos - 1] 이상의 소수를 사용하는 답은 존재하지 않는다.
    if (mpos == pn) return 0;
    
    long long ret = 0;
    // 만약 nd = 12인 경우 a^11, a^5 * b, a^3 * b^2, a^2 * b * c 등의 형태가 존재하는데,
    // a < b < c일 때 위의 4개의 경우 중 어떤 것을 고르더라도, a^4 보다는 크게 되기 때문에
    // x^4 <= n를 만족하는 x에 대해서 답을 구한다.
    int maxi = (int)(pow(n, 1.0 / minmul[nd]) + 1);
    for (int i = mpos; p[i] <= maxi; ++i) {
        long long t = 1;
        for (int j = 2; j <= nd; ++j) {
            // 주의: t * p[i]는 overflow가 날 수 있음
            if (t > n / p[i]) {
                break;
            }
            t = t * p[i];
            if (nd % j == 0) ret += find_sol(n / t, i + 1, nd / j);
        }
    }
    return ret;
}

int main() {
    initPrime();
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
    
    int T;
    cin >> T;
    
    long long n, m;
    for (int cn = 1; cn <= T; ++cn) {
        cin >> n >> m;
cout<<"Case #"<<cn<<" input : "<<"("<<n<<" , "<<m<<")"<<endl;
        int nd = numDivisor(n);
cout<<"Yo"<<endl;
        // n = 1 또는 소수이거나, m^2이 n 이상이면 무조건 답은 0
        if (n == 1 || nd == 2 || m * m >= n) {
            cout<<"Case #"<<cn<<": 0"<<endl;
        } else {
            // 입력 받은 m 이상의 제일 작은 소수의 위치를 찾음
            int mpos = lower_bound(p, p + pn, m) - p;
            long long ret = find_sol(n - 1, mpos, nd);
            
            cout<<"Case #"<<cn<<": "<<ret<<endl;
        }
    }
}