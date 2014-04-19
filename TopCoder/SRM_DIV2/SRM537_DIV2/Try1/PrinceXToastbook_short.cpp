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
 
class PrinceXToastbook {
public:
	double eat(vector <int>);
};

vector<int> pre;
vector<int> topSort(50, -1);

ll pascal[51][51];
int N;

/*
 numPrev(i,j) = number of books to be read (prerequisite books)
 to understand book i.
 j is a bitmask representing books read so far.
 */
int numPrev(int, ll); 
void combiPascal(); //pascal's table for combination

double PrinceXToastbook::eat(vector <int> prerequisite) {
    pre = prerequisite;
	N = pre.size();
    
    combiPascal();
    
    double permu[51]; //permutation
    permu[0] = permu[1] = 1.0;
    for(double i = 2.0; i <= 50; i+=1.0)
        permu[int(i)] = i * permu[int(i-1)];
    
    double ans = 0;
    
    REP(i,0,N)
    {
        topSort[i] = numPrev(i, 0ll);
        if(topSort[i] >= N) continue; //cycle exists
        ans += double(pascal[N][topSort[i]+1]) * permu[N-topSort[i]-1];
    }
    
    return ans/permu[N];
}

int numPrev(int idx, ll visited)
{
    int& res = topSort[idx];
    if(res != -1) return res;
    
    if(pre[idx] == -1)
        return 0;
    
    if( ((visited>>idx) & 1) == 1) //cycle found
        return N;
    
    visited += (1ll<<idx);
    res = 1 + numPrev(pre[idx], visited);
    
    return res;
}

//makes pascal table. It can be used to get a combination.
//For example, pascal[10][5] is the same as number of ways to pick 5 items out of 10 items
void combiPascal()
{
	memset(pascal, 0, sizeof(pascal));
	
	pascal[0][0] = 1;
	for(int i=0; i <=50; i++)
		pascal[i][0] = 1;
	
	for(int i=1; i <= 50; i++)
		for(int j=1; j <= 50; j++)
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	PrinceXToastbook *obj;
	double answer;
	obj = new PrinceXToastbook();
	clock_t startTime = clock();
	answer = obj->eat(p0);
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
		res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	double p1;
	
	{
	// ----- test 0 -----
	int t0[] = {-1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1.5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {-1,0,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1.6666666666666667;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,-1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2.0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0.0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-1,-1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2.0;
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
