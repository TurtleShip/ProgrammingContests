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
#include <cstring>
using namespace std;

typedef long long ll; 

class MiningGoldEasy {
public:
	int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j);
};

vector<int> event_i;
vector<int> event_j;
int N;
int M;
int K;
int mem[55][55][55];

/*
finds the most amount of gold you can gather when
it is 'day'th day, and you are at position
row = event_i[i_day], col = event_j[j_day]
*/
int findOptimal(int day, int i_day, int j_day) {
	int& res = mem[day][i_day][j_day];

	if(res == -1) {
		if(day == K) { // no more day left
			res = 0;
		} else {
			int curGold = N + M 
			- abs(event_i[day] - event_i[i_day]) 
			- abs(event_j[day] - event_j[j_day]);
			int nextMove = 0;

			// find the optimal setting
			// move row
			for(int i=0; i < K; i++)
				nextMove = max(nextMove, findOptimal(day+1, i, j_day));

			// move column
			for(int j=0; j < K; j++)
				nextMove = max(nextMove, findOptimal(day+1, i_day, j));

			res = curGold + nextMove;
		}
		// printf("findOptimal(%d, %d, %d) = %d\n", day, i_day, j_day, res);
	}

	return res;
}

int MiningGoldEasy::GetMaximumGold(int _N, int _M, vector <int> _event_i, vector <int> _event_j) {
	event_i = _event_i;
	event_j = _event_j;
	N = _N;
	M = _M;
	K = event_j.size();

	memset(mem, -1, sizeof(mem));

	int res = 0;
	for(int i=0; i < K; i++)
		for(int j=0; j < K; j++)
			res = max(res, findOptimal(0, i, j));
	return res;
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	MiningGoldEasy *obj;
	int answer;
	obj = new MiningGoldEasy();
	clock_t startTime = clock();
	answer = obj->GetMaximumGold(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	p0 = 2;
	p1 = 2;
	int t2[] = {0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 2;
	int t2[] = {0,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {0,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 7;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 3;
	int t2[] = {0,3,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {0,3,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 15;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 4;
	int t2[] = {0,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {4,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 11;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 5;
	p1 = 6;
	int t2[] = {0,4,2,5,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {3,4,5,6,0};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 48;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 557;
	p1 = 919;
	int t2[] = {81,509,428,6,448,149,77,142,40,405,109,247};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {653,887,770,477,53,637,201,863,576,393,512,243};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 16255;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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