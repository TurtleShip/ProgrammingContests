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
 
class GeometricProgressions {
public:
	int count(int, int, int, int, int, int);
};

/*
 b1 == 0 => s1 = 0
 q1 == 0 => s1 = 0,b1
 q1 == 1 => s1 = b1
 */

/*
 factor(i,f) finds the factors of i and inserts them into the set f.
 */
void factor(int num, set<int>& S)
{
    while(num > 1)
    {
        if(num % 2 == 0)
        {
            num /= 2;
            S.insert(2);
            continue;
        }
        int fac = 3;
        while( fac < num && (num % fac != 0))
            fac += 2;
        num /= fac;
        S.insert(fac);        
    }
}

/*
 decompose(i,v,F) finds the factorization vector v of i, based on the factors in F
 */
void decompose(int num, vector<int>& dec, vector<int> fac)
{
    for(int i=0; i < fac.size(); i++)
    {
        int cur = 0;
        while(num > 1 && num % fac[i] == 0)
        {
            cur++;
            num /= fac[i];
        }
        dec.push_back(cur);
    }
}

string toString(vector<int> V)
{
    string str = "";
    for(int i=0; i < V.size(); i++)
    {
        stringstream ss;
        ss<<V[i];
        string temp;
        ss>>temp;
        str += " " + temp;
    }

    return str;
}

int GeometricProgressions::count(int b1, int q1, int n1, int b2, int q2, int n2) {
    
    if(b2 == 0 || q2 <= 1)
    {
        swap(b1,b2); swap(q1,q2); swap(n1,n2);
    }
    
    if(b1 == 0 || q1 <= 1)
    {
        set<ll> S;
        S.insert(b1);
        if(n1 > 1)
            S.insert(b1*q1);
        
        ll cur = (ll)b2;
        REP(i,0,n2)
        {
            S.insert(cur);
            cur*=q2;
            if(cur > 500000000)
                return (n2 - i - 1) + S.size();
        }
        return S.size();
    }
	
    //Not weird cases
    
    /*
     The set "factors" stores all possible prime factors that can occur
     */
    set<int> factors;
    factor(b1, factors);
    factor(q1, factors);
    factor(b2, factors);
    factor(q2, factors);
    
    vector<int> V(factors.begin(), factors.end());
    vector<int> repb1, repq1, repb2, repq2;
    decompose(b1, repb1, V);
    decompose(q1, repq1, V);
    decompose(b2, repb2, V);
    decompose(q2, repq2, V);
    
    set<string>S;
    vector<int> q1Fac;
    vector<int> q2Fac;
    
    for(int i=0; i < V.size(); i++)
    {
        if(repq1[i] > 0) q1Fac.push_back(i);
        if(repq2[i] > 0) q2Fac.push_back(i);
    }
    
    for(int i=0; i < n1; i++)
    {
        S.insert(toString(repb1));
        for(int j=0; j < q1Fac.size(); j++)
            repb1[q1Fac[j]] += repq1[q1Fac[j]];
    }
    int ans = S.size();
    for(int i=0; i < n2; i++)
    {
        if(S.count(toString(repb2)) == 0) ans++;

        for(int j=0; j < q2Fac.size(); j++)
            repb2[q2Fac[j]] += repq2[q2Fac[j]];
    }
    
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	GeometricProgressions *obj;
	int answer;
	obj = new GeometricProgressions();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	int p3;
	int p4;
	int p5;
	int p6;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2;
	p2 = 5;
	p3 = 6;
	p4 = 2;
	p5 = 5;
	p6 = 6;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 5;
	p3 = 2;
	p4 = 3;
	p5 = 5;
	p6 = 9;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 1;
	p2 = 1;
	p3 = 0;
	p4 = 0;
	p5 = 1;
	p6 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	p1 = 4;
	p2 = 100500;
	p3 = 48;
	p4 = 1024;
	p5 = 1000;
	p6 = 100500;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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
