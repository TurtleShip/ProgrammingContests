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
 
class PasswordXGrid {
public:
	int minSum(vector <string>, vector <string>);
};

const int maxN = 45;
int dp[maxN][maxN];
int vert[maxN][maxN];
int hori[maxN][maxN];

int PasswordXGrid::minSum(vector <string> H, vector <string> V) {

    int R = H.size();
    int C = H[0].size()+1;
    
    memset(dp, 0, sizeof(dp));
    memset(hori, 0, sizeof(hori));
    memset(vert, 0, sizeof(vert));
    
    for(int i=0; i < R; i++)
        for(int j=0; j < C-1; j++)
            hori[i][j] = H[i][j] - '0';
    
    for(int i=0; i < R-1; i++)
        for(int j=0; j < C; j++)
            vert[i][j] = V[i][j] - '0';

    for(int i = R-1; i >= 0; i--)
        for(int j= C-1; j >= 0; j--)
            dp[i][j] = max(hori[i][j] + dp[i][j+1], vert[i][j] + dp[i+1][j]);

    return dp[0][0];

}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PasswordXGrid *obj;
	int answer;
	obj = new PasswordXGrid();
	clock_t startTime = clock();
	answer = obj->minSum(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"1","4"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"32"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"47","59"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"361"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 19;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"36","23","49"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"890","176"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 28;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"8888585","5888585"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"58585858"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 58;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"7777777","7777777","7777777","7777777"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"44444444","44444444","44444444"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 61;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
