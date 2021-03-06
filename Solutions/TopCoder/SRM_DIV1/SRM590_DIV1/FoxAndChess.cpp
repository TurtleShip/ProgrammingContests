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

typedef long long ll; 

class FoxAndChess {
public:
	string ableToMove(string begin, string target);
};

string FoxAndChess::ableToMove(string begin, string target) {
	bool isPossible = true;
	int N = begin.size();
	vector<bool> used(N, false);

	// see that we can go to the "target" from "begin"
	for(int i=0; isPossible && i < N; i++) {
		if(target[i] == '.') continue;
		if(target[i] == 'R') {
			bool found = false;
			
			for(int j=0; !found && j <= i; j++) {
				if(used[j]) continue;
				if(begin[j] == 'R') {
					found = true;
					// use it
					used[j] = true;
					for(int k=j; isPossible && k <= i; k++) {
						isPossible &= begin[k] != 'L' && target[k] != 'L';
					}
				}
			}
			isPossible &= found;

		} else { // target[i] == 'L'
			bool found = false;

			for(int j=i; !found && j < N; j++) {
				if(used[j]) continue;
				if(begin[j] == 'L') {
					found = true;
					used[j] = true;
					for(int k=i; isPossible && k <= j; k++) {
						isPossible &= begin[k] != 'R' && target[k] != 'R';
					}
				}
			}

			isPossible &= found;
		}
	}

	// check that there is no leftover pawn in "begin"
	for(int i=0; isPossible && i < N; i++) {
		isPossible &= (begin[i] == '.' || used[i]);
	}
	
	return isPossible ? "Possible" : "Impossible";
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	FoxAndChess *obj;
	string answer;
	obj = new FoxAndChess();
	clock_t startTime = clock();
	answer = obj->ableToMove(p0, p1);
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
	
	string p0;
	string p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "R...";
	p1 = "..R.";
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "..R.";
	p1 = "R...";
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = ".L.R.R.";
	p1 = "L...R.R";
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = ".L.R.";
	p1 = ".R.L.";
	p2 = "Impossible";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "LRLLRLRLLRLLRLRLRL";
	p1 = "LRLLRLRLLRLLRLRLRL";
	p2 = "Possible";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "L";
	p1 = ".";
	p2 = "Impossible";
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
