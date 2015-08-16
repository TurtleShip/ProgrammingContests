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
 
class FloorBoards {
public:
	int layout(vector <string>);
};

/*
 1 <= R <= 10
 1 <= C <= 10
 */
int R;
int C;
int mem[11][60000];
int hori[60000]; //hori[i] = number of horizontal strips in number i
int pow3[11];
int get3[60000][10];
int set3[60000][10][3];
vector<string> room;

void preComute()
{
    pow3[0] = 1;
    for(int i=1; i <= C; i++)
        pow3[i] = 3 * pow3[i-1];
    
    for(int i=0; i < pow3[C]; i++)
        for(int j=0; j < C; j++)
            get3[i][j] = (i / pow3[j]) % 3;
    
    for(int i=0; i < pow3[C]; i++)
        for(int j=0; j < C; j++)
            for(int k=0; k < 3; k++)
                set3[i][j][k] = i + (k - get3[i][j]) * pow3[j];
}

int countHori(int mask)
{
    int ans = 0;
    bool isHori = false;
    for(int i=0; i < C; i++)
    {
        if(get3[mask][i] == 0)
        {
            if(!isHori)
            {
                isHori = true;
                ans++;
            }
        }
        else
        {
            isHori = false;
        }
    }
    return ans;
}

void fillHori()
{
    for(int i=0; i < pow3[C]; i++)
        hori[i] = countHori(i);
}
/*
 Given we are at (idx)th row, and previous row has shape of "mask" and
 used "numBoard" so far, return the minimum possible number.
 (i)th bit of mask is
 0 if (i)th column of the current row is a part of a horizontal strip
 1 if (i)th column of the current row is a part of a vertical strip
 2 if (i)th column of the current row is a pillar
 */
int rec(int idx, int mask)
{
    int& res = mem[idx][mask];
    if(res != -1) return res;
    
    if(idx == R)
    {
        res = 0;
        return res;
    }
    
    res = INF;
    for(int i=0; i < pow3[C]; i++)
    {
        //check validity of the current string
        bool isValid = true;
        for(int j=0; j < C; j++)
        {
            if((get3[i][j] == 2 && room[idx][j] == '.') || (get3[i][j] != 2 && room[idx][j] == '#'))
            {
                isValid = false;
                break;
            }
        }
        if(!isValid) continue;
        
        //count horizontal strip
        int horiNum = hori[i];
        
        //count vertical strip
        int vertNum = 0;
        for(int j=0; j < C; j++)
        {
            if(get3[i][j] == 1 && get3[mask][j] != 1)
                vertNum++;
        }
        
        res = min( res, horiNum + vertNum + rec(idx+1, i) );
    }
    
    return res;

}


/*
 We will go through each row, and try every combination.
 O(R * 3^C) => Worst : 10 * 3^10 = 590,490  Small enough
 */
int FloorBoards::layout(vector <string> _room) {
    
    room = _room;
    R = room.size();
    C = room[0].size();
    
    preComute();
    fillHori();
    
    memset(mem, -1, sizeof(mem));
    
    /*
     (-1)th row will be all pillars. 
     This way, (-1)th row does not affect 0th row.
     */
    return rec(0, pow3[C] - 1);


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
	FloorBoards *obj;
	int answer;
	obj = new FloorBoards();
	clock_t startTime = clock();
	answer = obj->layout(p0);
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
	string t0[] = {".....",".....",".....",".....","....."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {".......",".#..##.",".#.....",".#####.",".##..#.","....###"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 7;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"####","####","####","####"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"...#..","##....","#.#...",".#....","..#...","..#..#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {".#....","..#...",".....#","..##..","......",".#..#."};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 9;
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