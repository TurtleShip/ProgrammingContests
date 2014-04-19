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
 
class SumOfLuckiness {
public:
	long long theSum(int, int);
};

//Compute sum of luckiness <= num
string str;
int N;
ll C[11][11];
ll pow8[11];

/*
 n4 = number of 4's.
 n7 = number of 7's
 D = number of available digits
 below function returns how many ways you can make
 combination of 4's and 7's in D. */

ll numberOfWays(int n4, int n7)
{
   // cout<<"getLuck("<<n4<<" , "<<n7<<") , num : "<<str<<endl;
    
    
    ll sum = 0ll;
    
    for(int i = 0; i < N; i++)
    {        
        for(char cur = '0'; cur < str[i]; cur++)
        {
            int c4 = n4;
            int c7 = n7;
            
            if(cur == '4') c4--;
            if(cur == '7') c7--;
            
            int avail = N - i - 1;
            if(c4 >= 0 && c7 >= 0 && (c4+c7) <= avail)
                sum += (C[avail][c4] * C[avail-c4][c7] * pow8[avail - c4 - c7]);
        }
        
        if(str[i] == '4') n4--;
        if(str[i] == '7') n7--;
    }
    
   // cout<<"sum : "<<sum<<endl;

    return sum;
}


ll getSum(int num)
{
    stringstream ss;
    str.clear();
    ss<<(num+1);
    ss>>str;
    N = str.size();
    
    ll ans = 0;
    
    for(int n4 = 0; n4 <= N; n4++)
        for(int n7=0; (n4+n7) <= N; n7++)
            ans += abs(n7- n4) * numberOfWays(n4,n7);
    
    return ans;
}

long long SumOfLuckiness::theSum(int A, int B) {
    
    //make pascal's triangle to compute combinations
    memset(C, 0, sizeof(C));
    
    C[0][0] = 1;
    REPE(i,0,10)
    C[i][0] = 1;
    
    REPE(i,1,10)
    REPE(j,1,10)
    C[i][j] = C[i-1][j-1] + C[i-1][j];
    //end of pascal's triangle
    
    //make powers of 8
    pow8[0] = 1ll;
    REPE(i,1,10)
        pow8[i] = 8ll * pow8[i-1];
    
   // cout<<"(A-1) : "<<(A-1)<<" => "<<getSum(A-1)<<endl;
   // cout<<"B : "<<B<<" => "<<getSum(B)<<endl;
  //  cout<<endl;
    
	return getSum(B) - getSum(A-1);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	SumOfLuckiness *obj;
	long long answer;
	obj = new SumOfLuckiness();
	clock_t startTime = clock();
	answer = obj->theSum(p0, p1);
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
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 10;
	p2 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 40;
	p1 = 47;
	p2 = 8ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 58;
	p1 = 526;
	p2 = 231ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4444;
	p1 = 7777;
	p2 = 2338ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 585858585;
	p1 = 858585858;
	p2 = 287481025ll;
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
