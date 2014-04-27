#include <cstdio>
#include <algorithm>
using namespace std;

char board[55][55];
char testBoard[55][55];
int adjacentMove[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

void printBoard(const int&, const int&);
bool isInBound(const int&, const int&, const int&, const int&);
void revealAdjacentCell(const int&, const int&, const int&, const int&);
bool isThisBoardPossible(const int&, const int&);
bool isSolvable(const int&, const int&, const int&);

int main() {
	
	int T, R, C, M;
	scanf("%d", &T);

	for(int cid=1; cid <= T; cid++) {
		scanf("%d %d %d", &R, &C, &M);
		printf("Case #%d:\n", cid);
		if(isSolvable(R,C,M)) {
			printBoard(R, C);
		} else {
			// printBoard(R, C);
			printf("Impossible\n");
		}
	}

	return 0;
}

void printBoard(const int& nR, const int& nC) {
	for(int r=0; r < nR; r++) {
		for(int c=0; c < nC; c++)
			printf("%c", board[r][c]);
		printf("\n");
	}
}

bool isInBound(const int& curRow, const int& curCol, const int& nR, const int& nC) {
	return 0 <= curRow && curRow < nR && 0 <= curCol && curCol < nC;
}

// helper function for isThisBoardPossible
void revealAdjacentCell(const int& curRow, const int& curCol, const int& nR, const int& nC) {
	bool canRevealOthers = true;
	for(int i=0; i < 8; i++) {
		int nextRow = curRow + adjacentMove[i][0];
		int nextCol = curCol + adjacentMove[i][1];
		if(isInBound(nextRow, nextCol, nR, nC)) {
			canRevealOthers &= testBoard[nextRow][nextCol] != '*';
		}
	}

	if(canRevealOthers) {
		for(int i=0; i < 8; i++) {
			int nextRow = curRow + adjacentMove[i][0];
			int nextCol = curCol + adjacentMove[i][1];
			if(isInBound(nextRow, nextCol, nR, nC)
				&& testBoard[nextRow][nextCol] == '.') {
				testBoard[nextRow][nextCol] = 'c';
			revealAdjacentCell(nextRow, nextCol, nR, nC);
			}
		}
	}
}

/*
	Checks if the current board configuration
	is good enough to win. We will click the
	bottom right corner and see if we can reveal
	all other numbers.
	Runs in O(R*C). In worst case, 50*50 = 2,500
*/
bool isThisBoardPossible(const int& nR, const int& nC) {
	for(int r=0; r < nR; r++)
		for(int c=0; c < nC; c++)
			testBoard[r][c] = board[r][c];
	
	testBoard[nR-1][nC-1] = 'c';
	revealAdjacentCell(nR-1, nC-1, nR, nC);
	
	bool allRevealed = true;
	for(int r=0; allRevealed && r < nR; r++)
		for(int c=0; allRevealed && c < nC; c++)
			allRevealed &= testBoard[r][c] != '.';

	return allRevealed;
}

/*
	Returns true if it is possible to solve.
*/
bool isSolvable(const int& nR, const int& nC, const int& M) {

	// initialize board
	for(int r=0; r < nR; r++)
		for(int c=0; c < nC; c++)
			board[r][c] = '.';

	int mineLeft = M;
	/*
		Google contest analysis states that
			"In a valid mine configuration, 
			 Condition 1) the number of mines in a particular row is always 
			              equal or larger than the number of mines of the rows below it.
			 Condition 2) all the mines are left-aligned in a row."

		My strategy is
		1) Try filling each row completely with mines from top to bottom,
		   but leave at least 3 bottom rows intact.
		   
		2) Fill remaining columns left to right.
	*/
	
	int lastRow = 0;
	while(nC <= mineLeft && lastRow < nR-3) {		
		fill(board[lastRow], board[lastRow] + nC, '*');
		mineLeft -= nC;
		lastRow++;
	}

	/*
		We have less than nC mines left to place.
		Need to determine how many mines to place in the lastRow.
		Try all possibility.
	*/
	for(int numMineLastRow = 0; numMineLastRow <= min(mineLeft, nC); numMineLastRow++) {

		for(int c=0; c < numMineLastRow; c++) {
			board[lastRow][c] = '*';
			mineLeft--;
		}

		for(int c=0; 0 < mineLeft && c < nC; c++) {
			for(int r=lastRow; 0 < mineLeft && r < nR; r++) {
				if(board[r][c] == '*') continue;
				board[r][c] = '*';
				mineLeft--;
			}
		}
	
		if(isThisBoardPossible(nR,nC)) break;
		// clean up
		for(int r=lastRow; r < nR; r++) {
			for(int c=0; c < nC; c++) {
				if(board[r][c] == '*') {
					board[r][c] = '.';
					mineLeft++;
				}
			}
		}
	}
	

	// we click the bottom right corner
	board[nR-1][nC-1] = 'c';
	return mineLeft == 0 && isThisBoardPossible(nR, nC);
}
	