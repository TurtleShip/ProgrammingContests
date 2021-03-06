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
 
class TimeTravellingSalesman {
public:
	long long determineCost(int, vector <string>);
};

struct Edge
{
    int from;
    int to;
    ll cost;
    Edge(int f=-1, int t=-1, int c=-1)
    {
        from = f;
        to = t;
        cost = c;
    }
};



bool sortEdge(Edge a, Edge b)
{
    return a.cost < b.cost;
}

/*
 Answer is the cost of minimum spanning tree.
 I will use Kruskal's Algorithm for this.
 */
long long TimeTravellingSalesman::determineCost(int N, vector <string> roads) {
	
    string info;
    vector<Edge> edges;
    
    REP(i,0,roads.size())
        info = info + roads[i];
    
    replace(info.begin(), info.end(), ',', ' ');
    
    int f,t;
    ll c;
    stringstream ss;
    ss<<info;
    while(ss>>f>>t>>c)
        edges.push_back(Edge(f,t,c));
    
    int id[N];
    REP(i,0,N)
        id[i] = i;
    ll ans = 0;
    
    sort(edges.begin(), edges.end(), sortEdge);
    
    for(int i=0; i < edges.size(); i++)
    {
        int A = edges[i].from;
        int B = edges[i].to;

        if(id[A] == id[B]) continue;
        
        //choose edge
        ans += edges[i].cost;
        
        //update info
        int newId = min(id[A], id[B]);
        int oldId = max(id[A], id[B]);
        REP(i,0,N)
            if(id[i] == oldId) id[i] = newId;
    }
    
    bool valid = true;
    REP(i,0,N)
        if(id[i] != 0) valid = false;
 
    if(valid) return ans;
    
    return -1;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <string> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	TimeTravellingSalesman *obj;
	long long answer;
	obj = new TimeTravellingSalesman();
	clock_t startTime = clock();
	answer = obj->determineCost(p0, p1);
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
	vector <string> p1;
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	string t1[] = {"0,1,1 0,2,1 1,2,2"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 6;
	string t1[] = {"0,1,2 1,4,2 4,3,3 2,4,4 0,5,3"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 14ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	string t1[] = {"0,2,2"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4;
	string t1[] = {"1,0",",10","0 2,1",",584 3,2",",754"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1438ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
