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

int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class CheapestRoute {
public:
	vector <int> routePrice(vector <int>, vector <int>, vector <int>, int);
};

vector<int> ans(2,0);
vector<int> cellP;
vector<int> enterC;
vector<int> exitC;
int telP;
int N;
int T;

vector<int> bfs()
{
    int INF = 100000;
    ans[0] = INF;
    ans[1] = INF;
    /*
     Perform breadth first search
     */
    int dist[N];
    for(int i=0; i < N; i++)
        dist[i] = INF;
    
    queue<int> Q;
    Q.push(0);
    Q.push(0);
    Q.push(0);
    Q.push(0);
    
    while(!Q.empty())
    {
        int idx = Q.front(); Q.pop();
        int cost = Q.front(); Q.pop();
        int move = Q.front(); Q.pop();
        int prevTel = Q.front(); Q.pop();
        
        if(idx == N-1)
        {
            if(cost < ans[0])
            {
                ans[0] = cost;
                ans[1] = move;
            }
            continue;
            
        }
        
        dist[idx] = cost;
        //go left
        if(idx > 0 && cellP[idx-1] != -1 && (cost + cellP[idx-1]) < dist[idx-1])
        {
            Q.push(idx-1);
            Q.push(cost + cellP[idx-1]);
            Q.push(move+1);
            Q.push(prevTel);
        }
        
        //go right
        if(idx < N-1 && cellP[idx+1] != -1 && (cost + cellP[idx+1]) < dist[idx+1])
        {
            Q.push(idx+1);
            Q.push(cost + cellP[idx+1]);
            Q.push(move+1);
            Q.push(prevTel);
        }
        
        //Use teleport
        for(int i=0; i < T; i++)
        {
            if(enterC[i] == idx && cellP[exitC[i]] != -1 && (cost + telP + prevTel) < dist[exitC[i]])
            {
                Q.push(exitC[i]);
                Q.push(cost + telP + prevTel);
                Q.push(move+1);
                Q.push(prevTel+1);
            }
        }
    }
    vector<int> emp;
    if(ans[0] == INF && ans[1] == INF) return emp;
    return ans;
}


vector <int> CheapestRoute::routePrice(vector <int> _cellP, vector <int> _enterC, vector <int> _exitC, int _telP) {
	
    cellP = _cellP;
    enterC = _enterC;
    exitC = _exitC;
    telP = _telP;
     
    N = cellP.size();
    T = enterC.size();
    
    if(N == 1)
        return ans;
    
        
    

    return bfs();
}



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, int p3, bool hasAnswer, vector <int> p4) {
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
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << p3;
	cout << "]" << endl;
	CheapestRoute *obj;
	vector <int> answer;
	obj = new CheapestRoute();
	clock_t startTime = clock();
	answer = obj->routePrice(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p4.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p4[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p4.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p4[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p2;
	int p3;
	vector <int> p4;
	
	{
	// ----- test 0 -----
	int t0[] = {100};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1000;
	int t4[] = {0,0};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,-1,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1000;
	int t4[] = {1000,2};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1,2,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1.clear() /*{}*/;
	p2.clear() /*{}*/;
	p3 = 100;
	int t4[] = {5,2};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {1,0,-1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0;
	p4.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {4,2,1,0,5,6,0,3,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,4,3,7,5,4,2,5,8,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {7,3,5,0,5,4,5,0,8,3};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 8;
	int t4[] = {14,6};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
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
