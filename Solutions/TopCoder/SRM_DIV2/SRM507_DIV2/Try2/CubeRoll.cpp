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

int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class CubeRoll {
public:
	int getMinimumSteps(int, int, vector <int>);
};

int boundCase(int leftBound, int rightBound, int start, int end)
{
    bool chk[rightBound];
    memset(chk, false, sizeof(chk));
    
    queue<int> Q;
    Q.push(start);
    Q.push(0);
    chk[start] = true;
    int ans = 0;
    while(!Q.empty())
    {
        int curPos = Q.front();   Q.pop();
        int curTurn = Q.front();   Q.pop();
        if(curPos == end)
        {
            ans = curTurn;
            break;
        }
        for(int x = 1; (x*x + curPos) < rightBound; x++)
        {
            int next = x*x + curPos;
            if(chk[next]) continue;
            
            chk[next] = true;
            Q.push(next);
            Q.push(curTurn + 1);
        }
        
        for(int x= 1; (curPos - x*x) > leftBound; x++)
        {
            int next = curPos - x*x;
            
            if(chk[next]) continue;
               Q.push(next);
               Q.push(curTurn + 1);
        }
    }
    return ans;
}

int unboundCase(int start, int end)
{
    int res = boundCase(start -1 , end + 1, start, end);
    
    if((end - start) % 4 != 2) res = min(res, 2);
    else res = min(res, 3);
    
    return res;
}
               
int CubeRoll::getMinimumSteps(int initPos, int goalPos, vector <int> holePos) {
	int INF = 100001;
    int leftLimit = -INF;
    int rightLimit = INF;
    int start = min(initPos, goalPos);
    int end = max(initPos, goalPos);
    
    for(int i=0; i < holePos.size(); i++)
    {
        int cur = holePos[i];
        if(start < cur && cur < end)
            return -1;
        if(cur < start)
            leftLimit = max(leftLimit,cur);
        if(cur > end)
            rightLimit = min(rightLimit, cur);
    }
    
    int ans = 0;
    if(leftLimit == -INF || rightLimit == INF)
        ans = unboundCase(start, end);
    else
        ans = boundCase(leftLimit, rightLimit, start,end);
    
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	CubeRoll *obj;
	int answer;
	obj = new CubeRoll();
	clock_t startTime = clock();
	answer = obj->getMinimumSteps(p0, p1, p2);
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
	int p1;
	vector <int> p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 1;
	int t2[] = {3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = -1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 36;
	p1 = 72;
	int t2[] = {300,100,200,400};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	p1 = 21;
	int t2[] = {38,45};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 98765;
	p1 = 4963;
	int t2[] = {10,20,40,30};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 68332;
	p1 = 825;
	int t2[] = {99726,371,67,89210};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
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