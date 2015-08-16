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
bool marked[5][5];

/*
	pre-req : bool marked[5][5] is properly populated.
	You get Bingo when 5 marks in a row, column, or diagonal.
	Returns true if you have bingo.
	Related problem:
		UVa
			(10813 , Traditional BINGO )
*/
bool isBingo() {
	bool allMarked ;
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
	int T, cur, n;
	scanf("%d", &T);
	while(T--) {
		// initialize coords
		for(int i=1; i <= 75; i++)
			loc[i] = coord();

		for(int r=0; r < 5; r++)
			for(int c=0; c < 5; c++)
				marked[r][c] = false;
		marked[2][2] = true;

		for(int r=0; r < 5; r++)
			for(int c=0; c < 5; c++) {
				if(r == 2 && c == 2) continue;
				scanf("%d", &board[r][c]);
				loc[board[r][c]] = coord(r,c);
			}

		n = 0;
		while(!isBingo()) {
			scanf("%d", &cur);
			if(loc[cur].row != -1)
				marked[loc[cur].row][loc[cur].col] = true;
			n++;


		}
		printf("BINGO after %d numbers announced\n", n);

		while(n++ < 75)
			scanf("%*d");
	}

	return 0;
}
