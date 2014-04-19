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
 
class SRMCodingPhase {
public:
	int countScore(vector <int>, vector <int>, int);
};

int SRMCodingPhase::countScore(vector <int> points, vector <int> skills, int luck) {
    
    int timePenalty[3] = {2,4,8};
    
    /*
     This is a greedy approach. There are 8 possible combination of solvable problems.
     For each solvable problem, we can spend x point of luck to save x minutes.
     Problem #1 costs 2 points per sec, 
     Problem #2 costs 4 points per sec,
     problem #3 costs 8 points per sec.
     So for a give possible solution, it would be wise to save as many minute as possible
     from #3 to #1.
     */
    int ans = 0;
    for(int mask = 1; mask < (1<<3); mask++)
    {
        vector<bool> use(3,false);
        for(int i=0; i < 3; i++)
        {
            if(mask & (1<<i)) use[i] = true;
        }
        
        int time = 0;
        REP(i,0,3)
            if(use[i]) time += skills[i];
        
        if( (time - luck) > 75) continue;
        
        int curPoint = 0;
        int curLuck = luck;
        for(int i=2; i >=0; i--)
        {
            if(use[i])
            {
                int luckSpent = min(curLuck, skills[i] - 1);
                curPoint += points[i] - timePenalty[i] * (skills[i] - luckSpent);
                curLuck -= luckSpent;
            }
        }

        ans = max(ans, curPoint);
    }
    
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2;
	cout << "]" << endl;
	SRMCodingPhase *obj;
	int answer;
	obj = new SRMCodingPhase();
	clock_t startTime = clock();
	answer = obj->countScore(p0, p1, p2);
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
		res = answer == p3;
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
	vector <int> p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {250,500,1000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,25,40};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	p3 = 1310;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {300,600,900};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {30,65,90};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 25;
	p3 = 680;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {250,550,950};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10,25,40};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 75;
	p3 = 1736;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {256,512,1024};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {35,30,25};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	p3 = 1216;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {300,600,1100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {80,90,100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	p3 = 0;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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
