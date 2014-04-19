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
 
class CubeColoring {
public:
	long long theCount(vector <string>);
};

long long CubeColoring::theCount(vector <string> colors) {
    
    ll res = 0;
    set<int> pos[8];
    
    int R = colors.size();
    int C = colors[0].size();
    
    for(int i=0; i < R; i++)
        for(int j=0; j < C; j++)
            if(colors[i][j] == 'Y')
                pos[i].insert(j);
    
    int len[8];
    for(int i=0; i < 8; i++)
        len[i] = pos[i].size();
    
    set<int>::iterator p0,p2,p5,p7;
    
    for(p0 = pos[0].begin(); p0 != pos[0].end(); p0++)
        for(p2 = pos[2].begin(); p2 != pos[2].end(); p2++)
            for(p5 = pos[5].begin(); p5 != pos[5].end(); p5++)
                for(p7 = pos[7].begin(); p7 != pos[7].end(); p7++)
                {
                    set<int> used1; //for vertice 1
                    set<int> used3; //for vertice 3
                    set<int> used4; //for vertice 4
                    set<int> used6; //for vertice 6
                    
                    used1.insert(*p0);
                    used1.insert(*p2);
                    used1.insert(*p5);
                    
                    used3.insert(*p0);
                    used3.insert(*p2);
                    used3.insert(*p7);
                    
                    used4.insert(*p0);
                    used4.insert(*p5);
                    used4.insert(*p7);
                    
                    used6.insert(*p2);
                    used6.insert(*p5);
                    used6.insert(*p7);
                    
                    ll sz1 = len[1];
                    ll sz3 = len[3];
                    ll sz4 = len[4];
                    ll sz6 = len[6];
                    
                    set<int>::iterator itr;
                    for(itr = used1.begin(); itr != used1.end(); itr++)
                        if( pos[1].count(*itr) == 1)
                            sz1--;
                    
                    for(itr = used3.begin(); itr != used3.end(); itr++)
                        if( pos[3].count(*itr) == 1)
                            sz3--;
                    
                    for(itr = used4.begin(); itr != used4.end(); itr++)
                        if (pos[4].count(*itr) == 1)
                            sz4--;
                    
                    for(itr = used6.begin(); itr != used6.end(); itr++)
                        if(pos[6].count(*itr) == 1)
                            sz6--;
                    
                    res += sz1 * sz3 * sz4 * sz6;
                }
    
    return res;
}



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	CubeColoring *obj;
	long long answer;
	obj = new CubeColoring();
	clock_t startTime = clock();
	answer = obj->theCount(p0);
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
	long long p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"Y","Y","Y","Y","Y","Y","Y","Y"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0ll;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"YNNNNNNN","NYNNNNNN","NNYNNNNN","NNNYNNNN","NNNNYNNN","NNNNNYNN","NNNNNNYN","NNNNNNNY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"YNNYN","YYYYY","NYYNY","YNYYN","YNNYY","YNNYY","NNNYY","NYYYY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 250ll;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"YNNYN","YYYYY","NNNNN","YNYYN","YNNYY","YNNYY","NNNYY","NYYYY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"YNNYNYYYYYNN","NNNYNYYNYNNY","YYNNYYNNNYYN","YYYYYNNYYYNN","NNNYYYNNYNYN","YYYNYYYYNYNN","NNNNNNYYNYYN","NNYNYYNNYNYY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 611480ll;
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
