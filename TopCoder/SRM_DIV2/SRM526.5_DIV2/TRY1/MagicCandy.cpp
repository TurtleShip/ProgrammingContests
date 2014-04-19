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

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class MagicCandy {
public:
	int whichOne(int n);
};

//returns number of candies left after one chossing operation
int eatCandy(int n)
{
    return n - (int)sqrt(n);
}

//calculates how many steps are required to have one candy remaining
int numSteps(int n)
{
    int ans = 0;
    //stops when there is only one candy left
    while(n > 1)
    {
        n = eatCandy(n);
        ans++;
    }
    return ans;
}

//return previous position of the current candy
int previous(int cur)
{
    ll pos = (ll)cur;
    ll left = pos;
    ll right = 2ll*pos + 10;
    ll mid = (left + right)/2;
    
    while(left + 1 < right)
    {
        int guess = eatCandy(mid);
        /*cout<<"left : "<<left<<endl;
        cout<<"right : "<<right<<endl;
        cout<<"mid : "<<mid<<endl;
        cout<<"guess : "<<guess<<endl; */
        
        if(guess == cur)
            break;
        
        if(guess < cur)
            left = mid;
        else
            right = mid;
        mid = (left + right) / 2;
    }
    
    return (int)mid;
}

int MagicCandy::whichOne(int n){
	
    //first figure out how many steps required to have one candy left
    int steps = numSteps(n);
 
    int pos = 1;
    //The position of the last candy is obviously 1.
    //Get it's position "steps" steps before.
    REP(i,0,steps)
    pos = previous(pos);
    
    return pos;
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	MagicCandy *obj;
	int answer;
	obj = new MagicCandy();
	clock_t startTime = clock();
	answer = obj->whichOne(p0);
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
	
	int p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 9;
	p1 = 7;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 20;
	p1 = 17;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5265;
	p1 = 5257;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 20111223;
	p1 = 20110741;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1;
	p1 = 1;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
