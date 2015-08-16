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

int main() {
	int T;
	cin>>T;

	for(int cid=1; cid <=T; cid++) {
		int N, X;
		cin>>N>>X;
		vector<int> V(N, 0);
		for(int i=0; i < N; i++)
			cin>>V[i];

		sort( all(V) );

		int res = 0;
		int l = 0, r = N - 1;
		while(l < r) {
			if( V[r] + V[l] <= X ) {
				res++;
				r--;
				l++;
			} else {
				res++;
				r--;
			}
		}
		if(l == r) res++;
		printf("Case #%d: %d\n", cid, res);
	}
	return 0;
}
