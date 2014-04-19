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
 
class CuttingGlass {
public:
	int pieces(int, int, int, int, vector <string>);
};

const int maxL = 1100;
const int pad = 10;
/*
 move[x][y][0] = true if can move to the left (x-1, y)
 move[x][y][1] = true if can move to the right(x+1, y)
 move[x][y][2] = true if can move to the up(x,y-1)
 move[x][y][3] = true if can move to the down(x,y+1)
 */
bool move[maxL][maxL][4];
bool vis[maxL][maxL];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(int,int);
void bfs(int,int);

int CuttingGlass::pieces(int W, int H, int startx, int starty, vector <string> program) {
	
    int res = 0;
    memset(move, false, sizeof(move));
    memset(vis, false, sizeof(vis));
    for(int x=0; x < W; x++)
        for(int y=0; y < H; y++)
            for(int k=0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(0 <= nx && nx < W && 0 <= ny && ny < H)
                    move[x+pad][y+pad][k] = true;
            }
    
    string pro = "";
    for(int i=0; i < program.size(); i++)
        pro += program[i];
    
    int sx = startx + pad;
    int sy = starty + pad;
    
    for(int i=0; i < pro.size(); i++)
    {
        if(pro[i] == 'L') {
            move[sx-1][sy-1][3] = move[sx-1][sy][2] = false;
            sx--;
        }
        else if(pro[i] == 'R')
        {
            move[sx][sy-1][3] = move[sx][sy][2] = false;
            sx++;
        }
        else if(pro[i] == 'U')
        {
            move[sx-1][sy-1][1] = move[sx][sy-1][0] = false;
            sy--;
        }
        else if(pro[i] == 'D')
        {
            move[sx-1][sy][1] = move[sx][sy][0] = false;
            sy++;
        }
    }
    
    for(int x=0; x < W; x++)
        for(int y=0; y < H; y++)
            if(!vis[x+pad][y+pad])
            {
                res++;
                dfs(x+pad, y+pad);
                cout<<endl;
            }
    
    return res;
}


void dfs(int x, int y)
{
    
    vis[x][y] = true;
    stack<int> S;
    S.push(x); S.push(y);
    
    while(!S.empty())
    {
        int cy = S.top(); S.pop();
        int cx = S.top(); S.pop();
        
        for(int i=0; i < 4; i++)
            if(move[cx][cy][i])
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(!vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    S.push(nx);
                    S.push(ny);
                }
            }
    }
}


void bfs(int x, int y)
{
    vis[x][y] = true;
    queue<int> Q;
    Q.push(x); Q.push(y);
    
    while(!Q.empty())
    {
        int cx = Q.front(); Q.pop();
        int cy = Q.front(); Q.pop();
        
        for(int i=0; i < 4; i++)
        {
            if(move[cx][cy][i])
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(!vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    Q.push(nx); Q.push(ny);
                }
            }
        }
    }
}
 
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, vector <string> p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p4[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	CuttingGlass *obj;
	int answer;
	obj = new CuttingGlass();
	clock_t startTime = clock();
	answer = obj->pieces(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	vector <string> p4;
	int p5;
	
	{
	// ----- test 0 -----
	p0 = 100;
	p1 = 100;
	p2 = 50;
	p3 = 50;
	string t4[] = {"ULDR"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	p1 = 10;
	p2 = 3;
	p3 = 4;
	string t4[] = {"UDUDUDUDUDU"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 3;
	p2 = 0;
	p3 = 0;
	string t4[] = {"RDDDUUU","RDDDUUU","R","DLLLRRR","DLLL"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 9;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 3;
	p2 = 5;
	p3 = 3;
	string t4[] = {"LULLULLU"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 2;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
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
