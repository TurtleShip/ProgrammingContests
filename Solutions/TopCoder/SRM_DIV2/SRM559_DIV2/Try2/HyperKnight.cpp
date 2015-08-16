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
 
class HyperKnight {
public:
	long long countCells(int, int, int, int, int);
};

ll exactNum[256];

long long HyperKnight::countCells(int ia, int ib, int inumRows, int inumColumns, int k) {
	
    
    ll a = (ll)ia;
    ll b = (ll)ib;
    ll nR = (ll)inumRows;
    ll nC = (ll)inumColumns;
    ll dr[8] = {-a,-b,b,a,-a,-b,b,a};
    ll dc[8] = {-b,-a,-a,-b,b,a,a,b};
    ll res = 0ll;
    
    /* There are 8 possible moves, and 2^8 = 256 possible combination of moves,
     where 0 means no move and 255 means all moves. */
    for(int mask = 255; mask >= 0; mask--) {
        ll ndr = 0ll; //negative dr
        ll pdr = 0ll; //positive dr
        ll ndc = 0ll; //negative dc
        ll pdc = 0ll; //positive dc
        int curValid = 0;
        for(int i=0; i < 8; i++) {
            if(mask & 1<<i) {
                if(dr[i] < 0) ndr = max(ndr, -dr[i]);
                else pdr = max(pdr, dr[i]);
                if(dc[i] < 0) ndc = max(ndc, -dc[i]);
                else pdc = max(pdc, dc[i]);
                curValid++;
            }
        }
        ll curArea = (nR - ndr - pdr) * (nC - ndc - pdc);
        for(int superMask = mask+1; superMask <= 255; superMask++) {
            if( (superMask & mask) == mask)
                curArea -= exactNum[superMask];
        }
        exactNum[mask] = curArea;
        if(curValid == k) res += curArea;
    }
  
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	HyperKnight *obj;
	long long answer;
	obj = new HyperKnight();
	clock_t startTime = clock();
	answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	long long p5;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 1;
	p2 = 8;
	p3 = 8;
	p4 = 4;
	p5 = 20ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 8;
	p3 = 8;
	p4 = 2;
	p5 = 16ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 3;
	p2 = 7;
	p3 = 11;
	p4 = 0;
	p5 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 2;
	p2 = 10;
	p3 = 20;
	p4 = 8;
	p5 = 56ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	p1 = 4;
	p2 = 100;
	p3 = 10;
	p4 = 6;
	p5 = 564ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 2;
	p1 = 3;
	p2 = 1000000000;
	p3 = 1000000000;
	p4 = 8;
	p5 = 999999988000000036ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
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