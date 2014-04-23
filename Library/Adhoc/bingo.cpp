#include <cstdio>
using namespace std;

typedef struct coord {
	int row, col;
	coord() {
		row = col = -1;
	}
	coord(int r, int c) {
		row = r;
		col = c;
	}
} coord;

int board[5][5]; // bingo board
coord loc[80]; // location of bingo numbers on your board
bool marked[5][5]; // marked[r][c] = true if marked tile (r,c) off

/*
	pre-req : bool marked[5][5] is properly populated.
	You get Bingo when 5 marks in a row, column, or diagonal.
	Returns true if you have bingo.
*/
bool isBingo() {
	bool allMarked;

	// check horizontal
	for(int c=0; c < 5; c++) {
		allMarked = true;
		for(int r=0; allMarked && r < 5; r++)
			allMarked &= marked[r][c];
		if(allMarked) return true;
	}

	// check vertical
	for(int r=0; r < 5; r++) {
		allMarked = true;
		for(int c=0; allMarked && c < 5; c++)
			allMarked &= marked[r][c];
		if(allMarked) return true;
	}

	// check diagonal
	allMarked = true;
	for(int i=0; i < 5; i++)
		allMarked &= marked[i][i];
	if(allMarked) return true;

	allMarked = true;
	for(int i=0; i < 5; i++)
		allMarked &= marked[4-i][i];

	return allMarked;
}

int main() {
	return 0;
}
