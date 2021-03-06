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

int mem[25][1<<10];
int R;
int C;
vector<int> cols;

/*
 Count number of bits in "mask"
 */
int countTopLeftFour(int mask)
{
    int res = 0;
    while(mask > 0)
    {
        if(mask & 1) res++;
        mask = mask>>1;
    }
    return res;
}

/*
 rec(idx,mask) returns maximum outcome for (idx)th column
 when its previous column has configuration of "mask"
 (i)th bit of mask is set to 1 
 if ith row of the previous column is topleft corner of 2x2 '4' block.
 */
int rec(int idx, int mask)
{
    if(idx == C)
    {
        if(mask == 0) return 0;
        return nINF;
    }
    
    if(mask & cols[idx]) return nINF;
    
    int& res = mem[idx][mask];
    if(res != -1) return res;
    
    res = 0;
 
    /*
     Try every combination for current column.
     For each combination, check if it is valid by looking at "mask"
     and grid
     */
    for(int config = 0; config < (1<<(R-1)); config++)
    {
        /*
         "config" works the same way as "mask"
         We only check config to (1<<(R-1) - 1) instead of (1<<R - 1)
         because we cannot put the topleft corner of 2x2 '4' block
         at the last row.
         
         Let's call the current cell we are looking at
         cell[j][idx]  where idx stays the same for this column,
         and this information is strored at jth bith of config.
         
         We will check following conditions
         1. Is cell[j+1][idx] empty?
         
         2. Is cell[j][idx-1] or cell[j+1][idx-1] the beginning of
         4x4 block, thus making cell[j][idx] and cell[j+2][idx] unsuitable
         locations for the beginning of 4x4 block?
         
         3. Is either cell[j][idx] or cell[j+1][idx] supposed to be '1'?
         */
        
        if( (config & (config<<1)) || (mask & (config | (config<<1))) || (cols[idx] & (config | (config<<1))) )
            continue;
        
        //Pick the best outcome out of all valid configurations
        res = max(res, rec(idx+1, config | (config<<1)) + countTopLeftFour(config) * 16 + (R - countTopLeftFour(mask | config | (config<<1))));
    }
    
    return res;
    
}


int FourBlocks::maxScore(vector <string> grid) {
	R = grid.size();
    C = grid[0].size();
    
    memset(mem, -1, sizeof(mem));
    
    /*
     cols[i] 
     = jth bit of cols[i] is set to 1 
       if row j of column i contains '1' block in grid.
       0 otherwise.
     */
    for(int c = 0; c < C; c++)
    {
        int mask = 0;
        for(int r = 0; r < R; r++)
        {
            if(grid[r][c] == '1')
                mask = mask | (1<<r);
        }
        cols.push_back(mask);
    }
    
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
