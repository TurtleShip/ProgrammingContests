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
 
class Zoo {
public:
	long long theCount(vector <int> answers);
};

bool ascending(int a, int b)
{
    if(a < b) return true;
    return false;
}
long long Zoo::theCount(vector <int> ans){
    int N = ans.size();
    vector<int> rab;
    vector<int> cat;
    bool used[50] = {false};
	sort(ans.begin(), ans.end(), ascending);
    //check if this ans is a possible
    if(ans[0] != 0) return 0;
    int count = 0;
    
    for(int i=0; i < N; i++)
    {
        if(ans[i] == count && !used[i])
        {
            rab.push_back(count++);
            used[i] = true;
        }
    }
    count = 0;
    for(int i=0; i < N; i++)
    {
        if(ans[i] == count && !used[i])
        {
            cat.push_back(count++);
            used[i] = true;
        }
    }
    if(rab.size() + cat.size() != N) return 0;
    int large = max(rab.size(), cat.size());
    int small = min(rab.size(), cat.size());
    int diff = large - small;
    int res = 1;
    for(int i=0; i < small; i++)
        res *= 2;
    if(diff > 0) res *= 2;
    return res;
    
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	Zoo *obj;
	long long answer;
	obj = new Zoo();
	clock_t startTime = clock();
	answer = obj->theCount(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	
	vector <int> p0;
	long long p1;
	
	{
	// ----- test 0 -----
	int t0[] = {0,1,2,3,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {5,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,0,0,0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,0,2,0,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 8ll;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,0,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0ll;
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