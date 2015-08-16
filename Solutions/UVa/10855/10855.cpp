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

int howMany(const vector<string>& big, const vector<string>& small) {
	int res = 0;
	int bigN = SZ(big);
	int smallN = SZ(small);

	for(int r=0; r < (bigN - (smallN - 1)); r++) {
		for(int c=0; c < (bigN - (smallN -1)); c++) {
			bool isGood = true;
			for(int rr=0; isGood && rr < smallN; rr++) {
				for(int cc=0; isGood && cc < smallN; cc++) {
					isGood &= big[r+rr][c+cc] == small[rr][cc];
				}
			}
			if(isGood) res++;
		}
	}
	return res;
}

void rotate90(vector<string>& board) {
	int N = board.size();
	vector<string> copied(board.begin(), board.end());

	for(int r=0; r < N; r++) {
		for(int c=0; c < N; c++) {
			board[c][N-1-r] = copied[r][c];
		}
	}
}

void printBoard(vector<string>& board) {
	int N = board.size();
	for(int r=0; r < N; r++) {
		for(int c=0; c < N; c++) {
			cout<<board[r][c];
		}
		cout<<endl;
	}
	cout<<endl;
}
int main() {
	int bigN, smallN;



	while( (cin>>bigN>>smallN) && smallN != 0) {
		vector<string> big(bigN, "");
		vector<string> small(smallN, "");

		for(int i=0; i < bigN; i++)
			cin>>big[i];

		for(int i=0; i < smallN; i++)
			cin>>small[i];


		for(int i=0; i < 4; i++) {
			if(i != 0) cout<<" ";
			cout<<howMany(big, small);
			rotate90(small);
		}
		cout<<endl;
	}

	return 0;
}
