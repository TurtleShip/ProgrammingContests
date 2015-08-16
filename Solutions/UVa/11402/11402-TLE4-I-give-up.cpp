#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

const char NO_CHANGE = 'N';
const char FLIP = 'I';
const char BUC = 'F';
const char BARBARY = 'E';
	
typedef struct RangeInfo {

	int L;
	int R;
	int len; // R - L + 1
	int sum; // number of Buccaneer pirates in [L,R]
	char state; // state represnts the state that need to be updated

	RangeInfo() { 
		L = R = len = sum - 1;
		state = NO_CHANGE;
	}

	RangeInfo(int _L, int _R, int _sum) {
		L = _L;
		R = _R;
		len = R - L + 1;
		sum = _sum;
		state = NO_CHANGE;
	}

	bool operator==(RangeInfo other) {
		return L == other.L && R == other.R;
	}

	void markUpdate(const char updateType) {
		if(updateType == FLIP) {
			switch(state) {
				case NO_CHANGE: state = FLIP; break;
				case FLIP: state = NO_CHANGE; break;
				case BUC: state = BARBARY; break;
				case BARBARY: state = BUC; break;	
			}
		} else {
			state = updateType;
		}
	}

	void update() {
		switch(state) {
			case FLIP:
			sum = len - sum;
			break;

			case BUC:
			sum = len;
			break;

			case BARBARY:
			sum = 0;
			break;
		}

		// TRACE(cout<<"UPDATE : "<<state<<endl);
		// we did the udpate
		state = NO_CHANGE;
	}

	void printInfo() {
		WATCH(L);
		WATCH(R);
		WATCH(sum);
		WATCH(state);
		// TRACE(cout<<"==========="<<endl);
	}
} RangeInfo;

class SegmentTree {
private:
	vector<bool> record;
	vector<RangeInfo> segTree;
	int N;
	RangeInfo nullRange;

	int getLeft(int idx) { return idx << 1; }
	int getRight(int idx) { return (idx << 1) + 1; }

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
		// segTree[idx].printInfo();
	}

	RangeInfo rmq(const int& idx, const int& targetL, const int& targetR) {
		int curL = segTree[idx].L;
		int curR = segTree[idx].R;

		if(segTree[idx].state != NO_CHANGE) {
			markChildren(idx, segTree[idx].state);
			segTree[idx].update();	
		}

		if(targetR < curL || curR < targetL) return nullRange;

		if(targetL <= curL && curR <= targetR) return segTree[idx];

		RangeInfo left = rmq(getLeft(idx), targetL, targetR);
		RangeInfo right = rmq(getRight(idx), targetL, targetR);

		if(left == nullRange) return right;
		if(right == nullRange) return left;

		segTree[idx].sum = left.sum + right.sum;
		return segTree[idx];
	}

	bool isLeaf(const RangeInfo& info) {
		return info.L == info.R;
	}

	void markChildren(const int idx, const char updateType) {
		if(!isLeaf(segTree[idx])) {
			segTree[getLeft(idx)].markUpdate(updateType);
			segTree[getRight(idx)].markUpdate(updateType);	
		}
	}
	
	void update(const int& idx, const int& targetL, const int& targetR, const char& updateType) {
		int curL = segTree[idx].L;
		int curR = segTree[idx].R;

		if(targetL <= curL && curR <= targetR) segTree[idx].markUpdate(updateType);

		if(segTree[idx].state != NO_CHANGE) {
			markChildren(idx, segTree[idx].state);
			segTree[idx].update();	
		}
		
		if(targetL <= curL && curR <= targetR) return;

		if(targetR < curL || curR < targetL) return; // out of range
		
		if(!isLeaf(segTree[idx])) {
			update(getLeft(idx), targetL, targetR, updateType);
			update(getRight(idx), targetL, targetR, updateType);	
			segTree[idx].sum = segTree[getLeft(idx)].sum + segTree[getRight(idx)].sum;	
		}
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

	void update(const int& targetL, const int& targetR, const char& updateType) {
		update(1, targetL, targetR, updateType);
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
		// cout<<"YO"<<endl;
		for(int qid=1; qid<=Q; qid++) {
			cin>>cmd>>L>>R;
			// cout<<cmd<<" "<<L<<" "<<R<<endl;
			if(cmd == 'S') {
				cout<<"Q"<<ansId++<<": "<<segTree.rmq(L,R)<<endl;
			} else {
				// TRACE(cout<<"UPDATE FOR "<<cmd<<endl);
				segTree.update(L, R, cmd);
				// TRACE(cout<<"+++++++++++++++++++++++++"<<endl);
			}
			// segTree.printTree();
			// cout<<endl;
		}

	}


	return 0;
}