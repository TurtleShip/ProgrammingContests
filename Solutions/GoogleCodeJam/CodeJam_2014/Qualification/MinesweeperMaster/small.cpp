#include <cstdio>
using namespace std;

char board[55][55];
char testBoard[55][55];
char result[55][55];

bool foundPossibleConfigGlobal = false;

int adjacentMove[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

void printResultBoard(int, int);
bool isInBound(int, int, int, int);
void revealAdjacentCell(int, int, int, int);
bool isThisBoardPossible(int, int);
bool isPossibleRecursive(int, int, int, int, int, int, int);
bool solveUsingBruteForce(int, int, int);

int main() {
	
	int T, R, C, M;
	scanf("%d", &T);

	for(int cid=1; cid <= T; cid++) {
		scanf("%d %d %d", &R, &C, &M);
		bool isPossible = solveUsingBruteForce(R, C, M);
		printf("Case #%d:\n", cid);
		if(isPossible) {
			printResultBoard(R, C);
		} else {
			printf("Impossible\n");
		}
	}

	return 0;
}

void printResultBoard(int nR, int nC) {
	for(int r=0; r < nR; r++) {
		for(int c=0; c < nC; c++)
			printf("%c", result[r][c]);
		printf("\n");
	}
}

bool isInBound(int curRow, int curCol, int nR, int nC) {
	return 0 <= curRow && curRow < nR && 0 <= curCol && curCol < nC;
}
// helper function for isThisBoardPossible
void revealAdjacentCell(int curRow, int curCol, int nR, int nC) {
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
	all other numbers
*/
bool isThisBoardPossible(int startRow, int startCol, int nR, int nC) {
	for(int r=0; r < nR; r++)
		for(int c=0; c < nC; c++)
			testBoard[r][c] = board[r][c];

	revealAdjacentCell(startRow, startCol, nR, nC);
	
	bool allRevealed = true;
	for(int r=0; allRevealed && r < nR; r++)
		for(int c=0; allRevealed && c < nC; c++)
			allRevealed &= testBoard[r][c] != '.';

	return allRevealed;
}


/*
	Brute force.
*/
bool solveUsingBruteForce(int nR, int nC, int M) {
	// initialize the board
	for(int r=0; r < nR; r++)
		for(int c=0; c < nC; c++)
			board[r][c] = '.';
	
	foundPossibleConfigGlobal = false;

	return isPossibleRecursive(0, 0, M, nR, nC, M, nR*nC);
}

bool isPossibleRecursive(int curR, int curC, int minesLeft, int nR, int nC, int M, int spaceLeft) {
	if(foundPossibleConfigGlobal) return true;

	if(minesLeft == 0) {
		// see if there is any possible configuration
		bool foundPossibleConfig = false;
		for(int r=0; !foundPossibleConfig && r < nR; r++)
			for(int c=0; !foundPossibleConfig && c < nC; c++)
				if(board[r][c] == '.') {
					board[r][c] = 'c';
					if(isThisBoardPossible(r, c, nR, nC)) {
						foundPossibleConfig = true;
						foundPossibleConfigGlobal = true;

						// save the result
						for(int i=0; i < nR; i++)
							for(int j=0; j < nC; j++)
								result[i][j] = board[i][j];
					} else {
						board[r][c] = '.';
					}
				}
		return foundPossibleConfig;
	}

	// determine whether to put a mine at the current location or not
	int nextR = (curC == (nC-1)) ? (curR + 1) : curR;
	int nextC = (curC + 1) % nC;
	bool isPossible = false;

	// We have an option to not place a mine if we have enough space to place all mines left.
	if(spaceLeft > minesLeft) {
		isPossible |= isPossibleRecursive(nextR, nextC, minesLeft, nR, nC, M, spaceLeft - 1);
	}
	if(!isPossible && minesLeft > 0) {
		board[curR][curC] = '*';
		isPossible |= isPossibleRecursive(nextR, nextC, minesLeft - 1, nR, nC, M, spaceLeft - 1);
		if(!isPossible) board[curR][curC] = '.';
	}

	return isPossible;
}
