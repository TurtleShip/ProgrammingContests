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

#define FOR(i,a,b) for(int i=a; i < b; i++)
#define FORE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll; 
 
class MagicalSquare {
public:
	long long getCount(vector <string> rowStrings, vector <string> columnStrings);
};

long long MagicalSquare::getCount(vector <string> r, vector <string> c){
	ll ans = 0;
    
    for(int a=0; a <= r[0].size(); a++)
    {
        for(int b=0; a+b <= r[0].size(); b++)
        {
            for(int e=0; e <= r[1].size() && (a + e <= c[0].size()); e++)
            {
                for(int f=0; e+f <= r[1].size() && (b+f <= c[1].size()); f++)
                {
                    int d = r[0].size() - a - b;
                    int g = r[1].size() - e - f;
                    if(d + g >c[2].size()) continue;
                    
                    //check c0
                    if((r[0].substr(0,a) + r[1].substr(0,e)) != c[0].substr(0, a + e)) continue;
                    
                    //check c1
                    if((r[0].substr(a,b) + r[1].substr(e,f)) != c[1].substr(0, b+f)) continue;
                    
                    //check c2
                    if( (r[0].substr(a+b) + r[1].substr(e+f)) != c[2].substr(0, d+g)) continue;
                    
                    //check r2
                    if((c[0].substr(a+e) + c[1].substr(b+f) + c[2].substr(d+g)) != r[2]) continue;
                    ans++;
                       
                }
            }
        }
    }
    
    return ans;
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, long long p2) {
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
	MagicalSquare *obj;
	long long answer;
	obj = new MagicalSquare();
	clock_t startTime = clock();
	answer = obj->getCount(p0, p1);
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
	
	vector <string> p0;
	vector <string> p1;
	long long p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"f","o","x"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"f","o","x"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"x","x","x"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"x","","xx"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"cd","cd","cd"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"dvd","dvd","dvd"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"abab","ab","abab"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"abab","ab","abab"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 11ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"qwer","asdf","zxcv"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"qaz","wsx","erdfcv"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
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
