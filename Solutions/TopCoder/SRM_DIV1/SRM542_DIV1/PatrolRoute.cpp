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

typedef long long ll; 

class PatrolRoute {
public:
	int countRoutes(int X, int Y, int minT, int maxT);
};

ll mod = 1000000007ll;

ll xTime[5000];
ll ySum[5000];

int PatrolRoute::countRoutes(int _X, int _Y, int minT, int maxT) {
    
    ll X = ll(_X);
    ll Y= ll(_Y);
    ll res = 0ll;
    
    for(ll i = 2ll; i < X; i++) {
        xTime[int(i)] = (X - i) * (i - 1);
    }
    
	ySum[0] = ySum[1] = 0ll;
    
    for(ll i = 2ll; i < Y; i++) {
        ySum[(int)i] = (ySum[(int)i-1] + ((Y-i) * (i-1)) % mod);
    }
    
    for(ll x = 2ll; x < X; x++) {
        
        ll minY = max( (minT+1-2*x) / 2 , 2ll);
        ll maxY = min( (maxT - 2*x) / 2 , Y-1);
        if(maxY < 2) break; // not possible anymore
        if(maxY < minY) continue; // need to increase X
        
        res = (res + xTime[x] * (ySum[maxY] - ySum[minY-1] + mod) % mod ) % mod;
    }
    res = (res * 6ll) % mod;
    return res;
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	PatrolRoute *obj;
	int answer;
	obj = new PatrolRoute();
	clock_t startTime = clock();
	answer = obj->countRoutes(p0, p1, p2, p3);
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
	p0 = 3;
	p1 = 3;
	p2 = 1;
	p3 = 20000;
	p4 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 3;
	p2 = 4;
	p3 = 7;
	p4 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 6;
	p2 = 9;
	p3 = 12;
	p4 = 264;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 7;
	p1 = 5;
	p2 = 13;
	p3 = 18;
	p4 = 1212;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 4000;
	p1 = 4000;
	p2 = 4000;
	p3 = 14000;
	p4 = 859690013;
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
