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
 
class WhichDay {
public:
	string getDay(vector <string> notOnThisDay);
};

string WhichDay::getDay(vector <string> days){
    bool week[7];
    fill(week, week + 7, false);
    string names[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for(int i=0; i < 6; i++)
    {
        for(int j=0; j < 7; j++)
        {
            if(days[i] == names[j])
                week[j] = true;
        }
    }
    for(int i=0; i < 7; i++)
        if(!week[i]) return names[i];
	
    return "";
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	WhichDay *obj;
	string answer;
	obj = new WhichDay();
	clock_t startTime = clock();
	answer = obj->getDay(p0);
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
	
	vector <string> p0;
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Saturday";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"Sunday","Monday","Tuesday","Wednesday","Friday","Thursday"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Saturday";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"Sunday","Monday","Tuesday","Thursday","Friday","Saturday"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Wednesday";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"Sunday","Friday","Tuesday","Wednesday","Monday","Saturday"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Thursday";
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
