#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int pos[10];
int cur[10];
bool rowTaken[10];
bool leftDiag[20];
bool rightDiag[20];

void mark(const int& row, const int& col, const bool& flag) {
	rowTaken[row] = flag;
	leftDiag[row - col + 8]  = flag;
	rightDiag[row + col] = flag;
}

bool isOccupied(const int& row, const int & col) {
	return rowTaken[row] || leftDiag[row - col + 8] || rightDiag[row + col];
}

int findBest(const int& col) {
	if(col > 8) { // we've passed all columns
		int res = 0;
		for(int i=1; i <= 8; i++)
			if(cur[i] != pos[i])
				res++;
		return res;
	} else {
		int res = 10;
		for(int row=1; row <= 8; row++) {
			if(!isOccupied(row, col)) {
				mark(row, col, true);
				cur[col] = row;
				res = min(res, findBest(col + 1));
				mark(row, col, false);
			}
		}
		return res;
	}
}
int main() {
	int cid = 1;
	while(scanf("%d %d %d %d %d %d %d %d\n",
		&pos[1], &pos[2], &pos[3], &pos[4], &pos[5], &pos[6], &pos[7], &pos[8])
		!= EOF) {

		memset(rowTaken, false, sizeof(rowTaken));
		memset(leftDiag, false, sizeof(rightDiag));
		memset(rightDiag, false, sizeof(rightDiag));
		int res = findBest(1);
		printf("Case %d: %d\n", cid++, res);

	}

	return 0;


}