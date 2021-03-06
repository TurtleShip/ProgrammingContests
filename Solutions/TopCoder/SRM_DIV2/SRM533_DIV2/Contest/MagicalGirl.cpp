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
 
class MagicalGirl {
public:
	double maxExpectation(int, vector <int>, vector <int>, vector <int>);
};

/*
 1 <= M <= 100,000
 1 <= N <= 50 
 */

struct Witch
{
    double day;
    double win;
    double gain;
    Witch(double d, double w, double g)
    {
        day = d;
        win = w;
        gain = g;
    }
};



bool sortWitch(Witch a, Witch b)
{
    return (a.day < b.day);
}

double MagicalGirl::maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain) {
	
    int N = day.size();
    vector<Witch> V;

    for(int i=0; i < N; i++)
    {
        Witch cur((double)day[i], double(win[i])/100.0, (double)gain[i]);
        V.push_back(cur);
    }
    sort(V.begin(), V.end(), sortWitch);
    
    double dp[N+1];
    dp[0] = double(M);
    
    for(int i=1; i <=N; i++)
    {
        dp[i] = max(dp[i-1], V[i-1].day * (1.0 - V[i-1].win) + min(dp[i-1] - V[i-1].day + double(M) ,( dp[i-1] + V[i-1].gain)) * V[i-1].win);
        cout<<"dp["<<i<<"] : "<<dp[i]<<endl;
    }
    
    return dp[N];
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, double p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
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
	MagicalGirl *obj;
	double answer;
	obj = new MagicalGirl();
	clock_t startTime = clock();
	answer = obj->maxExpectation(p0, p1, p2, p3);
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
		res = fabs(p4 - answer) <= 1e-9 * max(1.0, fabs(p4));
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
	vector <int> p2;
	vector <int> p3;
	double p4;
	
	{
	// ----- test 0 -----
	p0 = 2;
	int t1[] = {1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {75};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2.5;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	int t1[] = {5,5,5,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100,100,100,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {1,1,1,1};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 14.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10;
	int t1[] = {5,5,5,5,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {40,80,60,20,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,10,10,10,10};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 13.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	int t1[] = {2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {2};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2.0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 20;
	int t1[] = {2,13,8,7,9,4,6,21};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {18,83,75,23,45,23,10,98};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,9,8,10,7,16,13,20};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 35.908;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 11;
	int t1[] = {10,20,30,40,50,60,70,80,90};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100,100,100,100,100,100,100,100,100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,10,10,10,10,10,10,10,10};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 101.0;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 100000;
	int t1[] = {1000000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {100};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {100000};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 100000.0;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) && all_right;
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
