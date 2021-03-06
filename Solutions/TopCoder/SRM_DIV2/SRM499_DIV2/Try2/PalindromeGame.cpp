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
 
class PalindromeGame {
public:
	int getMaximum(vector <string>, vector <int>);
};

/*
 1 <= N <= 50
 Palindrome itself can go anywhere.
 Also, two strings that become palindrome when combined can be a part
 of a larger palindrome.
 */

bool sortCards( pair<string,int> a, pair<string,int> b)
{
    return (a.second > b.second);
}

bool isPalindrome(string str)
{
    int i=0;
    int j = str.size() - 1;
    while( i < j)
    {
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int PalindromeGame::getMaximum(vector <string> front, vector <int> back) {
	int ans = 0;
    int N = front.size();
    vector< pair<string, int> > cards;
    bool chk[N];
    memset(chk, false, sizeof(chk));
    
    for(int i=0; i < N; i++)
        cards.push_back( make_pair(front[i], back[i]) );
    
    sort(cards.begin(), cards.end(), sortCards);
    
    bool foundMiddle = false;
    for(int i=0; i < N; i++)
    {
        if(chk[i]) continue;

        chk[i] = true;
        bool foundMatch = false;
        string rev = cards[i].first;
        reverse(rev.begin(), rev.end());
        for(int j=0; j < N; j++)
        {
            if(chk[j]) continue;
            if(rev == cards[j].first)
            {
                chk[j] = true;
                ans += cards[i].second + cards[j].second;
                foundMatch = true;
                break;
            }
        }
        
        if(!foundMatch && !foundMiddle && isPalindrome(cards[i].first))
        {
            chk[i] = true;
            foundMiddle = true;
            ans += cards[i].second;
            continue;
        }
    }
    
    return ans;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <int> p1, bool hasAnswer, int p2) {
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
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	PalindromeGame *obj;
	int answer;
	obj = new PalindromeGame();
	clock_t startTime = clock();
	answer = obj->getMaximum(p0, p1);
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
	vector <int> p1;
	int p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"topcoder","redcoder","redocpot"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,5,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 10;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"rabbit"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {1000000};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"abc","abc","def","cba","fed"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {24,7,63,222,190};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 499;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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
