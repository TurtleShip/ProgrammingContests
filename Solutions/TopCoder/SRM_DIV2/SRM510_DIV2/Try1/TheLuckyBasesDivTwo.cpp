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
 
class TheLuckyBasesDivTwo {
public:
	long long find(long long);
};

bool isLucky(ll num, ll base)
{
    while(num != 0)
    {
        if(num % base != 4 && num % base != 7)
            return false;
        num = num / base;
    }
    
    return true;
}

long long TheLuckyBasesDivTwo::find(long long n) {
    
    if(isLucky(n, n+1))
        return -1;
    
    /*
     Let's find out how many bases can produce lucky numbers out
     of n by using 2 digits.
     Let's say x is such a base.
     Then n = d0 + d1*x such that d0 and d1 are either 4 or 7
     x has to be bigger than d0 and d1.
     x = (n - d0) / d1
     So d1 has to be a multiple of d1 , and bigger than max(d0,d1)
     
     Possible candidates are  44,47,74,77
     */
    ll ans = 0;
    int d0[4] = {4ll,4ll,7ll,7ll};
    int d1[4] = {4ll,7ll,4ll,7ll};
    
    for(int i=0; i < 4; i++)
    {
        if( (n - d0[i]) % d1[i] == 0 && ((n - d0[i]) / d1[i]) > max(d0[i],d1[i]) )
            ans += 1ll;    
    }
    
    /*
     Now we will look for a base that make a lucky number whose length is
     equal to or bigger than 3.
     
     The smaller the base , the bigger the digit.
     The smaller the digit, the bigger the base.
     
     So smallest 3 digit number will be the biggest base.
     It will look like this
     n = d0 + d1*x + d2*x^2
     This digit will be the smallest when d0 == 0 , d1 == 0, d2 == 1,
     which will be (100)base x.
     n = x^2.
     So biggest base x = sqrt(n).
     
     Let's make it better by finding smallest 3-digit number that is actually lucky.
     => 444
     n = 4 + 4*x + 4*x^2
     
     Difficult to solve...
     How about 400, number before 444.
    n = 0 + 0*x + 4*x^2
     x^2 = n/4
     x = sqrt(n/4);
     */
    for(ll b = 2ll; b <= sqrt(n/4); b+=1ll)
        if(isLucky(n,b))
            ans+=1ll;
    
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TheLuckyBasesDivTwo *obj;
	long long answer;
	obj = new TheLuckyBasesDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	long long p0;
	long long p1;
	
	{
	// ----- test 0 -----
	p0 = 255ll;
	p1 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4ll;
	p1 = -1ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 13ll;
	p1 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 60ll;
	p1 = 2ll;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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