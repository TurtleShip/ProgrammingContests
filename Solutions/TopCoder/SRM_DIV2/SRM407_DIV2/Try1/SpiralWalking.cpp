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
 
class SpiralWalking {
public:
	int totalPoints(vector <string>);
};

bool chk[50][50];

int R;
int C;
vector<string> levelMap;
int upL;
int downL;
int leftL;
int rightL;
int LEFT = 0;
int RIGHT = 1;
int UP = 2;
int DOWN = 3;

/*
 direc        turn
 0 : left  -> up
 1 : right ->  down
 2 : up -> right
 3 : down -> left
 */

int rec(int curR, int curC, int direc, bool isFirst)
{
    chk[curR][curC] = true;
    int nextR = curR;
    int nextC = curC;
    bool isTurn = false;
    if(direc == LEFT)
    {
        if(curC == leftL) 
        {
            leftL++;
            isTurn = true;
            direc = UP;
            nextR--;
        }
        else nextC--;

    }
    else if(direc == RIGHT)
    {
        if(curC == rightL) 
        {
            rightL--;
            upL++;
            isTurn = true;
            direc = DOWN;
            nextR++;
        }
        else nextC++;
    }
    else if(direc == UP)
    {
        if(curR == upL) 
        {
            //upL++;
            isTurn = true;
            direc = RIGHT;
            nextC++;
        }
        else nextR--;
    }
    else if(direc == DOWN)
    {
        if(curR == downL) 
        {
            downL--;
            isTurn = true;
            direc = LEFT;
            nextC--;
        }
        else nextR++;
    }
    
    int curPoint = levelMap[curR][curC] - '0';
    
    if(isFirst) return curPoint + rec(nextR, nextC, direc, false);
    if(chk[nextR][nextC]) return curPoint;
    if(isTurn) return rec(nextR, nextC, direc, false);
    return curPoint + rec(nextR, nextC, direc, false); 
}
int SpiralWalking::totalPoints(vector <string> _levelMap) {
    
    levelMap = _levelMap;
    R = levelMap.size();
    C = levelMap[0].size();
    upL = 0;
    downL = R-1;
    leftL = 0;
    rightL = C-1;
    memset(chk, false, sizeof(chk));
    return rec(0,0,1, true); 
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
	SpiralWalking *obj;
	int answer;
	obj = new SpiralWalking();
	clock_t startTime = clock();
	answer = obj->totalPoints(p0);
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
	string t0[] = {"111","111","111"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"101","110"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"00","10"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"86850","76439","15863","24568","45679","71452","05483"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 142;
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
