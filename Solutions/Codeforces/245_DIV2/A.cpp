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
#define TRACE(x...) 
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define mp(x,y) make_pair(x,y)

const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-8;

typedef vector<int> VI;
typedef vector<double> vd;
typedef vector<VI> VVI;
typedef long long LL;

int main() {
	int N, M, coord;

	cin>>N>>M;
	vector< pair<int,int> > coordWithID(N);
	for(int i=0; i < N; i++) {
		cin>>coord;
		coordWithID[i] = mp(coord, i);
	}

	int l,r;
	for(int i=0; i < M; i++)
		cin>>l>>r;

	sort(all(coordWithID));
	vector< pair<int,int> >res(N);
	for(int i=0; i < N; i++) {
		res[i] = mp(coordWithID[i].second, i%2);
	}
	sort(all(res));
	for(int i=0; i < N; i++)
		cout<<res[i].second<<" ";
	cout<<endl;
	return 0;
}
