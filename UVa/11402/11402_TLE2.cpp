#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define TRACE(x...) 
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

typedef struct RangeInfo {
	int L;
	int R;
	int sum; // number of Buccaneer pirates in [L,R]

	RangeInfo() { 
		L = R = sum - 1; 
	}

	RangeInfo(int _L, int _R, int _sum) {
		L = _L;
		R = _R;
		sum = _sum;
	}

	bool operator==(RangeInfo other) {
		return L == other.L && R == other.R;
	}

	void printInfo() {
		WATCH(L);
		WATCH(R);
		WATCH(sum);
		TRACE(cout<<"==========="<<endl);
	}
} RangeInfo;

class SegmentTree {
private:
	vector<bool> record;
	vector<RangeInfo> segTree;
	int N;
	RangeInfo nullRange;

	int getLeft(int idx) { return idx << 1; }
	int getRight(int idx) { return (idx << 1) +1; }

	RangeInfo merge(RangeInfo left, RangeInfo right) {
		return RangeInfo(left.L, right.R, left.sum + right.sum);
	}

	void build(const int& idx, const int& L, const int& R) {
		if(L == R) {
			RangeInfo singleRange(L, R, (record[L] ? 1 : 0));
			segTree[idx] = singleRange;
		} else {
			build(getLeft(idx), L, (L+R) / 2);
			build(getRight(idx), (L+R)/2 + 1, R);
			RangeInfo left = segTree[getLeft(idx)];
			RangeInfo right = segTree[getRight(idx)];
			segTree[idx] = merge(left, right);
		}
		segTree[idx].printInfo();
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

	void update(const int& segTreeIdx, const int& recordIdx, const int& value) {
		if(segTreeIdx >= segTree.size() ||
			!(segTree[segTreeIdx].L <= recordIdx && recordIdx <= segTree[segTreeIdx].R))
			return;
		segTree[segTreeIdx].sum += value;
		update(getLeft(segTreeIdx), recordIdx, value);
		update(getRight(segTreeIdx), recordIdx, value);
	}

	void update(const int& idx, const bool& value) {
		if(record[idx] == value) return;
		record[idx] = value;
		int diff = (value) ? 1 : -1;
		update(1, idx, diff);
	}

public:
	SegmentTree(const vector<bool>& _record) {
		record = _record;
		N = record.size();
		segTree.resize(4*N);
		build(1, 0, N-1);
	}

	int rmq(const int& targetL, const int& targetR) {
		return rmq(1, targetL, targetR).sum;
	}

	void makeBuc(int L, int R) {
		for(int i=L; i <= R; i++)
			record[i] = true;
		build(1,0,N-1);
	}

	void makeBarbary(int L, int R) {
		for(int i=L; i <= R; i++)
			record[i] = false;
		build(1,0,N-1);
	}

	void flipThem(int L, int R) {
		for(int i=L; i <= R; i++)
			record[i] = !record[i];
		build(1,0,N-1);
	}
};

int main() {
	int T;
	cin>>T;

	for(int cid=1; cid<=T; cid++) {
		cout<<"Case "<<cid<<":"<<endl;
		int M, T;
		string line;
		cin>>M;

		vector<string> lines(M);
		vector<int> repeat(M);
		int totalPirates = 0;
		for(int i=0; i < M; i++) {
			cin>>repeat[i]>>lines[i];
			totalPirates += lines[i].size() * repeat[i];
		}
		vector<bool> isBuc(totalPirates);
		int cutoff = 0;
		for(int i=0; i < M; i++) {
			int L = lines[i].size();
			for(int j=0; j < L * repeat[i]; j++) {
				isBuc[cutoff + j] = lines[i][j % L] == '1';
			}
			cutoff += L * repeat[i];
		}

		SegmentTree segTree(isBuc);
		int Q;
		char cmd;
		int L, R;
		cin>>Q;
		int ansId = 1;

		for(int qid=1; qid<=Q; qid++) {
			cin>>cmd>>L>>R;
			if(cmd == 'F') segTree.makeBuc(L,R);
			else if(cmd == 'E') segTree.makeBarbary(L,R);
			else if(cmd == 'I') segTree.flipThem(L,R);
			else {
				cout<<"Q"<<ansId++<<": "<<segTree.rmq(L,R)<<endl;
			}
		}

	}


	return 0;
}