#include <vector>
#include <list>
#include <map>
#include <set>
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

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class KingSort {
public:
	vector <string> getSortedList(vector <string>);
};

struct compKings {
    bool operator() (const pair<string,int> a, const pair<string,int> b) const
    {
        string aName = a.first;
        string bName = b.first;
        
        if(aName.compare(bName) < 0) return true;
        if(aName.compare(bName) > 0) return false;
        if(a.second < b.second) return true;
        return false;
    }  
};

//change roman to number
int toNum(string roman)
{
    int ans = 0;
    
    //everything <=pos is 1~9
    int pos = roman.find_first_of("IV");
    if(pos != -1)
    {
        string down = roman.substr(pos);
        if(down == "I") ans += 1;
        if(down == "II") ans += 2;
        if(down == "III") ans += 3;
        if(down == "IV") ans += 4;
        if(down == "V") ans += 5;
        if(down == "VI") ans += 6;
        if(down == "VII") ans += 7;
        if(down == "VIII") ans += 8;
        if(down == "IX") ans += 9;
    }
    string up = roman.substr(0,pos);
    if(up == "X") ans += 10;
    if(up == "XX") ans += 20;
    if(up == "XXX") ans += 30;
    if(up == "XL") ans += 40;
    if(up == "L") ans += 50;
    
    return ans;
}

string toRoman(int num)
{
    int up = num / 10;
    int down = num % 10;
    string ans = "";
    if(up != 0)
    {
        if(up == 1) ans += "X";
        if(up == 2) ans += "XX";
        if(up == 3) ans += "XXX";
        if(up == 4) ans += "XL";
        if(up == 5) ans += "L";
    }
    if(down != 0)
    {
        if(down == 1) ans += "I";
        if(down == 2) ans += "II";
        if(down == 3) ans += "III";
        if(down == 4) ans += "IV";
        if(down == 5) ans += "V";
        if(down == 6) ans += "VI";
        if(down == 7) ans += "VII";
        if(down == 8) ans += "VIII";
        if(down == 9) ans += "IX";
    }
    return ans;
}

vector <string> KingSort::getSortedList(vector <string> kings) {
	
    set< pair<string,int> , compKings >order;
    int N = kings.size();
    vector<string > ans;
    
    REP(i,0,N)
    {
        int idx = kings[i].find_first_of(" ");
        order.insert( make_pair(kings[i].substr(0,idx), toNum(kings[i].substr(idx+1))));
    }
    
    set< pair<string,int> >::iterator itr;
    for(itr = order.begin(); itr != order.end(); itr++)
    {
        pair<string,int> cur = *itr;
        ans.push_back(cur.first + " " + toRoman(cur.second));
    }
    return ans;
    
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
	KingSort *obj;
	vector <string> answer;
	obj = new KingSort();
	clock_t startTime = clock();
	answer = obj->getSortedList(p0);
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
	string t0[] = {"Louis IX","Louis VIII"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Louis VIII","Louis IX"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"Louis IX","Philippe II"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Louis IX","Philippe II"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"Richard III","Richard I","Richard II"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Richard I","Richard II","Richard III"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"John X","John I","John L","John V"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"John I","John V","John X","John L"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"Philippe VI","Jean II","Charles V","Charles VI","Charles VII","Louis XI"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Charles V","Charles VI","Charles VII","Jean II","Louis XI","Philippe VI"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"Philippe II","Philip II"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"Philip II","Philippe II"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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