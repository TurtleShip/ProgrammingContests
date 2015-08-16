#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <string>
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
 
class MultiplesWithLimit {
public:
	string minMultiples(int, vector <int>);
};

string MultiplesWithLimit::minMultiples(int N, vector <int> forbiddenDigits) {
	
    vector<string> mem(N,"");
    vector<bool> allowed(10,true);
    queue<int> Q;
    string digi = "0123456789";

    int forb_len = forbiddenDigits.size();
    REP(i,0,forb_len)
        allowed[forbiddenDigits[i]] = false;
    
    Q.push(0);
    
    while(!Q.empty()) //DFS
    {
        int cur = Q.front();
        Q.pop();
        
        REP(i,0,10)
        {
            if(allowed[i] && (cur + i) > 0)
            {
                int nextMod = (cur*10 + i) % N;
                if(mem[nextMod] == "")
                {
                    string nextNum = mem[cur] + digi[i];
                    mem[nextMod] = nextNum;
                    Q.push(nextMod);
                }
            }
        }
    }
    
    if(mem[0] == "") return "IMPOSSIBLE";
    if(mem[0].size() >= 9)
    {
        string str;
        stringstream ss;
        ss<<mem[0].size();
        ss>>str;
        string ans = mem[0].substr(0,3) + "..." + mem[0].substr(mem[0].size() - 3);
        ans += "(" + str + " digits)";
        return ans;
    }
    return mem[0];
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	MultiplesWithLimit *obj;
	string answer;
	obj = new MultiplesWithLimit();
	clock_t startTime = clock();
	answer = obj->minMultiples(p0, p1);
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
	
	int p0;
	vector <int> p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 8;
	int t1[] = {2,3,4,5,6,7,8,9};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "1000";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 9;
	int t1[] = {1,3,4,5,6,7,8,9};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "222...222(9 digits)";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 524;
	int t1[] = {5,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "3668";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10000;
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1;
	int t1[] = {0,1,2,3,4,5,6,7,8,9};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = "IMPOSSIBLE";
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