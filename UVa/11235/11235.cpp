#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Number "number" appears consecutively in [L,R]
 * and "size" is the size of the range (= R - L + 1)
 */
typedef struct FreqInfo {
	int L;
	int R;
	int number;
	int size;

	FreqInfo() {
		L = R = size = - 1;
	}

	FreqInfo(int _L, int _R, int _number) {
		L = _L; R = _R; number = _number;
		size = R - L + 1;
	}
} FreqInfo;

FreqInfo getMax(const FreqInfo& a, const FreqInfo& b) {
	return (a.size > b.size) ? a : b;
}

typedef struct RangeInfo {
	int L;
	int R;
	FreqInfo maxFreq;
	FreqInfo leftFreq;
	FreqInfo rightFreq;

	RangeInfo() {
		L = R = -1;
	}

	RangeInfo(int _L, int _R, FreqInfo _maxFreq) {
		L = _L;
		R = _R;
		maxFreq = _maxFreq;
		leftFreq = maxFreq;
		rightFreq = maxFreq;
	}

	bool operator==(RangeInfo other) {
		return L == other.L && R == other.R;
	}
} RangeInfo;

class SegmentTree {

	private:
		vector<RangeInfo> segTree;
		vector<int> record;
		RangeInfo nullRange;
		
		int getLeft(int idx) {
			return idx << 1;
		}

		int getRight(int idx) {
			return (idx << 1) + 1;
		}

		RangeInfo merge(const RangeInfo& left, const RangeInfo& right) {
			RangeInfo result;
			result.L = left.L;
			result.R = right.R;
			result.leftFreq = left.leftFreq;
			result.rightFreq = right.rightFreq;
			result.maxFreq = getMax(left.maxFreq, right.maxFreq);

			// check for connecting numbers
			if(left.rightFreq.number == right.leftFreq.number) {
				FreqInfo newFreqInfo(left.rightFreq.L, right.leftFreq.R, left.rightFreq.number);
				if(result.leftFreq.number == newFreqInfo.number) {
					result.leftFreq = newFreqInfo;
				}
				if(result.rightFreq.number == newFreqInfo.number) {
					result.rightFreq = newFreqInfo;
				}

				if(newFreqInfo.size > result.maxFreq.size) {
					result.maxFreq = newFreqInfo;
				}
			}
			return result;
		}

		void build(const int& idx, const int& L, const int& R) {
			
			if(L == R) {
				RangeInfo singleRange(L, R, FreqInfo(L,R,record[L]));
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
		SegmentTree(const vector<int>& _record) {
			record = _record;
			segTree.resize(4*record.size());
			build(1, 0, record.size() -1);
		}

		int rmq(const int& targetL, const int& targetR) {
			 FreqInfo info = rmq(1, targetL, targetR).maxFreq;
			 return info.size;
		}
};

int main() {
	int N, Q, L, R;
	while(cin>>N>>Q) {
		vector<int>record(N);
		for(int i=0; i < N; i++)
			cin>>record[i];
		SegmentTree segTree(record);
		
		while(Q--) {
			cin>>L>>R;
			L--; R--;
			cout<<segTree.rmq(L,R)<<endl;

		}

	}
	return 0;
}
