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

class TheBoringGameDivTwo {
public:
	vector <int> find(int, int, int, int, int, int);
};

int killedJ,killedB,killedF;
int scoreJ, scoreB, scoreF;
int mem[50][50][50];

int recMin(int,int,int,int,int,int,int);
int recMax(int,int,int,int,int,int,int);

vector <int> TheBoringGameDivTwo::find(int sJ, int kJ, int sB, int kB, int sF, int kF) {
    
    vector<int> emp;
    
	if( (-sJ - sB + sF) != (kJ + kB - kF) ) return emp;
    
    killedJ = kJ;
    killedB = kB;
    killedF = kF;
    
    scoreJ = sJ;
    scoreB = sB;
    scoreF = sF;
    
    REP(i,0,50)
    REP(j,0,50)
    REP(k,0,50)
    mem[i][j][k] = INF;
    
    int minV = recMin(0,0,0,0,0,0,0);
    if(minV == INF) return emp;
    
    memset(mem, -1, sizeof(mem));
    int maxV = recMax(0,0,0,0,0,0,0);
    
    vector<int>ans(2,0);
    ans[0] = minV;
    ans[1] = maxV;
    
    return ans;
}

int recMin(int kJ, int kB, int kF, int sJ, int sB, int sF, int round)
{
    int& res = mem[kJ][kB][kF];
    
    if( res < round ) return res;
    
    if(kJ == killedJ && kB == killedB && kF == killedF)
    {
        if(sJ == scoreJ && sB == scoreB && sF == scoreF)
        {
            res = round;  
        }
        return res;
    }
    
    if( (-sJ - sB + sF) != (kJ + kB - kF) || (sF > scoreF || kJ > killedJ || kB > killedB || kF > killedF) )
        return res;
    
    res = min(res,recMin(kJ,kB,kF+1, sJ+1, sB, sF, round+1));
    res = min(res,recMin(kJ,kB,kF+1, sJ, sB+1, sF, round+1));
    
    res = min(res,recMin(kJ+1,kB,kF+1, sJ, sB, sF, round+1));
    res = min(res,recMin(kJ+1,kB,kF+1, sJ, sB+1, sF+1, round+1));
    
    res = min(res,recMin(kJ,kB+1,kF+1, sJ, sB, sF, round+1));
    res = min(res,recMin(kJ,kB+1,kF+1, sJ+1, sB, sF+1, round+1));
    
    res = min(res,recMin(kJ+1,kB+1,kF, sJ, sB, sF+2, round+1));
    res = min(res,recMin(kJ+1,kB+1,kF, sJ, sB-1, sF+1, round+1));
    res = min(res,recMin(kJ+1,kB+1,kF, sJ-1, sB, sF+1, round+1));
    
    return res;
}

int recMax(int kJ, int kB, int kF, int sJ, int sB, int sF, int round)
{
    int& res = mem[kJ][kB][kF];
    
    if( res < round ) return res;
    
    
    if(kJ == killedJ && kB == killedB && kF == killedF)
    {
        if(sJ == scoreJ && sB == scoreB && sF == scoreF)
        {
            res = round;
        }
        return res;
    }
    
    if( (-sJ - sB + sF) != (kJ + kB - kF) || (sF > scoreF || kJ > killedJ || kB > killedB || kF > killedF) )
        return res;
    
    res = max(res,recMax(kJ,kB,kF+1, sJ+1, sB, sF, round+1));
    res = max(res,recMax(kJ,kB,kF+1, sJ, sB+1, sF, round+1));
    
    res = max(res,recMax(kJ+1,kB,kF+1, sJ, sB, sF, round+1));
    res = max(res,recMax(kJ+1,kB,kF+1, sJ, sB+1, sF+1, round+1));
    
    res = max(res,recMax(kJ,kB+1,kF+1, sJ, sB, sF, round+1));
    res = max(res,recMax(kJ,kB+1,kF+1, sJ+1, sB, sF+1, round+1));
    
    res = max(res,recMax(kJ+1,kB+1,kF, sJ, sB, sF+2, round+1));
    res = max(res,recMax(kJ+1,kB+1,kF, sJ, sB-1, sF+1, round+1));
    res = max(res,recMax(kJ+1,kB+1,kF, sJ-1, sB, sF+1, round+1));
    
    return res;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, vector <int> p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	TheBoringGameDivTwo *obj;
	vector <int> answer;
	obj = new TheBoringGameDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p6.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p6[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p6.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p6[i]) {
					res = false;
				}
			}
		}
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
	int p2;
	int p3;
	int p4;
	int p5;
	vector <int> p6;
	
	{
        // ----- test 0 -----
        p0 = 1;
        p1 = 1;
        p2 = 1;
        p3 = 1;
        p4 = 2;
        p5 = 2;
        int t6[] = {2,3};
        p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
        // ------------------
	}
	
	{
        // ----- test 1 -----
        p0 = 0;
        p1 = 0;
        p2 = 0;
        p3 = 0;
        p4 = 0;
        p5 = 0;
        int t6[] = {0,0};
        p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
        // ------------------
	}
	
	{
        // ----- test 2 -----
        p0 = 4;
        p1 = 7;
        p2 = -2;
        p3 = 5;
        p4 = 1;
        p5 = 9;
        p6.clear() /*{}*/;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
        // ------------------
	}
	
	{
        // ----- test 3 -----
        p0 = 1;
        p1 = 5;
        p2 = -1;
        p3 = 4;
        p4 = 3;
        p5 = 6;
        int t6[] = {8,9};
        p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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
