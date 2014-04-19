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

 //a and b cannot both be 0
ll GCD(ll a, ll b)
{
	if(b==0) return a;
	return GCD(b, a%b);
}
   
class FractionInDifferentBases {
public:
	long long getNumberOfGoodBases(long long, long long, long long, long long);
};

long long FractionInDifferentBases::getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
    //Make P/Q to an irreducible fraction
    ll g = GCD(P,Q);
    Q /= g;
    
    ll mul = 1ll;
    for(ll i=2ll; i*i <= Q; i+=1ll)
        if(Q%i == 0)
        {
            mul *= i;
            while(Q%i == 0)
                Q/= i;
        }

    if(Q > 1) mul *= Q;
    return (B-A+1ll) - (B/mul - (A-1ll)/mul);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, long long p1, long long p2, long long p3, bool hasAnswer, long long p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	FractionInDifferentBases *obj;
	long long answer;
	obj = new FractionInDifferentBases();
	clock_t startTime = clock();
	answer = obj->getNumberOfGoodBases(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	long long p2;
	long long p3;
	long long p4;
	
	{
	// ----- test 0 -----
	p0 = 1ll;
	p1 = 2ll;
	p2 = 10ll;
	p3 = 10ll;
	p4 = 0ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1ll;
	p1 = 9ll;
	p2 = 9ll;
	p3 = 10ll;
	p4 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5ll;
	p1 = 6ll;
	p2 = 2ll;
	p3 = 10ll;
	p4 = 8ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2662ll;
	p1 = 540ll;
	p2 = 2ll;
	p3 = 662ll;
	p4 = 639ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 650720ll;
	p1 = 7032600ll;
	p2 = 2012ll;
	p3 = 2012540ll;
	p4 = 2010495ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
