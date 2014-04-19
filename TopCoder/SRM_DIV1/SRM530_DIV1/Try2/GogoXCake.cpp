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

typedef long long ll; 

class GogoXCake {
public:
	string solve(vector <string> cake, vector <string> cutter);
};

int R_cake;
int C_cake;
int R_cutter;
int C_cutter;
bool shouldCut[55][55];
bool canCut[55][55];

string GogoXCake::solve(vector <string> cake, vector <string> cutter) {
	/*
     Observations
     #1 : Turning cutter is not allowed.
     -> We can try to simulate in a brute-force way.
     
     Runtime
     There are 50 possible spots for matching the upper-left corner of cutter
     with any point in cake.
     Fore each spot, there are at most 50 slots of cutter to check.
     50*50 is small enough.
     */
    R_cake = cake.size();
    C_cake = cake[0].size();
    R_cutter = cutter.size();
    C_cutter = cutter[0].size();
    
    for(int r = 0; r < R_cake; r++)
        for(int c= 0; c < C_cake; c++)
            shouldCut[r][c] = cake[r][c] == '.';
    
    for(int r= 0; r < R_cutter; r++)
        for(int c = 0; c < C_cutter; c++)
            canCut[r][c] = cutter[r][c] == '.';
    
    for(int r = 0; r + R_cutter - 1 < R_cake; r++)
        for(int c = 0; c + C_cutter - 1 < C_cake; c++) {
           
            bool isOkay = true;
            
            // check if it is okay to cut
            for(int rr = 0; isOkay && rr < R_cutter; rr++)
                for(int cc = 0; isOkay && cc < C_cutter; cc++)
                    if(canCut[rr][cc] && !shouldCut[r+rr][c+cc])
                        isOkay = false;
            
            // Use cutter to cut cakes
            if(isOkay)
                for(int rr = 0; rr < R_cutter; rr++)
                    for(int cc = 0; cc < C_cutter; cc++)
                        if(canCut[rr][cc])
                            shouldCut[r+rr][c+cc] = false;
                        
        }
    
    // check if we cut everything correctly
    bool res = true;
    for(int i=0; res && i < R_cake; i++)
        for(int j=0; res && j < C_cake; j++)
            res = !shouldCut[i][j];
    
    return res ? "YES" : "NO";
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, string p2) {
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
	GogoXCake *obj;
	string answer;
	obj = new GogoXCake();
	clock_t startTime = clock();
	answer = obj->solve(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	string p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"X.X","...","...","X.X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".X","..","X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"..XX","...X","X...","XX.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..",".."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"...X..."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".X.","X.X",".X."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "YES";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"XXXXXXX","X.....X","X.....X","X.....X","XXXXXXX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".X.","XXX",".X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"..","X.",".X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"..",".X","X."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"X..",".XX",".XX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {".XX",".XX","X.."};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "NO";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
