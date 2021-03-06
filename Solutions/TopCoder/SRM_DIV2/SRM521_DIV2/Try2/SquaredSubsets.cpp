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
 
class SquaredSubsets {
public:
	long long countSubsets(int, vector <int>, vector <int>);
};

bool isInside(int xi, int yi, int xj, int yj, int xc, int yc)
{
    return (xi <= xc && xc <= xj && yi <= yc && yc <= yj);
}

bool isNSquare(int curX, int curY, int nextX, int nextY, int n)
{
    if( max(curX, curY) > n ) return false;
    if( min(nextX, nextY) <= n) return false;
    
    return true;
}

long long SquaredSubsets::countSubsets(int n, vector <int> x, vector <int> y) {
	
    set<int> sx(x.begin(), x.end());
    set<int> sy(y.begin(), y.end());
    INF = 200000001;
    sx.insert(-INF);
    sx.insert(INF);
    sy.insert(-INF);
    sy.insert(INF);
    
    vector<int> px(sx.begin(), sx.end());
    vector<int> py(sy.begin(), sy.end());
    
    set<ll> ans;
    
    for(int xi = 1; xi < (px.size()-1); xi++)
        for(int yi = 1; yi < (py.size()-1); yi++)
        {
            for(int xj = xi; xj < (px.size()-1); xj++)
                for(int yj = yi; yj < (py.size()-1); yj++)
                {
                    if(isNSquare(px[xj]-px[xi], py[yj]-py[yi], px[xj+1]-px[xi-1], py[yj+1] - py[yi-1], n) )
                    {
                        ll mask = 0;
                        for(int i=0; i < x.size(); i++)
                        {
                            if(isInside(px[xi], py[yi], px[xj], py[yj], x[i], y[i]) )
                                mask = (mask | (1ll<<i) );
                        }
                        if(mask == 0) continue;
                            ans.insert(mask);
                    }
                    
                }
        }
    return ans.size();
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	SquaredSubsets *obj;
	long long answer;
	obj = new SquaredSubsets();
	clock_t startTime = clock();
	answer = obj->countSubsets(p0, p1, p2);
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
	
	int p0;
	vector <int> p1;
	vector <int> p2;
	long long p3;
	
	{
	// ----- test 0 -----
	p0 = 5;
	int t1[] = {-5,0,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,0,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 5ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	int t1[] = {-5,0,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,0,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 5ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 100000000;
	int t1[] = {-1,-1,-1,0,1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {-1,0,1,1,-1,0,1};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 21ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	int t1[] = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 66ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	int t1[] = {-1,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 3ll;
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
