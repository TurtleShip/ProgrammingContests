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

#define FOR(i,a,b) for(int i=a; i < b; i++)
#define FORE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll; 
 
class CuttingGrass {
public:
	int theMin(vector <int> init, vector <int> grow, int H);
};

bool sortGrass(pair<int,int> a, pair<int,int> b)
{
    if(a.second < b.second) return true;
    return false;
}

int CuttingGrass::theMin(vector <int> init, vector <int> grow, int H){
    int N = init.size();
    vector< pair<int,int> > grass;
    int dp[51][51] = {0};
    int init_total = 0;
    int grow_total = 0;
    
    for(int i=0; i < N; i++)
    {
        grass.push_back( make_pair(init[i], grow[i]) );
        init_total += init[i];
        grow_total += grow[i];
    }
        
    if(init_total <= H) return 0;
	
    sort(grass.begin(), grass.end(), sortGrass);
    //try dp
    //dp[i][j] = maximum amount of cut grass using i cuts from [0..j-1];
    //Also, grow[i] <= grow[i+1] in [0...j-1] sequence.
    //Refer my notes for explaination.
    //dp[i][j]
    //= max(dp[i][j-1] , dp[i-1][j-1] + grass[j-1].first + i * grass[j-1].second
    for(int i = 1; i <= N; i++)
    {
        for(int j=1; j <= N; j++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-1] + grass[j-1].first + i * grass[j-1].second);
        }
    if((init_total + (grow_total* i) - dp[i][N]) <= H)
        return i;
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