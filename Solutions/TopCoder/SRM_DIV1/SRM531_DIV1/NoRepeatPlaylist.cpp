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

typedef long long ll; 

class NoRepeatPlaylist {
public:
	int numPlaylists(int N, int M, int P);
};

ll mod = 1000000007;
ll mem[110][110];
int N, M, P;
ll solve(int pos, int played) {

    if(pos == P) {
        // check if all songs are played
        if(played == N) return 1;
        return 0;
    }
    
    ll &res = mem[pos][played];
    if(res != -1ll) return res;
    res = 0ll;
    int notPlayed = N - played;
    //play a song that has NOT been played
    if(notPlayed > 0)
        res = (res + notPlayed * solve(pos+1, played+1)) % mod;
    
    // play the same song = a song that has been played
    int availableSongs = played - M;
    
    if(availableSongs > 0)
        res = (res + availableSongs * solve(pos+1, played)) % mod;
    
    return res;
}

int NoRepeatPlaylist::numPlaylists(int _N, int _M, int _P) {
	N = _N;
    M = _M;
    P = _P;
    for(int i=0; i <= P; i++)
        for(int j=0; j <= N; j++)
            mem[i][j] = -1ll;
    
    return solve(0, 0);
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	NoRepeatPlaylist *obj;
	int answer;
	obj = new NoRepeatPlaylist();
	clock_t startTime = clock();
	answer = obj->numPlaylists(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 0;
	p2 = 3;
	p3 = 1;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 1;
	p2 = 3;
	p3 = 0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 0;
	p2 = 3;
	p3 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4;
	p1 = 0;
	p2 = 4;
	p3 = 24;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 2;
	p1 = 1;
	p2 = 4;
	p3 = 2;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 50;
	p1 = 5;
	p2 = 100;
	p3 = 222288991;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
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