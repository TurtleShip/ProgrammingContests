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
#include <cassert>
using namespace std;

#define pb(x) push_back(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define SZ(c) int((c).size())
#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-8;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef long long LL;

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef struct Dir {
	int dr, dc;
	Dir() {};
	Dir(int _dr, int _dc) {
		dr = _dr;
		dc = _dc;
	}

	bool operator==(Dir other) {
		return dr == other.dr && dc == other.dc;
	}
} Dir;

Dir north = Dir(-1, 0);
Dir south = Dir( 1, 0);
Dir west  = Dir( 0,-1);
Dir east  = Dir( 0, 1);

/*
  Returns N by N spiral board.
  5 by 5 spiral board looks like this.
  13 12 11 10 25
  14 3  2  9  24
  15 4  1  8  23
  16 5  6  7  22
  17 18 19 20 21
*/
vector< vector<int> > makeSprial(int N) {
	assert(N%2 == 1); // N must be odd
  vector< vector<int> >board(N, vector<int>(N, 0));
	Dir dir[5]  = {north, west, south, east, north};
	int walk[5] =  {1,1,2,2,2};
	int delta[5] = {0,2,2,2,2};
	int curR = N/2;
	int curC = N/2;
	int num = 1;
	board[curR][curC] = num++;
	while(num < N*N) {
		// do the walk
		for(int i=0; i < 5; i++) {
			for(int j=0; j < walk[i]; j++) {
				curR += dir[i].dr;
				curC += dir[i].dc;
				board[curR][curC] = num++;
			}
		}

		// update walk
		for(int i=0; i < 5; i++)
			walk[i] += delta[i];
	}

  return board;
}

template<typename T>
void printBoard(vector< vector<T> >& board) {
	int R = board.size();
	int C = board[0].size();
	for(int r=0; r < R; r++) {
		for(int c=0; c < C; c++) {
			cout<<board[r][c];
		}
		cout<<endl;
	}
}

int main() {
	int N;
	LL P;

	while(cin>>N>>P && !(N == 0 && P == 0)) {
		if(N == 1) {
			cout<<"Line = 1, column = 1."<<endl;
			continue;
		}
		Dir dir[5]  = {north, west, south, east, north};
		int walk[5] =  {1,1,2,2,2};
		int delta[5] = {0,2,2,2,2};
		int targetR = 1;
		int targetC = 1;
		int curR = N/2;
		int curC = N/2;
		int ct = 0;
		LL num = 1ll;
		LL lowerN = 1ll;

		while( ((lowerN + 2) * (lowerN + 2)) < P  ) {
			lowerN += 2ll;
			curR--;
			curC++;
			ct++;
		}
		num = lowerN * lowerN;

		for(int i=0; i < 5; i++)
			walk[i] += delta[i] * ct;

		bool found = num == P;
		// do the walk
		for(int i=0; !found && i < 5; i++) {
			for(int j=0; !found && j < walk[i]; j++) {
				curR += dir[i].dr;
				curC += dir[i].dc;
				num += 1ll;
				found = num == P;
			}
		}

		targetC = curC + 1;
		targetR = N - curR;
		cout<<"Line = "<<targetR<<", column = "<<targetC<<"."<<endl;
	}

	return 0;
}
