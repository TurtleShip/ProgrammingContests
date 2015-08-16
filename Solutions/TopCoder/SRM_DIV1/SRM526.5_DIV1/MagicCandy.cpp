#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
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
 
class MagicCandy {
public:
	int whichOne(int);
};


//returns the position of 'n'th candy after eating
int eat(int n)
{
    return n - (int)sqrt(n);
}

//returns the position of 'n'th candy before eating
int prev(int n)
{
    /*
     We need to find a number such that n = eat(x)
     We know n = x - sqrt(x)
     We need to find x. Finding a formula is very hard,
     but we can guess.
     x = n + sqrt(x)
     so n <= x <= 2*n + 10 ( large enough number);
     */
    ll left = (ll)n;
    ll right = 2ll*(ll)n + 10ll;
    ll mid = (left + right)/2ll;
    while(left + 1 < right)
    {
        mid = (left + right)/2;
        int cur = eat(mid);
        if(cur == n)
            break;
        if(cur < n)
            left = mid;
        else
            right = mid;
    }
    return mid;
}

//computes how many steps are need to process n candies down to 0
int howMany(int n)
{
    int steps = 0;
    while(eat(n) != 0)
    {
        n = eat(n);
        steps++;
    }
    return steps;
}

int MagicCandy::whichOne(int n) {
	int cap = howMany(n);
    int ans = 1;

    REP(i,0,cap)
        ans = prev(ans);

    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	MagicCandy *obj;
	int answer;
	obj = new MagicCandy();
	clock_t startTime = clock();
	answer = obj->whichOne(p0);
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
	
	int p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 9;
	p1 = 7;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	p1 = 17;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5265;
	p1 = 5257;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 20111223;
	p1 = 20110741;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1;
	p1 = 1;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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