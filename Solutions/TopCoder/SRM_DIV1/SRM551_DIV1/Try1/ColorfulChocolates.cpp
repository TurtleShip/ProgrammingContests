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
#define TRACE(x) 

int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class ColorfulChocolates {
public:
	int maximumSpread(string, int);
};

int ColorfulChocolates::maximumSpread(string str, int maxSwaps) {
	
    /*
     There are 26 possible colors.
     For each color, pick a starting position (50 maximum position),
     and check the maximum result using maxSwaps number of swaps
     */
    int res = 0;
    int N = str.size();
    int INF = 5555;
    for(int curPos = 0; curPos < N; curPos++) {
        char curColor = str[curPos];
        int curRes = 1;
        int l = curPos - 1;
        int r = curPos + 1;
        int curSwap = maxSwaps;
        while(l >= 0 && str[l] == curColor) {
            l--;
            curRes++;
        }
        
        while(r < N && str[r] == curColor) {
            r++;
            curRes++;
        }
        
        
        TRACE(printf("\n\ncurPos = %d, curColor = %c, curRes = %d\n", curPos, curColor, curRes);)
        TRACE(printf("left = %d, right %d\n", l, r);)
        string curStr = str;
        while(curSwap > 0) {
            int nextL = l;
            int nextR = r;
            while(nextL >= 0 && curStr[nextL] != curColor) nextL--;
            while(nextR < N && curStr[nextR] != curColor) nextR++;
            
            int dl = INF;
            int dr = INF;
            if(nextL >= 0) dl = (l - nextL);
            if(nextR < N) dr = (nextR - r);
            if(dl == INF && dr == INF) break;
            if( min(dl,dr) > curSwap) break;
            TRACE( printf("\nnextL = %d, nextR = %d\n", nextL, nextR); )
            TRACE( printf("dl = %d, dr = %d\n", dl, dr));
            curSwap -= min(dl,dr);
            if(dl < dr) {
                curStr = curStr.substr(0, nextL) + curStr.substr(nextL+1, l - nextL) + curStr.substr(nextL,1) + curStr.substr(l+1);
                l--;
            }
            else {
                curStr = curStr.substr(0,r) + curStr.substr(nextR,1) + curStr.substr(r, nextR-r) + curStr.substr(nextR+1);
                r++;
            }
            curRes++;
            TRACE( printf("curStr = %s\n", curStr.c_str()); )
        }
        
        TRACE(printf("finalRes = %d\n\n",curRes); )
        
        res = max(res, curRes);
    }
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	ColorfulChocolates *obj;
	int answer;
	obj = new ColorfulChocolates();
	clock_t startTime = clock();
	answer = obj->maximumSpread(p0, p1);
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
	p0 = "ABCDCBC";
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "ABCDCBC";
	p1 = 2;
	p2 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "ABBABABBA";
	p1 = 3;
	p2 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "ABBABABBA";
	p1 = 4;
	p2 = 5;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
	p1 = 77;
	p2 = 5;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
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
