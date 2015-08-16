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

/*
 R = number of rows
 C = number of columns
 cols[i] = binary representation of (i)ith column.
 (j)th bit of cols[i] is 1 if '1' block needs to be at
 (j)th row of (i)th column.
 */
int R;
int C;
vector<int> cols;
int mem[25][1<<10];

int countFour(int num)
{
    int res = 0;
    while(num > 0)
    {
        if(num & 1) res++;
        num = (num>>1);
    }
    return res;
}

/*
 "mask" is a binary number representing configuration of previous column.
 (i)th bit of "mask" is 1 if topleft corner of '4' block is placed at
 the (i) row of the current column.
 */
int rec(int idx, int mask)
{
    
    int& res = mem[idx][mask];
    if(res != -1) return res;
    
    if(idx == C)
    {
        /*
         check validity of mask
         by making sure previous column did not contain beginning of
         '4' block 
         */
        if(mask == 0) res = 0;
        else res = nINF;
        return res;
    }
    
    if(mask & cols[idx]) return (res = nINF); 
    
    res = 0;
    
    //try every possible combination for the current column
    for(int config = 0; config < (1<<(R-1)); config++)
    {
        /*
         Check following cases
         */
        if( (config & (config<<1)) || (mask & (config | (config<<1)) ) || (cols[idx] & (config | (config<<1))) )
            continue;
        
        res = max(res, rec(idx+1, config | (config<<1) ) + 16 * countFour(config) + (R - countFour(config | (config<<1) | mask )) );
    }
    return res;
}


/*
 1 <= R <= 10
 1 <= C <= 25
 Go through each column, try every combination.
 Since there are at most 10 rows in a column, at most 2^10 possible config.
 The entire ops O(C * 2^R) = 25 * 2^10 at most
 */
int FourBlocks::maxScore(vector <string> grid) {
	R = grid.size();
    C = grid[0].size();
    
    for(int c=0; c < C; c++)
    {
        int mask = 0;
        for(int r=0; r < R; r++)
        {
            if(grid[r][c] == '1')
            {
                mask = (mask | (1<<r));
            }
        }
        cols.push_back(mask);
    }
    memset(mem, -1, sizeof(mem));
    
    return rec(0,0);
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