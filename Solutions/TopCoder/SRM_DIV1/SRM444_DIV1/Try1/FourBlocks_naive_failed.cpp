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
 
class FourBlocks {
public:
	int maxScore(vector <string>);
};

int FourBlocks::maxScore(vector <string> grid) {
	
    /*
     1 <= R <= 10
     1 <= C <= 25
     */
    
    int R = grid.size();
    int C = grid[0].size();
    
    /*
     Constriants tell us that 
     each element of grid will contain only '.' or '1'
     
     In order to achieve maximum score, we want to use as many '4' blocks
     as possible.
     
     Let's define a state for each cell
     0 : empty
     1 : '1' block
     2 : '4' block
     
     Since '4' block requires '4' blocks, we need to look at cells grouped
     in 4.
     At cell[i][j], we will look at
     cell[i+1][j] , cell[i][j+1] , cell[i+1][j+1]
     */
    
    for(int i=0; i < R-1; i++)
    {
        for(int j=0; j < C-1; j++)
        {
            char& c1 = grid[i][j];
            char& c2 = grid[i+1][j];
            char& c3 = grid[i][j+1];
            char& c4 = grid[i+1][j+1];
            
            if(c1 == '.' && c2 == '.' && c3 == '.' && c4 == '.')
            {
                c1 = c2 = c3 = c4 = '4';
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i < R; i++)
    {
        for(int j=0; j < C; j++)
        {
            if(grid[i][j] == '4') ans += 4;
            else ans ++;
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
	FourBlocks *obj;
	int answer;
	obj = new FourBlocks();
	clock_t startTime = clock();
	answer = obj->maxScore(p0);
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
	string t0[] = {".....1..1..","..1.....1.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 70;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"...1.",".....",".1..1",".....","1...."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 73;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...1.",".1...","..1.1","1...."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".....1...",".....1...","111111111",".....1...",".....1..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 117;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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