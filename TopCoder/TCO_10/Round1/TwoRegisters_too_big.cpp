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
 
class TwoRegisters {
public:
	string minProg(int);
};

const int maxL = 1000010;

string mem[maxL][maxL];
bool found[maxL][maxL];

bool isBetter(string, string);

string TwoRegisters::minProg(int r) {
	
    mem[1][1] = ""; //start state
    
    queue<int> Q;
    Q.push(1);
    Q.push(1);
    
    while(!Q.empty())
    {
        int x = Q.front(); Q.pop();
        int y = Q.front(); Q.pop();
        
        int nextNum = x+y;
        
        if(nextNum <= r)
        {
            if(!found[nextNum][y] || isBetter(mem[x][y]+"X", mem[nextNum][y]) )
            {
                found[nextNum][y] = true;
                mem[nextNum][y] = mem[x][y] + "X";
                Q.push(nextNum);
                Q.push(y);
            }
            if(!found[x][nextNum] || isBetter(mem[x][y] + "Y", mem[x][nextNum]) )
            {
                found[x][nextNum] = true;
                mem[x][nextNum] = mem[x][y] + "Y";
                Q.push(x);
                Q.push(nextNum);
            }
        }
    }
    
    bool isFirst = true;
    string res = "-";
    for(int i=1; i <=r; i++)
    {
        if(found[r][i] && (isFirst || isBetter(mem[r][i], res)) )
        {
            isFirst = false;
            res = mem[r][i];
        }
    }
    
    return res;
}

bool isBetter(string a, string b)
{
    if(a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	TwoRegisters *obj;
	string answer;
	obj = new TwoRegisters();
	clock_t startTime = clock();
	answer = obj->minProg(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	int p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = 10;
	p1 = "XXYYX";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = "XX";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	p1 = "XYYYYXX";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 34;
	p1 = "XYXYXYX";
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
