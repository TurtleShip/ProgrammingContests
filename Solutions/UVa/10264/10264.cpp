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

int corners[(1<<15) + 10];
int potencies[(1<<15) + 10];
int main() {
  int N;
  const int maxN = 14;

  while(cin>>N) {
    int maxCoord = 1<<N;
    
    for(int i=0; i < maxCoord; i++)
      cin>>corners[i];

    for(int i=0; i < maxCoord; i++) {
      int curSum = 0;
      for(int j=0; j < N; j++) {
        int neighbor = i ^ (1<<j);
        curSum += corners[neighbor];
      }
      potencies[i] = curSum;
    }

    int res = 0;

    for(int i=0; i < maxCoord; i++) {
      for(int j=0; j < N; j++) {
        int neighbor = i ^ (1<<j);
        if(neighbor > i) {
          res = max(res, potencies[i] + potencies[neighbor]);
        }
      }
    }

    cout<<res<<endl;
  }

  return 0;
}
