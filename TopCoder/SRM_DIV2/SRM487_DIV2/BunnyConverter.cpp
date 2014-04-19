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
 
class BunnyConverter {
public:
	int getMinimum(int, int, int, int);
};

int BunnyConverter::getMinimum(int n, int z, int start, int goal) {
	
    ll zz = (ll)z;
    int z3 =  (zz * zz * zz) % ( (ll)n);

    bool vis[n+1];
    memset(vis, false, sizeof(vis));
    
    int steps = 0;
    queue<ll> Q;
    Q.push(ll(goal));
    Q.push(steps);
    
    while(!Q.empty())
    {
        ll x = Q.front(); Q.pop();
        ll s = Q.front(); Q.pop();
        
        if(x == start) return s;
        if(vis[x]) return -1;
        
        vis[x] = true;
        
        x = ( n - ( (x*x)%n + z3)%n ) % n;
        if(x == 0) x = n;
        Q.push(x);
        Q.push(s+1);
    }
    
    return -1;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	BunnyConverter *obj;
	int answer;
	obj = new BunnyConverter();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0, p1, p2, p3);
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
	
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 1;
	p2 = 5;
	p3 = 3;
	p4 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 5;
	p1 = 1;
	p2 = 5;
	p3 = 1;
	p4 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	p1 = 2;
	p2 = 3;
	p3 = 4;
	p4 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 7;
	p1 = 7;
	p2 = 7;
	p3 = 7;
	p4 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 499979;
	p1 = 499979;
	p2 = 499976;
	p3 = 3;
	p4 = 249988;
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
