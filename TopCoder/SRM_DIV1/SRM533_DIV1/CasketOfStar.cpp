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

class CasketOfStar {
public:
	int maxEnergy(vector <int> weight);
};

int dp[55][55];
vector<int> V;

/*
 solve(s,t) returns the maximum energy that can be gained
 from V[s]...V[t], inclusive
 */
int solve(int s, int t) {
    if(dp[s][t] != -1) return dp[s][t];
    
    // we only have two element. This is the end
    if((s+1) == t) return 0;
    
    /*
     Let's say that the position of last element we delete is "last"
     Then we know that the energy will include V[s]*V[t] at its last iteration.
     More importantly, maximum sequence needs to V[last] until its last iteration.
     In other words, we can think {V[s] .. V[last]} and {V[last] .. V[t]} separately
     since V[last] won't be erased until the last iteration and therefore 
     act as "boundary" for both sides.
     */
    int res = 0;
    // pick the last element to delete
    for(int last = s + 1; last < t; last++)
        res = max(res, solve(s,last) + solve(last, t));
    
    res += V[s] * V[t];
    dp[s][t] = res;
    return res;
}

int CasketOfStar::maxEnergy(vector <int> weight) {
    V = weight;
	memset(dp, -1, sizeof(dp));
    return solve(0, V.size() - 1);
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
	CasketOfStar *obj;
	int answer;
	obj = new CasketOfStar();
	clock_t startTime = clock();
	answer = obj->maxEnergy(p0);
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
	int t0[] = {1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 12;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {100,2,1,3,100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10400;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {2,2,7,6,90,5,9};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1818;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {477,744,474,777,447,747,777,474};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2937051;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 13;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
