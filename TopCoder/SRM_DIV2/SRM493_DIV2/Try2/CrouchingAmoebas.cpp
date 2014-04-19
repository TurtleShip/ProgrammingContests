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
 
class CrouchingAmoebas {
public:
	int count(vector <int>, vector <int>, int, int);
};

int CrouchingAmoebas::count(vector <int> x, vector <int> y, int A, int T) {
    int ans = 0;
	REP(px,0,x.size())
    REP(py,0,y.size())
    for(int xT = -T; xT <= T; xT++)
        for(int yT = -T; yT <= T; yT++)
            if( (abs(xT) + abs(yT)) <= T )
            {
                int leftX = x[px] + xT;
                int botY = y[py] + yT;
                
                int rightX = leftX + A;
                int upY = botY + A;
                
                vector<ll> dist;
                for(int i=0; i < x.size(); i++)
                {
                    ll cur = 0;
                    if(x[i] < leftX) cur += abs(leftX - x[i]);
                    if(x[i] > rightX) cur += abs(rightX - x[i]);
                    if(y[i] < botY) cur += abs(botY - y[i]);
                    if(y[i] > upY) cur += abs(upY - y[i]);
                    dist.push_back(cur);
                }
                int sum = 0;
                int num = 0;
                sort(dist.begin(), dist.end());
                for(int i=0; i < dist.size(); i++)
                {
                    if(dist[i] + sum <= T)
                    {
                        sum += dist[i];
                        num++;
                    }
                    else 
                        break;
                }
                ans = max(ans, num);
            }
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, int p3, bool hasAnswer, int p4) {
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
	cout << "}" << "," << p2 << "," << p3;
	cout << "]" << endl;
	CrouchingAmoebas *obj;
	int answer;
	obj = new CrouchingAmoebas();
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;
	int p4;
	
	{
	// ----- test 0 -----
	int t0[] = {0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 1;
	p4 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 1;
	p4 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 2;
	p4 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,0,3,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,3,0,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	p3 = 4;
	p4 = 4;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-1000000000,1000000000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1000000000,1000000000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 15;
	p4 = 1;
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
