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

class CubeStickers {
public:
	string isPossible(vector <string>);
};

string CubeStickers::isPossible(vector <string> sticker) {
	/*
     Possible combination
     3 diff. color x 2 each
     2 diff color x 2 each  + 2 diff color x 1 each
     1 color x 2 each + 4 diff color x 1 each
     6 diff color x 1 each
     */
    map<string, int> myMap;
    
    for(int i=0; i < sticker.size(); i++)
    {
        if(myMap.count(sticker[i]) == 0)
            myMap[sticker[i]] = 1;
        else
            myMap[sticker[i]]++;
    }
    
    int ones = 0;
    int twoPlus = 0;
    map<string, int>::iterator itr;
    for(itr = myMap.begin(); itr != myMap.end(); itr++)
    {
        if((*itr).second > 1)
            twoPlus++;
        else
            ones++;
    }
    if( twoPlus >= 3 || (twoPlus >= 2 && ones >= 2) || (twoPlus >= 1 && ones >= 4) || ( ones >= 6) )
        return "YES";
    return "NO";
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
	CubeStickers *obj;
	string answer;
	obj = new CubeStickers();
	clock_t startTime = clock();
	answer = obj->isPossible(p0);
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
        string t0[] = {"cyan","magenta","yellow","purple","black","white","purple"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "YES";
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 1 -----
        string t0[] = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "NO";
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 2 -----
        string t0[] = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "YES";
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 3 -----
        string t0[] = {"purple","orange","orange","purple","black","orange","purple"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "NO";
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
	}
	
	{
        // ----- test 4 -----
        string t0[] = {"white","gray","green","blue","yellow","red","target","admin"};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = "YES";
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
