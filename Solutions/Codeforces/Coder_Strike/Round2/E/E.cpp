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

typedef long long ll;
typedef vector<int> vi;

const int maxCol = 200010;
const int maxID = 400010;
const int INF = 400010;

/*
  RangeInfo hold information from column L to column R
*/
typedef struct RangeInfo {
  /*
    dist[i][j] = The shortest path from
    (row i, column L) to (row j, column R)
  */
  int dist[2][2];
  int L; // leftmost column within this range
  int R; // rightmost column within this range
  RangeInfo()   {
    L = R = -1;
  }
  RangeInfo(int idx, const vector< vector<bool> >& isEmpty) {
    L = R = idx;
    dist[0][0] = isEmpty[0][idx] ? 0 : INF;
    dist[1][1] = isEmpty[1][idx] ? 0 : INF;
    dist[0][1] = dist[1][0] = (isEmpty[0][idx] && isEmpty[1][idx]) ? 1 : INF;
  }

  bool operator==(RangeInfo other) {
    return L == other.L && R == other.R;
  }
} RangeInfo;

class SegmentTree {
private:
  vector<RangeInfo> segTree;
  vector< vector<bool> > isEmpty;
  int N;
  RangeInfo nullRange;

  int getLeft(int idx) { return idx << 1; }
  int getRight(int idx) { return (idx << 1) + 1; }

  /*
    Merges information of RangeInfo "left" and RangeInfo "right".
    left.R must be one column left to right.L
  */
  RangeInfo merge(const RangeInfo& left, const RangeInfo& right) {
    RangeInfo result;
    result.L = left.L;
    result.R = right.R;
    for(int startRow = 0; startRow < 2; startRow++) {
      for(int endRow = 0; endRow < 2; endRow++) {
        result.dist[startRow][endRow] = INF;
        for(int midRow = 0; midRow < 2; midRow++) {
          result.dist[startRow][endRow] =
            min( result.dist[startRow][endRow],
                 left.dist[startRow][midRow] + 1 + right.dist[midRow][endRow] );
        }
      }
    }
    return result;
  }

  void build(int idx, int L, int R) {
    if(L == R) {
      RangeInfo singleRange(L, isEmpty);
      segTree[idx] = singleRange;
    } else {
      build(getLeft(idx), L, (L+R)/2);
      build(getRight(idx), (L+R)/2 + 1, R);
      RangeInfo left = segTree[getLeft(idx)], right = segTree[getRight(idx)];
      segTree[idx] = merge(left, right);
    }
  }

  RangeInfo rmq(const int& idx, const int& targetL, const int& targetR) {
    int curL = segTree[idx].L;
    int curR = segTree[idx].R;

    if(targetR < curL || curR < targetL) return nullRange;
    if(targetL <= curL && curR <= targetR) return segTree[idx];

    RangeInfo left = rmq(getLeft(idx), targetL, targetR);
    RangeInfo right = rmq(getRight(idx), targetL, targetR);

    if(left == nullRange) return right;
    if(right == nullRange) return left;

    RangeInfo result = merge(left, right);
    return result;
  }



public:
  SegmentTree(const vector< vector<bool> >& _isEmpty) {
    isEmpty = _isEmpty;
    N = isEmpty[0].size();

    segTree.resize(8*N);
    build(1, 0, N-1);
  }

  RangeInfo rmq(const int& targetL, const int& targetR) {
    return rmq(1, targetL, targetR);
  }
};

typedef struct Coord {
  int row, col;

  Coord(int& id, const int& N) {
    id--;
    row = id / N;
    col = id % N;
  }

} Coord;

int main() {
  int N, M;
  cin>>N>>M;
  vector< vector<bool> >isEmpty(2, vector<bool>(N, false));

  char cur;
  for(int r=0; r < 2; r++) {
    for(int c=0; c < N; c++) {
      cin>>cur;
      isEmpty[r][c] = cur == '.';
    }
  }
  SegmentTree segTree(isEmpty);

  int sourceId, targetId;
  for(int i=0; i < M; i++) {
    cin>>sourceId>>targetId;

    Coord left(sourceId, N);
    Coord right(targetId, N);
    if(left.col > right.col) {
      swap(left, right);
    }

    RangeInfo result = segTree.rmq(left.col, right.col);
    int shortestCost = result.dist[left.row][right.row];
    cout<<(shortestCost == INF ? -1 : shortestCost)<<endl;
  }


  return 0;
}
