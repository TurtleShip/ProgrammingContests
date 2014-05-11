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

// Removes duplicates in the given vector.
// Note that the ORDER of elements is NO LONGER preserved.
template<typename T>
void makeUnique(vector<T>& V) {
	sort(V.begin(), V.end());
	V.resize( distance(V.begin(), unique(V.begin(), V.end())));
}

// Readline using scanf : scanf("%[^\n]\n", input);
int solve(const vector<int>& V, const int& N, const int& idx, const int& ballColor) {

	int left = idx;
	int right = idx;
	while(left >= 0 && V[left] == ballColor)
		left--;
	while(right < N && V[right] == ballColor)
		right++;

	int ct = right - left ;

	if(ct >= 3) {
		int res = ct-1;
		bool canDelete = true;
		vi curV;
		for(int i=0; i <= left; i++)
			curV.pb(V[i]);
		for(int i=right; i < N; i++)
			curV.pb(V[i]);

		while(canDelete) {
			canDelete = false;

			for(int i=0; !canDelete && i < curV.size(); i++) {
				int color = curV[i];
				int right = i+1;
				while(right < curV.size() && curV[right] == color) {
					right++;
				}
				canDelete |= (right - i) >= 3;
				if(canDelete) {
					res += right - i;
					vi prevV( all(curV) );
					curV.clear();
					for(int j=0; j < i; j++)
						curV.pb(prevV[j]);
					for(int j=right; j < prevV.size(); j++)
						curV.pb(prevV[j]);
				}
			}
		}
		return res;
	}
	return -1;
}

int main() {
	int N, K, ballColor;
	cin>>N>>K>>ballColor;
	vector<int> V(N);
	for(int i=0; i < N; i++)
		cin>>V[i];

	// int solve(const vector<int>& V, const int& N, const int& idx, const int& ballColor) {
	int res = 0;
	for(int i=0; i < N; i++) {
		res = max(res, solve(V, N, i, ballColor));
	}
	cout<<res<<endl;

	return 0;
}
