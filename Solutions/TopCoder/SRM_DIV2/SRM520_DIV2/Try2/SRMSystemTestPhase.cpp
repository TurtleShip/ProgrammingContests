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
 
class SRMSystemTestPhase {
public:
	int countWays(vector <string>);
};


/*
 dp[i][p][c]
 = number of possible outcome when (i-1)th player has
 p passes and c challenges
 */
int dp[51][4][4];
int N;
int mod = 1000000007;
vector<string> desc;
/*
 Returns how many possible outcomes exist for player idx if
 (idx-1)th player has p passes and c challenges.
 */
int howMany(int p, int c, int idx)
{
    int& res = dp[idx][p][c];
    
    if(res != 0 || idx == N) return res;
    
    int ch[3];
    
    /*
     ch[i] = result for ith problem of (idx)th player.
     0 = passed
     1 = challenged
     2 = failed
     3 = not submitted
     */
    for(ch[0] = 0; ch[0] <= 3; ch[0]++)
        for(ch[1] = 0; ch[1] <= 3; ch[1]++)
            for(ch[2] =0; ch[2] <= 3; ch[2]++)
            {
                bool valid = true;
                int pass= 0;
                int challen = 0;
                for(int j=0; j < 3; j++)
                {
                    if((desc[idx][j] == 'N' && ch[j] != 3) || (desc[idx][j] == 'Y' && ch[j] == 3))
                    {
                        valid = false; break;
                    }
                    if(ch[j] == 0) pass++;
                    if(ch[j] == 1) challen++;
                }
                if(!valid) continue;
                
                if(pass < p || (pass == p && challen >= c))
                   res = (res + howMany(pass, challen, (idx+1))) % mod;
            }
    
    return res;
}

int SRMSystemTestPhase::countWays(vector <string> description) {
	
    N = description.size();
    desc = description;
    memset(dp, 0, sizeof(dp));
    
    for(int p=0; p <=3; p++)
        for(int c=0; c <=3; c++)
            dp[N][p][c] = 1; //represents empty board empty board
    
    return howMany(3,0,0);
    
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
