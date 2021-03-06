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

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class DucksAlignment {
public:
	int minimumTime(vector <string> grid);
};

bool byCol(pair<int,int> a, pair<int,int> b)
{
    if(a.second < b.second) return true;
    return false;
}

bool byRow(pair<int,int> a, pair<int,int> b)
{
    if(a. first < b.first) return true;
    return false;
}

int dist(int a, int b, int c, int d)
{
    return abs(a-c) + abs(b-d);
}

int DucksAlignment::minimumTime(vector <string> grid){
	vector< pair<int,int> >duck;
    int R = grid.size();
    int C = grid[0].size();
    int ans = INF;
    
    REP(i,0,R)
    REP(j,0,C)
    {
        if(grid[i][j] == 'o')
            duck.push_back( make_pair(i,j) );
    }
    int N = duck.size();
    //each column has at most on duck
    //Let's try align row first
    sort(duck.begin(), duck.end(), byCol);
    REP(r,0,R)
    {
        int rowTime = 0;
        REP(i,0, N)
        {
            rowTime += abs(duck[i].first - r);
        }
        
        REP(c,0,C-N+1)
        {
            int colTime = 0;
            REP(i,0,N)
            {
                colTime += abs(duck[i].second - (c+i));
            }
            ans = min(ans, rowTime + colTime);
        }
    }
    
    //try aling col
    sort(duck.begin(), duck.end(), byRow);
    REP(c,0,C)
    {
        int colTime = 0;
        REP(i,0,N)
        colTime += abs(duck[i].second - c);
        
        REP(r,0,R-N+1)
        {
            int rowTime = 0;
            REP(i,0,N)
                rowTime += abs(duck[i].first - (r+i));
            
            ans = min(ans, rowTime + colTime);
        }
    }
    return ans;
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	DucksAlignment *obj;
	int answer;
	obj = new DucksAlignment();
	clock_t startTime = clock();
	answer = obj->minimumTime(p0);
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {".o","o."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {".o...","..o..","....o"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"o..........","..o........",".......o...","...........","...........","...........","........o..","..........."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 16;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".........","....o....","........."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"...o..........................","............................o.",".o............................","............o.................",".................o............","......................o.......","......o.......................","....o.........................","...............o..............",".......................o......","...........................o..",".......o......................"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 99;
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
