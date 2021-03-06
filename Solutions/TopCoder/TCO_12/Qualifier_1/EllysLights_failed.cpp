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
 
class EllysLights {
public:
	int getMinimum(string, vector <string>);
};

ll getVal(string);

ll initVal;
vector<ll> swit;
set<ll> chk;

int EllysLights::getMinimum(string initial, vector <string> switches) {
	
    int N = switches.size();
    initVal = getVal(initial);
    for(int i=0; i < N; i++)
        swit.push_back(getVal(switches[i]));
    
    if(initVal == 0) return 0;
    
    int ans = 55;
   
    queue<ll> Q;
    
    for(int i=0; i < N; i++)
    {
        chk.insert(swit[i]);
        Q.push(swit[i]);
        Q.push(1ll<<i);
        Q.push(1);
    }
    
    //check validity
    for(int i=0; i < initial.size(); i++)
    {
        if(initial[i] == 'Y')
        {
            bool hasY = false;
            for(int j=0; j < N; j++)
            {
                if(switches[j][i] == 'Y')
                {
                    hasY = true;
                    break;
                }
            }
            if(!hasY) return -1;
        }
    }
    
    //BFS
    while(!Q.empty())
    {
        ll val = Q.front(); Q.pop();
        ll condi = Q.front(); Q.pop();
        ll turn = Q.front(); Q.pop();
        
        if(val == initVal)
        {
            ans = turn;
            break;
        }
        
        for(int i=0; i < N; i++)
        {
            if( (condi & (1ll<<i)) == 0 )
            {
                ll next = val ^ swit[i];
                if(chk.count(next) == 1) continue;
                chk.insert(next);
                Q.push(next);
                Q.push(condi |= (1ll<<i) );
                Q.push(turn + 1);
                
            }
        }
    }

    if(ans == 55) return -1;
    return ans;
}

ll getVal(string str)
{
    ll res = 0ll;
    ll two = 1ll;
    for(int i=str.size()-1; i >= 0; i--)
    {
        if(str[i] == 'Y') res += two;
        two *= 2ll;
    }
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	EllysLights *obj;
	int answer;
	obj = new EllysLights();
	clock_t startTime = clock();
	answer = obj->getMinimum(p0, p1);
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
	
	string p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "YNYNNN";
	string t1[] = {"YNNYNY","NYYYNN","YNYNYN","NNNNYN","NYNNNY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "YNYNYN";
	string t1[] = {"NNNNNN","YYYYYY","NYNNNN","NNNYNN","NNNNNY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "YYN";
	string t1[] = {"YNY","NYN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "NNYNYNYYYNNYYYYN";
	string t1[] = {"NYNYNYNYNYNYNYNY","YNYNYNYNYNYNYNYN","NNNNNNNNNNNNNNNN","YNNNNNNNNNNNNNNN","NYNNNNNNNNNNNNNN","NNYNNNNNNNNNNNNN","NNNYNNNNNNNNNNNN","NNNNYNNNNNNNNNNN","NNNNNYNNNNNNNNNN","NNNNNNYNNNNNNNNN","NNNNNNNYNNNNNNNN","NNNNNNNNYNNNNNNN","NNNNNNNNNYNNNNNN","NNNNNNNNNNYNNNNN","NNNNNNNNNNNYNNNN","NNNNNNNNNNNNYNNN","NNNNNNNNNNNNNYNN","NNNNNNNNNNNNNNYN","NNNNNNNNNNNNNNNY"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY";
	string t1[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN","NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN","NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN","NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN","NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY","NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN","NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN","NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN","NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN","NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN","YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN","NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN","NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 7;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN";
	string t1[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN","NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN","NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN","NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN","NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN","YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN","NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN","NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY","NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN","NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN","NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN","NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN","NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN","NNNNYNNNNNN"
			"NNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN","NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN","NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN","NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN","NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN","NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN","NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -1;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
