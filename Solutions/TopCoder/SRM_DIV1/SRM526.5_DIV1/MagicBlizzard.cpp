#include <vector>
#include <list>
#include <map>
#include <set>
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

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class MagicBlizzard {
public:
	double expectation(vector <int>, vector <int>);
};

//area[i] = area covered when range = i
double area[10001];

bool snowSort( pair<int,int> a, pair<int,int> b)
{
    if(a.first < b.first) return true;
    return false;
}

double MagicBlizzard::expectation(vector <int> range, vector <int> amount) {
    
    int N = range.size();
    for(double i=0; i <= 10000; i+=1.0)
        area[(int)i] = pow(i*2.0+1.0, 2.0);
   
    double beauty = 0.0;
    vector< pair<int,int> >snow;
    REP(i,0,N)
        snow.push_back( make_pair(range[i], amount[i]) );

    sort(snow.begin(), snow.end(), snowSort);

    /*
     Assume snow is falling one by one.
     Snow is number 0....(N-1)
     Let 
     r = range[i] , b = beauty up to ith snow
     R =ange[i+1] >= r, B = beauty up to (i+1)th snow
     
     If this (i+1)th snowball falls into a square that contains x snowball
     before, then the beauty is increased by (x+1)^2 - x^2 = 2X + 1
     
     So if we know x' = expected value of x,
     then B - b = 2*x' + 1
     
     Note that  x' = i / (2R+1)^2
     because at (i+1)snowball, there are i number of snowballs already fell,
     and (i+1)th snowball will fall within (2*R+1)^2 range.
     
     So at each snowfall, beauty is increased by 2*i / (2R+1)^2 + 1
     */
    int idx = 0;
    for(int i=0; i < N; i++)
    {
        double land = area[snow[i].first];

        for(int j=0; j < snow[i].second; j++)
        {
            beauty += 2.0 * (double)idx / land + 1.0; 
            idx++;
        }
    }
    
    return beauty;
}



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	MagicBlizzard *obj;
	double answer;
	obj = new MagicBlizzard();
	clock_t startTime = clock();
	answer = obj->expectation(p0, p1);
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
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	vector <int> p1;
	double p2;
	
	{
	// ----- test 0 -----
	int t0[] = {1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2.2222222222222223;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 3.666666666666667;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {5,2,6,5};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,2,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 8.46525111252384;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {7,11,2,13,3,19,5,17};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {16,8,4,15,12,9,10,6};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 98.55659436211914;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {0,0,0,0,0,0,0,0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1.0E10;
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
