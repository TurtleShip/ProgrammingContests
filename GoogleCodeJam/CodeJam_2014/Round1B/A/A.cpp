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
string trimString(string str) {
	string res = "";
	res.push_back(str[0]);

	for(int i=1; i < str.size(); i++) {
		if(str[i] != str[i-1]) {
			res.pb(str[i]);
		}
	}
	return res;
}

int findUnique(string str) {
	int res = 1;
	for(int i=1; i < str.size(); i++) {
		if(str[i] != str[i-1]) res++;
	}
	return res;
}

int main() {
	int T;
	cin>>T;

	for(int cid=1; cid <= T; cid++){
		int N;
		cin>>N;
		vector<string> V(N, "");

		for(int i=0; i < N; i++) {
			cin>>V[i];
		}
		// vector<string> trimmed(N,"");
		string trimmed = trimString(V[0]);
		bool isPossible = true;
		for(int i=1; isPossible && i < N; i++) {
			string cur = trimString(V[i]);
			isPossible &= trimmed == cur;
		}

		cout<<"Case #"<<cid<<": ";

		if(isPossible) {

			int L = findUnique(V[0]);
			vector< vector<int> > allLen(N, vector<int>(L, 99999));

			for(int i=0; i < N; i++) {
				string cur = V[i];
				int len = 1;
				int pos = 0;
				// cout<<"cur : "<<cur<<endl;
				for(int j=1; j < cur.size(); j++) {
					if(cur[j] != cur[j-1]) {
						allLen[i][pos] = len;
						// minLen[pos] = min(minLen[pos], len);

						// printf("minLen[%d] = %d\n", pos, minLen[pos]);
						pos++;
						len = 1;

					} else {
						len++;
					}
				}
				if(pos < L) {
					allLen[i][pos] = len;
					// printf("minLen[%d] = %d\n", pos, minLen[pos]);
				}
			}

			// try all
			int res = 0;
			for(int pos = 0; pos < L; pos++) {
				// try all possible string position
				int posRes = INF;
				for(int i=0; i < N; i++) {
					int curRes = 0;
					for(int j=0; j < N; j++) {
						curRes += abs(allLen[j][pos] - allLen[i][pos]);
					}
					posRes = min(posRes, curRes);
				}
				res += posRes;
			}
			cout<<res<<endl;

		} else {
			cout<<"Fegla Won"<<endl;
		}


	}

	return 0;
}
