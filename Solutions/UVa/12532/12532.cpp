#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

const int ZERO = 0;
const int NEGATIVE = -1;
const int POSITIVE = 1;
typedef struct RangeInfo {
	int L;
	int R;
	int numZero; // number of zeros
	int numPosi; // number of positive numbers
	int numNega; // number of negative numbers
	int product;

	RangeInfo() {L = R = product = -1;}
	RangeInfo(int _L, int _R, int _product) {
		L = _L;
		R = _R;
		numZero = numPosi = numNega = 0;
		product = _product;
		switch(product) {
			case ZERO: numZero++; break;
			case POSITIVE: numPosi++; break;
			case NEGATIVE: numNega++; break;
		}
	}

	bool operator==(RangeInfo other) {
		return L == other.L && R == other.R;
	}

	// oldValue != newValue should always be true
	void update(const int& oldValue, const int& newValue) {
		switch(oldValue) {
			case ZERO: numZero--; break;
			case POSITIVE: numPosi--; break;
			case NEGATIVE: numNega--; break;
		}

		switch(newValue) {
			case ZERO: numZero++; break;
			case POSITIVE: numPosi++; break;
			case NEGATIVE: numNega++; break;
		}

		if(numZero > 0) product = 0;
		else if(numNega % 2 == 1) product = -1;
		else product = 1;
	}
} RangeInfo;

class SegmentTree {
private:
	int N;
	vector<int> record;
	vector<RangeInfo> segTree;

	int getLeft(const int& idx) {
		return idx<<1;
	}

	int getRight(const int& idx) {
		return (idx<<1) + 1;
	}

	RangeInfo merge(const RangeInfo& left, const RangeInfo& right) {
		RangeInfo result(left.L, right.R, left.product * right.product);
		result.numZero = left.numZero + right.numZero;
		result.numPosi = left.numPosi + right.numPosi;
		result.numNega = left.numNega + right.numNega;
		return result;
	}

	void build(int idx, int L, int R) {
		// WATCH(idx);
		// WATCH(L);
		// WATCH(R);
		// TRACE(cout<<"========="<<endl);
		if(L == R) {
			segTree[idx] = RangeInfo(L, R, record[L]);
		} else {
			int mid = (L + R) / 2;
			int leftChild = getLeft(idx);
			int rightChild = getRight(idx);
			build(leftChild, L, mid);
			build(rightChild, mid+1, R);
			segTree[idx] = merge(segTree[leftChild], segTree[rightChild]);
		}
	}

	void update(const int& segIdx, const int& recordIdx, const int& oldValue, const int& newValue) {
		RangeInfo& curInfo = segTree[segIdx];
		if(curInfo.L <= recordIdx && recordIdx <= curInfo.R) {
			curInfo.update(oldValue, newValue);
			if(curInfo.L != curInfo.R) {
				update(getLeft(segIdx), recordIdx, oldValue, newValue);
				update(getRight(segIdx), recordIdx, oldValue, newValue);
			}
		}
	}

	int getProduct(const int& segIdx, const int& targetL, const int& targetR) {
		RangeInfo& curInfo = segTree[segIdx];
		int curL = curInfo.L;
		int curR = curInfo.R;
		if(targetL <= curL && curR <= targetR) {
			return curInfo.product;
		}

		if(targetR < curL || curR < targetL || curL == curR) {
			return POSITIVE;
		}

		int L = getProduct(getLeft(segIdx), targetL, targetR);
		int R = getProduct(getRight(segIdx), targetL, targetR);

		return L * R;
		
	}

public:
	SegmentTree(const vector<int>& _record) {
		record = _record;
		N = record.size();
		segTree.resize(4*N);
		build(1, 0, N-1);
	}

	void update(const int& idx, const int& value) {
		if(record[idx] == value) return; // no need to update

		update(1, idx, record[idx], value);
		// now actually update the record
		record[idx] = value;
	}

	char getProduct(const int& L, const int& R) {
		int result = getProduct(1, L, R);
		if(result == ZERO) return '0';
		if(result == NEGATIVE) return '-';
		return '+';
	}
};

int main() {
	int N, K, X, Y;
	char cmd;
	
	while(cin>>N>>K) {
		vector<int> record(N,0);
		for(int i=0; i < N; i++) {
			cin>>record[i];
			if(record[i] < 0) record[i] = NEGATIVE;
			else if(record[i] > 0) record[i] = POSITIVE;
		}
		SegmentTree segTree(record);
		string result;

		while(K--) {
			cin>>cmd>>X>>Y;
			// WATCH(cmd);
			// WATCH(X);
			// WATCH(Y);
			if(cmd == 'C') segTree.update(X-1, (Y > 0) ? POSITIVE : (Y == 0) ? ZERO : NEGATIVE);
			else result.push_back(segTree.getProduct(X-1,Y-1));
		}
		cout<<result<<endl;
	}
	return 0;
}