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

int arr[3][3];
int adjMove[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

bool isZeros() {
  bool allZero = true;
  for(int r=0; allZero && r < 3; r++)
    for(int c=0; allZero && c < 3; c++)
      allZero &= arr[r][c] == 0;
  return allZero;
}

void funcArr() {
  int prev[3][3];
  for(int r=0; r < 3; r++)
    for(int c=0; c < 3; c++)
      prev[r][c] = arr[r][c];

  for(int r=0; r<3; r++) {
    for(int c=0; c< 3; c++) {
      int sum = 0;
      for(int i=0; i < 4; i++) {
        int nextR = r + adjMove[i][0];
        int nextC = c + adjMove[i][1];
        if(0 <= nextR && nextR < 3 && 0 <= nextC && nextC < 3)
          sum += prev[nextR][nextC];
        arr[r][c] = sum % 2;
      }
    }
  }
}

void printBoard() {
  for(int r=0; r < 3; r++) {
    for(int c=0; c < 3; c++) {
      cout<<arr[r][c];
    }
    cout<<endl;
  }
  cout<<"============="<<endl;
}
int main() {
  int T;
  cin>>T;

  while(T--) {
    int res = -1;
    string str;
    for(int r=0; r < 3; r++) {
      cin>>str;
      for(int c=0; c<3; c++) {
        arr[r][c] = str[c] - '0';
      }
    }

    while(!isZeros()) {
      res++;
      funcArr();
    }

    cout<<res<<endl;
  }
  return 0;
}
