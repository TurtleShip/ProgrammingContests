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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for(int i=a; i < b; i++)
#define FORE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll; 
 bool DescendingSort(int a, int b)
{
    if(a > b) return true;
    return false;
}
class FiveHundredEleven {
public:
	string theWinner(vector <int> cards);
};

string FiveHundredEleven::theWinner(vector <int> cards){
	string a1 = "Fox Ciel";
    string a2 = "Toastman";
    int N = cards.size();
    bool used[50] = {false};
    int mem = 0;
    sort(cards.begin(), cards.end(), DescendingSort);

    //card game is played N times at most
    for(int i=0; i < N; i++)
    {
        //best strategy is to pick the largest number that does not go over 511
        int pick;
        for(pick=0; pick < N; pick++)
        {
            if(!used[pick] && ((mem | cards[pick]) < 511))
            {
                used[pick] = true;
                mem = mem | cards[pick];
                break;
            }
        }
        if(pick == N)
        {
            //this means this player has to either go over 511, or be exactly 511. Let's find out.
            bool lost = true;
            for(int j=0; j < N; j++)
            {
                if(!used[j] && ((mem | cards[j]) > 511))
                {
                    lost = false;
                    break;
                }
            }
            if(lost)
            {
                if(i%2 == 0) return a2;
                else return a1;
            }
            else
            {
                //these guys will play until no cards are left
                if(N % 2 == 0) return a2;
                else return a1;
            }
            
        }
        
    }
    if(N%2==0) return a2;
    return a1;
}
 

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	FiveHundredEleven *obj;
	string answer;
	obj = new FiveHundredEleven();
	clock_t startTime = clock();
	answer = obj->theWinner(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	vector <int> p0;
	string p1;
	
	{
	// ----- test 0 -----
	int t0[] = {3,5,7,9,510};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Fox Ciel";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {0,0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Toastman";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {511};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Toastman";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {5,58,192,256};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "Fox Ciel";
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
