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
 
class HexagonPuzzle {
public:
	int theCount(vector <string>);
};

int mod = 1000000007;
/*
 'X' = locked
 '.' = unlocked
 */
vector<string> board;
vector<int> partLen;
bool ori[50][50];
bool used[50][50];
int N;

int getParts(int, int);
int rec(int,int);

int HexagonPuzzle::theCount(vector <string> board) {
	
    N = board.size();
    int maxC = 0;
    memset(ori, false, sizeof(ori));
    memset(used, false, sizeof(used));
    
    REP(i,0,N)
    REP(j,0,i+1)
        ori[i][j] = (board[i][j] == '.');
    
    REP(i,0,N)
    REP(j,0,i+1)
    {
        int cur = getParts(i,j);
        maxC = max(maxC, cur);
        if(cur >= 3)
            partLen.push_back(cur);
        
    }
    
    maxC++;
    ll permu[maxC];
    permu[3] = 3ll;
    
    for(int i=4; i < maxC; i++)
        permu[i] = (permu[i-1] * i) % mod;
    
    ll ans = 1;

    //cout<<"partLen : ";
    for(int i=0; i < partLen.size(); i++)
        ans = (ans * permu[partLen[i]]) % mod;

    return ans;
}

int getParts(int r, int c)
{
    if(!ori[r][c] || used[r][c]) return 0;
    
    int dr[6] = {1,1,0,-1,-1,0};
    int dc[6] = {0,1,1,0,-1,-1};
    
    used[r][c] = true;
    int res = 1;
    
    for(int i=0; i < 6; i++)
    {
        int j = (i+1)%6;
        int nr1 = r + dr[i];
        int nc1 = c + dc[i];
        
        int nr2 = r + dr[j];
        int nc2 = c + dc[j];
        
        if(0<= nr1 && nr1 < N && 0 <= nr2 && nr2 < N && 0 <= nc1 && nc1 < N && 0 <= nc2 && nc2 < N && ori[nr1][nc1] && ori[nr2][nc2])
        {
            res += getParts(nr1,nc1) + getParts(nr2,nc2);
        }
    }
    return res;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	HexagonPuzzle *obj;
	int answer;
	obj = new HexagonPuzzle();
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
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {".",".X","X..",".X.X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"X"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {".","..","...",".X.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20160;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {".","..","XXX","..X.",".X..X","XXXX..","..X.X.X","..X.XX.."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 108;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {".","..","...","....",".....","......",".......","........"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 261547992;
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