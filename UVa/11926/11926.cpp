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

const int maxNum = 1000000;

bool hasStart[maxNum + 100];
bool hasEnd[maxNum + 100];

int main() {
  int N; // the number of one-time tasks.
  int M; // the number of repeating tasks.
  int st, end, dur;
  bool isGood;

  while(cin>>N>>M && !(N == 0 && M == 0)) {
    // initialize
    for(int i=0; i <= maxNum; i++) {
      hasStart[i] = hasEnd[i] = false;
    }
    isGood = true;

    for(int i=0; i < N; i++) {
      cin>>st>>end;

      isGood &= !hasStart[st] && !hasEnd[end];
      hasStart[st] = true;
      hasEnd[end] = true;
      for(int j=st+1; isGood && j < end; j++) {
        isGood &= !hasStart[j] && !hasEnd[j];
        hasStart[j] = hasEnd[i] = true;
      }
    }

    for(int i=0; i < M; i++) {
      cin>>st>>end>>dur;

      while(isGood && st <= maxNum) {
        isGood &= !hasStart[st] && !hasEnd[end];
        hasStart[st] = true;
        hasEnd[end] = true;
        for(int j=st+1; isGood && j < end && j <= maxNum; j++) {
          isGood &= !hasStart[j] && !hasEnd[j];
          hasStart[j] = hasEnd[i] = true;
        }
        st += dur;
        end += dur;
      }
    }

    if(isGood) cout<<"NO CONFLICT"<<endl;
    else cout<<"CONFLICT"<<endl;
  }

  return 0;
}
