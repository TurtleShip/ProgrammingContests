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
#define F first
#define S second

int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
typedef pair<int,int> PII;

class CrouchingAmoebas {
public:
	int count(vector <int>, vector <int>, int, int);
};

/*
 At most 30 points.  N <= 30
 At most 15 moves. T <= 15
 Try brute force. 
 Pick a point, try making it each of four corners,
 and go through each point to check if they are in the square.
 Sort points who are not in the square by their distance to the square 
 in ascending order.
 
 This will take O(N * 4 * N * NlogN)
 ,at worst < 10^7. Small enough
 */

ll bx,by,ex,ey;

ll getDist(pair<ll,ll> a)
{
    if(bx <= a.F && a.F <= ex)
    {
        if(a.S < by) return abs(by - a.S);
        if(a.S > ey) return abs(ey - a.S);
    }
    
    if(by <= a.S && a.S <= ey)
    {
        if(a.F < bx) return abs(bx - a.F);
        if(a.F > ex) return abs(ex - a.F);
    }
    
    if(a.F < bx)
    {
        if(a.S > ey) return (abs(a.F - bx) + abs(a.S - ey));
        if(a.S < by) return (abs(a.F - bx) + abs(a.S - by));
    }
    if(a.F > ex)
    {
        if(a.S > ey) return (abs(a.F - ex) + abs(a.S - ey));
        if(a.S < by) return (abs(a.F - ex) + abs(a.S - by));
    }
    return 0;
}

bool sortT(pair<ll,ll> a, pair<ll,ll> b)
{
    return getDist(a) < getDist(b);
}


int CrouchingAmoebas::count(vector <int> x, vector <int> y, int _A, int T) {
    
    ll maxN = 1000000000ll;

    if(_A==maxN) return (x.size());
    
    ll A = (ll)_A;
    
    int N = x.size();
    vector< pair<ll,ll> > pt;
    for(int i=0; i < N; i++)
        pt.push_back(make_pair(ll(x[i]),ll(y[i])));
    
    vector< pair<ll,ll> >others(pt.begin(), pt.end());
    
    int best = 0;
    for(int i=0; i < N; i++)
    {
        ll dbx[4] = {pt[i].F, pt[i].F, pt[i].F - A, pt[i].F - A};
        ll dby[4] = {pt[i].S, pt[i].S - A, pt[i].S - A, pt[i].S};
        ll dex[4] = {pt[i].F + A, pt[i].F + A, pt[i].F, pt[i].F};
        ll dey[4] = {pt[i].S + A, pt[i].S, pt[i].S, pt[i].S + A};
        
        for(int d = 0; d < 4; d++)
        {
            //From bottom left corner to upper right cornner
            bx = dbx[d];
            by = dby[d];
            ex = dex[d];
            ey = dey[d];
            
            int cur = 0;
            ll curT = (ll)T;
            
            //cout<<"curPoint : ("<<bx<<" , "<<by<<") => "<<endl;
            sort(others.begin(), others.end(), sortT);
            for(int j=0; j < N; j++)
            {
                ll curDist = getDist(others[j]);
                //cout<<"dist to ("<<others[j].F<<" , "<<others[j].S<<") : "<<curDist<<endl;
                if(curDist == 0) cur++;
                else
                {
                    if(curDist > curT) break;
                    curT -= curDist;
                    cur++;
                }
            }
            //cout<<endl;
            best = max(best, cur);
            
        }
            
        
    }
    return best;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, int p3, bool hasAnswer, int p4) {
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
	cout << "}" << "," << p2 << "," << p3;
	cout << "]" << endl;
	CrouchingAmoebas *obj;
	int answer;
	obj = new CrouchingAmoebas();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	int p3;
	int p4;
	
	{
	// ----- test 0 -----
	int t0[] = {0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 1;
	p4 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 1;
	p4 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1,2,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 2;
	p4 = 3;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,0,3,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,3,0,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	p3 = 4;
	p4 = 4;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-1000000000,1000000000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-1000000000,1000000000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1;
	p3 = 15;
	p4 = 1;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
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
