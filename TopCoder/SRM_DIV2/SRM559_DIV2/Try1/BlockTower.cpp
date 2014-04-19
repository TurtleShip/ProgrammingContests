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
 
class BlockTower {
public:
	int getTallest(vector <int>);
};

int dp[55][55];
vector<int> V;
int N;
/*
 dp[i][j] = maximum tower height achieved when using [0...i] with j odd heights.
 */

int solve(int idx, int odd) {
   // printf("solve( %d , %d )", idx, odd);
    if(odd < 0) return nINF;
    int& res = dp[idx][odd];
   
    if(res != -1) return res;
    res = 0;
    
    if(idx == 0) {
        if(odd == 1) {
            if(V[idx] % 2 == 1) res = V[idx];
            else res = nINF;
        } else if(odd == 0) {
            if(V[idx] % 2== 0) res = V[idx];
            else res = 0;
        } else res = nINF;
    } else {
        if(V[idx] % 2 == 1) res = max( V[idx] + solve(idx-1, odd-1), solve(idx-1, odd));
        else {
            if(odd > 0) res = solve(idx-1,odd);
            else res = V[idx] + solve(idx-1, odd);
        }
    }
  //   printf("solve( %d , %d ) = %d\n", idx, odd,res);
    return res;
}

int BlockTower::getTallest(vector <int> vec) {
    V = vec;
    N = V.size();
    memset(dp, -1, sizeof(dp));
	
    int res = 0;
    for(int i=0; i <= N; i++) {
        res = max(res, solve(N-1, i));
    }
    return res;
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
	BlockTower *obj;
	int answer;
	obj = new BlockTower();
	clock_t startTime = clock();
	answer = obj->getTallest(p0);
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
	int t0[] = {4,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 11;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {7,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {48,1,50,1,50,1,48};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 196;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {49,2,49,2,49};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 147;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {44,3,44,3,44,47,2,47,2,47,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 273;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
