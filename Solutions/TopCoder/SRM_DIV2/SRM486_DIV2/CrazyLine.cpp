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
 
class CrazyLine {
public:
	int maxCrazyness(vector <int>);
};

int CrazyLine::maxCrazyness(vector <int> H) {
	
    int N = H.size();
    if(N == 1) return 0;
    if(N == 2) return abs(H[0] - H[1]);
    
    sort(H.begin(), H.end());
    
    if(N%2 == 0)
    {
        int small = N/2 - 1;
        int big = N/2;
        int res = H[big++] - H[small--];
        while(0 <= small)
            res -= 2 * H[small--];
        while(big < N)
            res += 2 * H[big++];
        return res;
    }
    //N%2 == 1
    int small = N/2;
    int big = N/2+1;
    int res1 = 0;
    res1 -= H[small] + H[small-1];
    small -= 2;
    while( 0 <= small)
        res1 -= 2 * H[small--];
    while(big < N)
        res1 += 2 * H[big++];
    
    small = N/2 - 1;
    big = N/2;
    int res2 = 0;
    res2 += H[big] + H[big+1];
    big += 2;
    while( 0 <= small)
        res2 -= 2 * H[small--];
    while(big < N)
        res2 += 2 * H[big++];
    
    return max(res1, res2);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	CrazyLine *obj;
	int answer;
	obj = new CrazyLine();
	clock_t startTime = clock();
	answer = obj->maxCrazyness(p0);
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
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {5,10,25,40,25};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 100;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {2,3,5,7,11,13,17,19};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 82;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,1,1,1,1,1,501};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
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
