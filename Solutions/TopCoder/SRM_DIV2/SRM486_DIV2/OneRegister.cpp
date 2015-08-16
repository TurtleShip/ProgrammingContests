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
 
class OneRegister {
public:
	string getProgram(int, int);
};

map<int, string> mem;
const string FAIL = ":-(";

bool isBetter(string a, string b);
string OneRegister::getProgram(int s, int t) {
	
    if(s == t) return "";
    if(t == 1) return "/";
    
    queue<int> Q;
    queue<string> S;
    Q.push(t);
    S.push("");
    string res = FAIL;
    string alt = FAIL; //alternative answer
    while(!Q.empty())
    {
        int val = Q.front(); Q.pop();
        string eq = S.front(); S.pop();
        
        if(val == s)
        {
            if(isBetter(eq, res)) res = eq;
        }
        else if(val == 1)
        {
            if(isBetter(eq, alt)) alt = eq;
        }
        else
        {
            if(val % 2 == 0)
            {
                if(mem.count(val) == 0 || isBetter(eq, mem[val]))
                {
                    mem[val] = eq;
                    Q.push( val / 2 );
                    S.push( "+" + eq );
                }
            }
            int a = (int)sqrt(val);
            if(a*a == val)
            {
                if(mem.count(val) == 0 || isBetter(eq, mem[val]))
                {
                    mem[val] = eq;
                    Q.push(a);
                    S.push("*" + eq);
                }
            }
        }
    }
    cout<<"alt : "<<alt<<endl;
    if(alt != FAIL)
    {
        alt = "/" + alt;
        if(isBetter(alt, res)) res = alt;
    }
    return res;
}

bool isBetter(string a, string b)
{
    if(a == FAIL || b == FAIL)
    {
        if(b != FAIL) return false;
        return true;
    }
    
    if(a.size() != b.size())
        return a.size() < b.size();
    
    for(int i=0; i < a.size(); i++)
    {
        if(a[i] == b[i]) continue;
        if(a[i] < b[i]) return true;
        else return false;
    }
    return true;
}

/*
 Since we have to use one operand twice, operator can be interpreted
 somewhat differently than its conventional meaning.
 
 a + => a + a => a * 2
 a - => a - a => 0
 a * => a * a => a ^ 2
 a % => a / a => 1
 
 So,, since t is always >= 1, '-' should never be used.
 
 Let's look at the reverse.
 Let b = the result of an operation.
 
 If b % 2 == 0 => + was used, and a = b/2
 If sqrt(b) * sqrt(b) == b => * was used, and a = sqrt(b)
 If b == 1, / was used, and a can be any number.
 If b == 0, - was used. however, this will never happen because 
 t is always bigger than 0.
 
 So we can basically reverse the process
 */

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	OneRegister *obj;
	string answer;
	obj = new OneRegister();
	clock_t startTime = clock();
	answer = obj->getProgram(p0, p1);
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
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 7;
	p1 = 392;
	p2 = "+*+";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 7;
	p1 = 256;
	p2 = "/+***";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 256;
	p2 = "**";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 7;
	p1 = 7;
	p2 = "";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 7;
	p1 = 9;
	p2 = ":-(";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 10;
	p1 = 1;
	p2 = "/";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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