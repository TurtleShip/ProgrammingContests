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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// dp[i] = sum of r(1,j) where 2 <= j <= i
double dp[100010];
double w;

void preprocess() {
    dp[1] = 0.0;
    double curH = 1.0;
    for(int i=2; i <= 100000; i++) {
        dp[i] = dp[i-1] + sqrt(w*w + curH*curH);
        curH += 1.0;
    }
}

class Pillars {
public:
	double getExpectedLength(int _w, int _x, int _y) {
        double res = 0.0;
        double x = double(_x);
        double y = double(_y);
        if(_x > _y) swap(_x,_y);
        w = _w;
        preprocess();
        
        for(int i=1; i <= _x; i++)
            res += dp[i] + w + dp[_y-i+1];
		
        return res/x/y;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	Pillars *obj;
	double answer;
	obj = new Pillars();
	clock_t startTime = clock();
	answer = obj->getExpectedLength(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
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
	double p3;
	
	{
        // ----- test 0 -----
        p0 = 1;
        p1 = 1;
        p2 = 1;
        p3 = 1.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
	}
	
	{
        // ----- test 1 -----
        p0 = 1;
        p1 = 5;
        p2 = 1;
        p3 = 2.387132965131785;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
	}
	
	{
        // ----- test 2 -----
        p0 = 2;
        p1 = 3;
        p2 = 15;
        p3 = 6.737191281760445;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
	}
	
	{
        // ----- test 3 -----
        p0 = 10;
        p1 = 15;
        p2 = 23;
        p3 = 12.988608956320535;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
