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
 
class TheCowDivTwo {
public:
	int find(int N, int K);
};

// 1 <= N <= 1000  1 <= K <= 47   K <= N
int TheCowDivTwo::find(int N, int K){
    ll modulos = 1000000007;
    
    //dp[p][k][s] = choosing k elements out of List[p, p+1, .., N-1],
    //and the set of K elements have sum mod N = s
    /* Then we are looking for dp[0][K][0] because we want the number
     of sets of K elements who have sum mod N = 0 */
    int dp[2][K+1][N];
    

    for(int p=N; p >= 0; p--)
    {
        for(int k = 0; k <= K; k++)
        {
            for(int s = N-1; s >= 0; s--)
            {
                if(k==0)
                {
                    if(s==0) dp[p%2][k][s] = 1;
                    else dp[p%2][k][s] = 0;
                }
                else if(p==N)
                    dp[p%2][k][s] = 0;
                else
                {
                    dp[p%2][k][s] = (dp[(p+1)%2][k][s] + dp[(p+1)%2][k-1][(N+s-p)%N]) % modulos;
                }
                //cout<<"dp["<<p<<"]["<<k<<"]["<<s<<"] = "<<dp[p][k][s]<<endl;
            }
        }
        //cout<<endl;
    }
    return dp[0][K][0];
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	TheCowDivTwo *obj;
	int answer;
	obj = new TheCowDivTwo();
	clock_t startTime = clock();
	answer = obj->find(p0, p1);
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
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 7;
	p1 = 4;
	p2 = 5;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 1;
	p2 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 58;
	p1 = 4;
	p2 = 7322;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 502;
	p1 = 7;
	p2 = 704466492;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 1000;
	p1 = 47;
	p2 = 219736903;
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
