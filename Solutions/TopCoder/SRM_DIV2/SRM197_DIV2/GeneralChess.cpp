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
 
class GeneralChess {
public:
	vector <string> attackPositions(vector <string>);
};

int dx[8] = {2,2,1,1,-2,-2,-1,-1};
int dy[8] = {1,-1,2,-2,1,-1,2,-2};

bool sortKnight(pair<int,int> a , pair<int,int> b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

vector <string> GeneralChess::attackPositions(vector <string> pieces) {
	int N = pieces.size();
    vector< pair<int,int> >S(N);
    vector< pair<int,int> >knights;

    for(int i=0; i < N; i++)
    {
        int j = 0;
        while(pieces[i][j] != ',')
            j++;
        stringstream ss1(pieces[i].substr(0,j));
        stringstream ss2(pieces[i].substr(j+1));
        int a, b;
        ss1>>a;
        ss2>>b;
        S[i] = make_pair(a,b);
    }

    for(int i=0; i < 8; i++)
    {
        int x = S[0].first + dx[i];
        int y = S[0].second + dy[i];
        
        set< pair<int,int> >cur;
        for(int j=0; j < 8; j++)
            cur.insert( make_pair(x + dx[j], y + dy[j]) );
        bool isValid = true;
        for(int j=1; j < N; j++)
        {
            if(cur.count( S[j] ) == 0)
            {
                isValid = false;
                break;
            }
        }
        if(isValid)
            knights.push_back( make_pair(x,y) );
    }
    
    sort(knights.begin(), knights.end(), sortKnight);
    
    vector<string> res;
    for(int i=0; i < knights.size(); i++)
    {
        stringstream ss;
        ss<<knights[i].first<<","<<knights[i].second;
        res.push_back(ss.str());
    }
    
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, vector <string> p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	GeneralChess *obj;
	vector <string> answer;
	obj = new GeneralChess();
	clock_t startTime = clock();
	answer = obj->attackPositions(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p1[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
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
	
	vector <string> p0;
	vector <string> p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"0,0"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"-2,-1","-2,1","-1,-2","-1,2","1,-2","1,2","2,-1","2,1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"2,1","-1,-2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0,0","1,-1"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0,0","2,1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"-1000,1000","-999,999","-999,997"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"-1001,998"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
