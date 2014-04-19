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

class VocaloidsAndSongs {
public:
	int count(int S, int gumi, int ia, int mayu);
};
int dp[51][51][51][51];
int mod = 1000000007;

int VocaloidsAndSongs::count(int S, int gumi, int ia, int mayu) {

	// base cases
	for(int s = 0; s <= S; s++)
		for(int a=0; a <= gumi; a++)
			for(int b=0; b <= ia; b++)
				for(int c=0; c <= mayu; c++)
					dp[s][a][b][c] = 0;
	dp[0][0][0][0] = 1;

	for(int s=1; s <= S; s++)
		for(int a=0; a <= gumi; a++)
			for(int b=0; b <= ia; b++)
				for(int c=0; c<= mayu; c++) {
					if((a + b + c) == 0) continue;
					if(a > 0) {
						dp[s][a][b][c] += dp[s-1][a-1][b][c];
						dp[s][a][b][c] %= mod;
					}
					if(a > 0 && b > 0) {
						dp[s][a][b][c] += dp[s-1][a-1][b-1][c];
						dp[s][a][b][c] %= mod;
					}
					if(a > 0 && c > 0) {
						dp[s][a][b][c] += dp[s-1][a-1][b][c-1];
						dp[s][a][b][c] %= mod;
					}
					if(a > 0 && b > 0 && c > 0) {
						dp[s][a][b][c] += dp[s-1][a-1][b-1][c-1];
						dp[s][a][b][c] %= mod;
					}
					if(b > 0) {
						dp[s][a][b][c] += dp[s-1][a][b-1][c];
						dp[s][a][b][c] %= mod;
					}
					if(b > 0 && c > 0) {
						dp[s][a][b][c] += dp[s-1][a][b-1][c-1];
						dp[s][a][b][c] %= mod;
					}
					if(c > 0) {
						dp[s][a][b][c] += dp[s-1][a][b][c-1];
						dp[s][a][b][c] %= mod;
					}
				}

	return dp[S][gumi][ia][mayu];
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	VocaloidsAndSongs *obj;
	int answer;
	obj = new VocaloidsAndSongs();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3);
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
	p1 = 1;
	p2 = 1;
	p3 = 1;
	p4 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 3;
	p2 = 1;
	p3 = 1;
	p4 = 9;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 50;
	p1 = 10;
	p2 = 10;
	p3 = 10;
	p4 = 0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 18;
	p1 = 12;
	p2 = 8;
	p3 = 9;
	p4 = 81451692;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 50;
	p1 = 25;
	p2 = 25;
	p3 = 25;
	p4 = 198591037;
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
