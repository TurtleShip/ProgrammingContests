#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

template<class T>
class SegmentTree {

public:
  typedef struct RangeInfo {
    int L;
    int R;
    T info;
    RangeInfo() {
      L = R = info = -1;
    }

    RangeInfo(int _L, int _R, T _info) {
      L = _L; R = _R; info = _info;
    }

    bool operator==(RangeInfo other) {
      return L == other.L && R == other.R;
    }

  } RangeInfo;

private:
  vector<RangeInfo> segTree;
  vector<T> record;
  int N;
  RangeInfo nullRange;

  int getLeft(int idx) { return idx << 1; }
  int getRight(int idx) { return (idx << 1) + 1; }

  /*
    Merge information of RangeInfo "left" and RangeInfo "right".
    left.R == (right.L - 1) must be satisfied.
    Modify this function to suit our need.
  */
  RangeInfo merge(const RangeInfo& left, const RangeInfo& right) {
    RangeInfo result;
    result.L = left.L;
    result.R = right.R;

    // Change here to suit your need
    result.info = min(left.info, right.info);
    return result;
  }

  void build(const int& idx, const int& L, const int& R) {
    if(L == R) {
      RangeInfo singleRange(L, R, record[L]);
      segTree[idx] = singleRange;
    } else {
      build(getLeft(idx), L, (L+R)/2);
      build(getRight(idx), (L+R)/2 + 1, R);
      RangeInfo left = segTree[getLeft(idx)];
      RangeInfo right = segTree[getRight(idx)];
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
  SegmentTree(const vector<T>& _record) {
    record = _record;
    N = record.size();
    segTree.resize(4*N);
    build(1, 0, N-1);
  }

  RangeInfo rmq(const int& targetL, const int& targetR) {
    return rmq(1, targetL, targetR);
  }
};

int main() {

  int arr[] = {10, 8, 55, -3, 55, 12, 100, -90, 30};
  int N = sizeof(arr) / sizeof(arr[0]);
  vector<int> V(arr, arr + N);

  SegmentTree<int> segTree(V);

  for(int i=0; i < N; i++) {
    for(int j=i+1; j < N; j++) {
      SegmentTree<int>::RangeInfo rangeInfo = segTree.rmq(i, j);
      int actual = arr[i];
      for(int k=i+1; k <= j; k++) {
        actual = min(actual, V[k]);
      }
      assert(actual == rangeInfo.info);
    }
  }


  return 0;
}
