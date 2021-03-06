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
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class DivisibleSequence {
public:
	int count(int, int);
};

ll mod = 1000000009ll;

// A[0] = N
// A[i] % A[i+1] == 0

// number of prime factors
ll facts[55];

ll fastPow(ll a, ll b) {
    if( b == 0 ) return 1;
    
    ll sq = (a*a) % mod;
    ll res = fastPow( sq, b / 2ll);
    if(b % 2 != 0)
        res = (res * a) % mod;
    
    res %= mod;
    
    return res;
}
ll getCombi(ll n, ll k) {
//    ll res = n;
    
    /*for(ll i = 1ll; i <= (k-1ll); i+=1ll) {
        res *= n-i;
        res /= i;
        res %= mod;
    }*/
  /*  for(int i=0; i <= (k-1); i++) {
//        res = (res * (n-i)) % mod;
        res = (n-i);
        res /= (k-i);
        res %= mod;
    }*/
    ll res = 1ll;
    
    for(ll i = 1ll; i <= k; i++) {
        res = (res * n+k-i) % mod;
        res = res * fastPow(i, mod-2) % mod;
    }

    printf("n = %lld\n", n);
    printf("k = %lld\n", k);
    printf("res = %lld\n\n", res);
       return res;
}

int DivisibleSequence::count(int N, int _seqLen) {
	ll seqLen = _seqLen;
    if(seqLen == 1) return 1;
    
    int primeLen = 0;
    int num = N;
    ll res = 1ll;
    for(int i=2; i * i <= num; i++) {
        if(num % i == 0) {
            printf("Factor %d : %d\n", primeLen, i);
            facts[primeLen] = 0;
            while(num % i == 0) {
                num /= i;
                facts[primeLen]++;
            }
            primeLen++;
        }
    }
    if(num != 1) printf("Factor %d : %d\n", primeLen, num);
    
    if(num != 1) facts[primeLen++] = 1;
//    printf("prime length : %d\n",primeLen);
    for(int i=0; i < primeLen; i++) {
//        printf("facts[%d] = %d\n", i, facts[i]);
        res = (res * getCombi(seqLen, facts[i])) % mod;
    }
    
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	DivisibleSequence *obj;
	int answer;
	obj = new DivisibleSequence();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 3;
	p2 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 6;
	p1 = 3;
	p2 = 9;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	p1 = 2;
	p2 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1;
	p1 = 10000;
	p2 = 1;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 30;
	p1 = 4;
	p2 = 64;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 25883;
	p1 = 100000;
	p2 = 991000009;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
