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
 
class NinePuzzle {
public:
	int getMinimumCost(string init, string goal);
};

int NinePuzzle::getMinimumCost(string init, string goal){
	
    /*
     0 -> 1,2
     1 -> 0,2,3,4
     2 -> 0,1,4,5
     3 -> 1,4,6,7
     4 -> 1,2,3,5,7,8
     5 -> 2,4,8,9
     6 -> 3,7
     7 -> 3,4,6,8
     8 -> 4,5,7,9
     9 -> 5,8
     */
    int ans =0;
    int ic[4] = {0};
    int gc[4] = {0};
    int N = init.size();
    
    REP(i,0,N)
    {
        char a = init[i];
        char b = goal[i];
        if(a == 'R') ic[0]++;
        if(a == 'G') ic[1]++;
        if(a == 'B') ic[2]++;
        if(a == 'Y') ic[3]++;
        
        if(b == 'R') gc[0]++;
        if(b == 'G') gc[1]++;
        if(b == 'B') gc[2]++;
        if(b == 'Y') gc[3]++;
    }
    
    REP(i,0,4) ans += abs(ic[i] - gc[i]);
    
    return (ans/2);
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	NinePuzzle *obj;
	int answer;
	obj = new NinePuzzle();
	clock_t startTime = clock();
	answer = obj->getMinimumCost(p0, p1);
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
	
	string p0;
	string p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "BG*YRGRRYR";
	p1 = "BGGY*YRRRR";
	p2 = 0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "GBBB*BGBBG";
	p1 = "RYYY*YRYYR";
	p2 = 9;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "RRBR*BRBBB";
	p1 = "BBRB*RBRRR";
	p2 = 1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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
