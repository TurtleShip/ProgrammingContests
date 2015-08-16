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

/*
	returns
	-1 : if x <= y
	 0 : x == y
	 1 : x > y
*/
int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

// Removes duplicates in the given vector.
// Note that the ORDER of elements is NO LONGER preserved.
template<typename T>
void makeUnique(vector<T>& V) {
	sort(V.begin(), V.end());
	V.resize( distance(V.begin(), unique(V.begin(), V.end())));
}

// Readline using scanf : scanf("%[^\n]\n", input);

// print 4 decimal places ( need to #include <iomanip> )
// cout<<fixed<<setprecision(4)<<doubleValue<<endl;

int x[300*300+10];
int y[300*300+10];

int main() {
	int R,C,K;

	cin>>R>>C>>K;
	bool goingRight = true;
	int tile = 0;
	for(int r=1; r <= R; r++) {
		if(goingRight) {
			for(int c=1; c <= C; c++) {
				x[tile]=r;
				y[tile]=c;
				tile++;
			}
		} else {
			for(int c=C; c >= 1; c--) {
				x[tile]=r;
				y[tile]=c;
				tile++;
			}
		}
		goingRight = !goingRight;
	}
	tile = 0;
	for(int i=0; i < K-1; i++) {
		cout<<2<<" ";
		cout<<x[tile]<<" ";
		cout<<y[tile]<<" ";
		tile++;
		cout<<x[tile]<<" ";
		cout<<y[tile]<<" ";
		tile++;
		cout<<endl;
	}
	cout<<(R*C - tile)<<endl;
	while(tile < R*C) {
		cout<<x[tile]<<" ";
		cout<<y[tile]<<" ";
		tile++;
	}
	cout<<endl;

	return 0;
}
