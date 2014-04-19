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
 
class TrainingCamp {
public:
	vector <string> determineSolvers(vector <string>, vector <string>);
};

vector <string> TrainingCamp::determineSolvers(vector <string> attendance, vector <string> problemTopics) {
	int N = attendance.size();
    int M = attendance[0].size();
    int K = problemTopics.size();
    
    vector<string> ans;
    
    for(int i=0; i < N; i++)
    {
        string cur = "";
        for(int j=0; j < K; j++)
        {
            bool isValid = true;
            for(int m=0; m < M; m++)
            {
                if(problemTopics[j][m] == 'X' && attendance[i][m] == '-')
                    isValid = false;
                
            }
            cur += (isValid) ? "X" : "-";
        }
        ans.push_back(cur);
    }
    
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, bool hasAnswer, vector <string> p2) {
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
	TrainingCamp *obj;
	vector <string> answer;
	obj = new TrainingCamp();
	clock_t startTime = clock();
	answer = obj->determineSolvers(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p2[i] << "\"";
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
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
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
	vector <string> p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"XXX","XXX","XX-"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"---","XXX","-XX","XX-"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"XXXX","XXXX","X--X"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"-XXXX","----X","XXX--","X-X-X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"X---X","-X---","XXX--","--X--"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"-X-X","----","-XXX","X--X"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"-----","XXXXX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"XXXXX","-----","--X-X"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"-X-","XXX"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"-","X","X","-","X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"-","X"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"X-","XX","XX","X-","XX"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"X----X--X","X--X-X---","--X-X----","XXXX-X-X-","XXXX--XXX"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"X----X-X-","-----X---","-X----X-X","-X-X-X---","-----X---","X-------X"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"-X--XX","-X--X-","------","XX-XX-","--X--X"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
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
