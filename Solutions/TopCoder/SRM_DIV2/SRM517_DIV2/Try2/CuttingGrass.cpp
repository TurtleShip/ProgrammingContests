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
 
class CuttingGrass {
public:
	int theMin(vector <int>, vector <int>, int);
};

int CuttingGrass::theMin(vector <int> init, vector <int> grow, int H) {
	
    int N = init.size();
    int I = 0 , G = 0;
    vector< pair<int,int> >grass;
    REP(i,0,N)
    {
        I += init[i]; G += grow[i];
        grass.push_back( make_pair(grow[i], init[i]));
    }
    
    if(I <= H) return 0;
    
    /*
     Say we are cutting grass [0...(S-1)]
     What we do know that (i)th grass's growth must be smaller than
     (i+1)th grass's growth.
     What we don't know is which grass we should cut.
     */
    
    /*
     dp[i][j] 
     = maximum cut that can be gained from cutting grass[0..i]
     using j cuts
     */
    int dp[N][N];
    memset(dp, 0, sizeof(dp));

    sort(grass.begin(), grass.end());
    for(int cut=1; cut <= N; cut++)
    {
        dp[0][cut] = grass[0].second + grass[0].first;
        for(int idx = 1; idx < N; idx++)
        {
            dp[idx][cut] = max(dp[idx-1][cut-1] + grass[idx].second + grass[idx].first * (cut) , dp[idx-1][cut]);
        }
        if((I + G * cut - dp[N-1][cut]) <= H)
            return cut;
    }
    
    return -1;

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
	CuttingGrass *obj;
	int answer;
	obj = new CuttingGrass();
	clock_t startTime = clock();
	answer = obj->theMin(p0, p1, p2);
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
	int t0[] = {5,8,58};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 16;
	p3 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 58;
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {5,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	p3 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {5,1,6,5,8,4,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1,1,1,4,3,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 33;
	p3 = 5;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {49,13,62,95,69,75,62,96,97,22,69,69,52};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,2,4,3,6,5,7,6,5,4,7,7,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 517;
	p3 = 8;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {1231,1536,1519,1940,1539,1385,1599,1613,1394,1803,1763,1706,1863,1452,1818,1914,1386,1954,1496,1722,1616,1862,1755,1215,1233,1078,1448,1241,1732,1561,1633,1307,1844,1911,1371,1338,1989,1789,1656,1413,1929,1182,1815,1474,1540,1797,1586,1427,1996,1202};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {86,55,2,86,96,71,81,53,79,22,23,8,69,32,35,39,30,18,92,64,88,1,48,81,91,75,44,77,3,33,9,52,56,4,19,73,52,18,8,77,91,59,50,62,42,87,89,24,71,67};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 63601;
	p3 = 36;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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
