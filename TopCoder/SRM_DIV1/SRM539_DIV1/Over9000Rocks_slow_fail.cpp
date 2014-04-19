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

typedef long long ll; 

class Over9000Rocks {
public:
	int countPossibilities(vector <int> lowerBound, vector <int> upperBound);
};

struct Range {
    int low;
    int high;
    Range(int l= -1, int h = -1) {
        low = l;
        high = h;
    }
};

int Over9000Rocks::countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
	int res = 0;
    int N = lowerBound.size();
    int lim = (1<<N);
    int cut = 9000;
    /*
     If we know which box we will use, things will be much easier.
     There are 2^15 = (2^10) * 2^5 = 1000 * 32 = 32,000 possible combination.
     It is small enough to simulate.
     For each simulation, we need to check the uppoer bound on possible X.
     */
    vector<Range> V;
    for(int bit=0; bit < lim; bit++) {
        int high = 0;
        int low = 0;
        for(int j=0; j < N; j++) {
            if( (bit & (1<<j)) != 0) {
                low += lowerBound[j];
                high += upperBound[j];
            }
        }
        if(high <= cut) continue;
        // max(low, 9001) <= X <= up   is available.
        low = max(low,9001);
//        printf("low = %d, high %d\n", low,high);
        vector<Range> newV;
        for(int i=0; i < V.size(); i++) {
            if(high < (V[i].low - 1)) continue;
            if(low > (V[i].high + 1)) continue;
            
            if( high == (V[i].low - 1) ) {
                high = V[i].high;
            } else if (low == V[i].high + 1) {
                low = V[i].low;
            } else if( low <= V[i].low && V[i].low <= high && V[i].high > high) {
                high = V[i].high;
            } else if( V[i].low < low && low <= V[i].high && high >= V[i].high) {
                low = V[i].low;
            } else if( V[i].low <= low && high <= V[i].high) {
                low = V[i].low;
                high = V[i].high;
            }
        }
        newV.push_back(Range(low, high));
        
        for(int i=0; i < V.size(); i++) {
            if( (newV[0].high < V[i].low) || (newV[0].low > V[i].high) )
                newV.push_back(V[i]);
        }
        
        V.clear();
        for(int i=0; i < newV.size(); i++)
            V.push_back(newV[i]);
        
    }
    
    for(int i=0; i < V.size(); i++) {
//        printf("upper : %d , lower %d\n", V[i].high, V[i].low);
        res += V[i].high - V[i].low + 1;
    }
    
    return res;
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
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
	Over9000Rocks *obj;
	int answer;
	obj = new Over9000Rocks();
	clock_t startTime = clock();
	answer = obj->countPossibilities(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	int t0[] = {9000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9001};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {9000,1,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9000,2,20};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 15;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1001,2001,3001,3001};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1003,2003,3003,3003};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 9;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {9000,90000,1,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {9000,90000,3,15};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 38;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {1,1,1,1,1,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {3,4,5,6,7,8};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
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
