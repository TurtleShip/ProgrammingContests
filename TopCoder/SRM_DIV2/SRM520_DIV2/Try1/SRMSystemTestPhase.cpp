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
 
class SRMSystemTestPhase {
public:
	int countWays(vector <string> description);
};

int SRMSystemTestPhase::countWays(vector <string> desc){
    int N = desc.size();
	int dp[55][4][4] = {0};
    int mod = 1000000007;
    //base case
    for(int p=0; p <= 3; p++)
        for(int c=0; c <= 3; c++)
            dp[N][p][c] = 1;
    
    for(int i = N-1; i >=0; i--)
    {
        for(int p=0; p <=3; p++)
            for(int c=0; c <=3; c++)
            {
                //poss[i] = possible outcome for ith problem
                //0 = passed
                //1 = challenged
                //2 = failed , not submitted
                int poss[3];
                for(poss[0]=0; poss[0] < 3; poss[0]++)
                    for(poss[1]=0; poss[1] < 3; poss[1]++)
                        for(poss[2]=0; poss[2] < 3; poss[2]++)
                        {
                            int prevP = 0;
                            int prevC = 0;
                            bool valid = true;
                            for(int k=0; k < 3; k++)
                            {
                                if(desc[i][k] == 'Y')
                                {
                                    if(poss[k] == 0) prevP++;
                                    if(poss[k] == 1) prevC++;
                                } else if(poss[k] != 2)
                                    valid = false;
                            }
                            if(!valid) continue;
                            if(p > prevP || (p == prevP && c <= prevC))
                                dp[i][p][c] = (dp[i][p][c] + dp[i+1][prevP][prevC]) % mod;
                        }
            }
    }
    return dp[0][3][0];
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SRMSystemTestPhase *obj;
	int answer;
	obj = new SRMSystemTestPhase();
	clock_t startTime = clock();
	answer = obj->countWays(p0);
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"YYY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 27;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"YNN","NYN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 6;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"YNN","NNN","NNY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"NNN","NNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"YYY","YNY","NYY","YYN","YYY","YNN"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 15176;
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
