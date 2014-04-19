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
 
class SPartition {
public:
	long long getCount(string);
};

string s;
int N;
char want[20];
ll mem[21][21];


//count number of ways make 'want' out of 's'
//We are making string A and string B out of string s.
//a characters are aissgned to A, and b to B.
ll cal(int a, int b)
{
    ll& res = mem[a][b];
    
    //If we calcuated this result, return it
    if(res != -1)
        return res;
    
    if(a+b == N)
    {
        res = 1ll;
        return res;
    }
    res = 0ll;
    if(a < N/2 && want[a] == s[a+b])
        res += cal(a+1, b);
    if(b < N/2 && want[b] == s[a+b])
        res += cal(a, b+1);
    return res;
}



//make all possible combinations of nx 'x's and no 'o's 
//If this works, make it faster by enforcing
//want[0] == s[0] and want[N/2-1] == s[N-1]
ll backtrack(int nx, int no, int pos)
{
    if(nx + no == 0)
    {
        memset(mem, -1, sizeof(mem));
        return cal(0,0);
    }
    ll ans = 0ll;
    
    if(pos==0)
    {
        if(s[0] == 'x')
        {
            want[pos] = 'x';
            ans += backtrack(nx-1, no, pos+1);
        }
        else
        {
            want[pos] = 'o';
            ans += backtrack(nx, no-1, pos+1);
        }
        return ans;
    }
    
    if(pos==(N/2)-1)
    {
        if(s[N-1] == 'x')
        {
            want[pos] = 'x';
            ans += backtrack(nx-1, no, pos+1);
        }
        else
        {
            want[pos] = 'o';
            ans += backtrack(nx, no-1, pos+1);
        }
        return ans;
    }

    if(nx > 0)
    {
        want[pos] = 'x';
        ans += backtrack(nx-1, no, pos+1);
    }
    
    if(no > 0)
    {
        want[pos] = 'o';
        ans += backtrack(nx, no-1, pos+1);
    }
        
    return ans;
}

long long SPartition::getCount(string _s) {
    s = _s;
    N = s.size();
    int tx = 0;
    for(int i=0; i < N; i++)
        if(s[i] == 'x') tx++;
    int to = N - tx;
    
	if(tx%2 == 1 || to %2 == 1) return 0;
    return backtrack(tx/2, to/2, 0);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	SPartition *obj;
	long long answer;
	obj = new SPartition();
	clock_t startTime = clock();
	answer = obj->getCount(p0);
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
	
	string p0;
	long long p1;
	
	{
	// ----- test 0 -----
	p0 = "oxox";
	p1 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "oooxxx";
	p1 = 0ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "xoxxox";
	p1 = 4ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "xo";
	p1 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "ooooxoox";
	p1 = 8ll;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "ooxxoxox";
	p1 = 8ll;
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
