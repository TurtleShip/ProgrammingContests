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
 
class MathContest {
public:
	int countBlack(string, int);
};

/*
 white -> reverse order of the stack
 black -> reverse color
 
 count number of black balls that will be shown the audiance.
 
*/

bool chk[100000];
string balls;
int N;
int leftLast;
int rightLast;

int rec(int idx, int count, bool goRight, bool colorChange)
{
    if(chk[idx]) return count;
    if(idx == - 1 || idx == N) return count;
    chk[idx] = true;
    
    //current ball is white => Reverse order
    if( (!colorChange && balls[idx] == 'W') || (colorChange && balls[idx] == 'B') )
    {
        if(goRight)
        {
            leftLast = idx + 1;
            return rec(rightLast, count, !goRight, colorChange);
        }
        else
        {
            rightLast = idx - 1;
            return rec(leftLast, count, !goRight, colorChange);
        }
    }//current ball is black => change color
    else
    {
        if(goRight)
        {
            return rec(idx + 1, count + 1, goRight, !colorChange);
        }
        else
        {
            return rec(idx - 1, count + 1, goRight, !colorChange);
        }
    }
    
    cout<<"NO!!! This line should never be reached!!!"<<endl;
    return -1;
}

int MathContest::countBlack(string seq, int rep) {
	
    memset(chk, false, sizeof(chk));
    balls = "";
    for(int i=0; i < rep; i++)
        balls = balls + seq;
    N = balls.size();
    leftLast = 0;
    rightLast = N - 1;
    
    return rec(0, 0, true, false);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	MathContest *obj;
	int answer;
	obj = new MathContest();
	clock_t startTime = clock();
	answer = obj->countBlack(p0, p1);
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
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "BBWWB";
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "BBB";
	p1 = 10;
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "BW";
	p1 = 10;
	p2 = 20;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "WWWWWWWBWWWWWWWWWWWWWW";
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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