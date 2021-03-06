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
 
class Hieroglyphs {
public:
	int minimumVisible(vector <string>, vector <string>);
};

struct Line
{
    bool isVert;
    int start;
    int end;
    int ori;
    int len;
    Line(bool iv, int s, int e, int o)
    {
        isVert = iv;
        start = s;
        end = e;
        ori = o;
        len = e-s;
    }
};

vector<Line> getLine(vector<string>);
int getOverlap(int,int,int,int);

int Hieroglyphs::minimumVisible(vector <string> hier1, vector <string> hier2) {
	
    vector<Line> h1 = getLine(hier1);
    vector<Line> h2 = getLine(hier2);
    int N = h2.size();
    //Fix h1. Sort lines by vertical/horizonal orientation
    vector<Line> vert[81];
    vector<Line> hori[81];
    
    int sum = 0;
    int maxInter = 0;
    REP(i,0,h1.size())
        sum += h1[i].len;
    REP(i,0,N)
        sum += h2[i].len;

    for(int i=0; i < h1.size(); i++)
    {
        if(h1[i].isVert)
        {
            vert[h1[i].ori].push_back(h1[i]);
        }
        else
        {
            hori[h1[i].ori].push_back(h1[i]);
        }
    }
    
    for(int dx=-80; dx <= 80; dx++)
    {
        for(int dy=-80; dy <= 80; dy++)
        {
            int cur = 0;
            for(int i=0; i < N; i++)
            {
                int ori = (h2[i].isVert) ? (h2[i].ori + dx) : (h2[i].ori + dy);

                if(0 <= ori && ori <= 80)
                {
                    if(h2[i].isVert)
                    {
                        for(int j=0; j < vert[ori].size(); j++)
                            cur += getOverlap(h2[i].start + dy, h2[i].end + dy, vert[ori][j].start, vert[ori][j].end);
                    }
                    else
                    {
                        for(int j=0; j < hori[ori].size(); j++)
                            cur += getOverlap(h2[i].start + dx, h2[i].end + dx, hori[ori][j].start, hori[ori][j].end);
                    }
                }
            }
            maxInter = max(maxInter , cur);
        }
    }
    
    return (sum - maxInter);
}

int getOverlap(int sA, int eA, int sB, int eB)
{
    int s = max(sA, sB);
    int e = min(eA, eB);
    return max(0, e - s);
}

vector<Line> getLine(vector<string> V)
{
    vector<Line> res;
    
    for(int i=0; i < V.size(); i++)
    {
        stringstream ss;
        replace(V[i].begin(), V[i].end(), ',', ' ');
        ss<<V[i];
        int x1,y1,x2,y2;
        while(ss>>x1>>y1>>x2>>y2)
        {
            bool isVert = (x1 == x2);
            if(isVert)
            {
                res.push_back( Line(isVert, y1, y2, x1));
            }
            else
            {
                res.push_back( Line(isVert, x1, x2, y1));
            }
        }
    }
    return res;
    
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Hieroglyphs *obj;
	int answer;
	obj = new Hieroglyphs();
	clock_t startTime = clock();
	answer = obj->minimumVisible(p0, p1);
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
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"0 0 10 0,10 0 10 3"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0 1 10 1","5 1 5 4"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 16;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"1 1 1 5"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"3 2 5 2"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0 2 6 2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"5 1 6 1,8 1 9 1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 65;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"10 10 10 20,10 30 10 40","10 10 20 10"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"10 0 10 20,10 27 10 35","10 0 20 0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 45;
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
