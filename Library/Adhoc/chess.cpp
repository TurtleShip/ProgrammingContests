#include <cstdio>
#include <algorithm>
using namespace std;

bool isAttacked[8][8];
char board[8][8];

char rook = 'r';
char knight = 'n';
char bishop = 'b';
char queen = 'q';
char king = 'k';
char upPawn = 'p';
char downPawn = 'P';
char empty = 'e';


int knightMove[8][2] = { {-2,-1}, {-2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}, {2,-1}, {2,1} };
int kingMove[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
int upPawnMove[2][2] = { {1,-1}, {1,1} }; // black pawn
int downPawnMove[2][2] = { {-1,-1}, {-1,1} }; // white pawn
int diagMove[4][2] = { {-1,-1}, {-1,1}, {1,-1}, {1,1} };
int straightMove[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

bool isInBoard(int row, int col) {
	return 0 <= row && row < 8 && 0 <= col && col < 8;
}

/*
Given R x C chess board,
return the maximum number of pieces of type 'pieceType'
such that no piece will attack each other.
*/
int findMaximumPiece(int R, int C, char pieceType) {
	if(R <= 0 || C <= 0) return 0;

	int res = -1;
	if(pieceType == rook || pieceType == queen) {
		res =  min(R,C);
	} else if(pieceType == king) {
		res = ((R+1)/2) * ((C+1)/2);
	} else if(pieceType == knight) {
		/* Special cases */
		if(R == 1 || C == 1) return max(R,C);
		if(R == 2 || C == 2) {
			int big = max(R,C);
			return (big/4 * 4) + min(4,(big % 4) * 2);
		}

		/*
		There are T = R*C tiles in the board.
		Half of them are white, and the other half is black.
		Since knight can only attack pieces that are on
		the opposite color tile, placing knights on the same
		colored tiles will be the best answer.
		Note that when T is odd, we will choose the color
		that has 1 more tile.
		*/
		res = max(4, (R*C + 1) / 2);
	}
	return res;
}

/*
	Reads Forsyth-Edwards Notation.
	stores the result in board.
*/
bool readFEN() {
	char input[100];
	if(scanf("%[^\n]\n", input) == EOF) return false;
	int row = 0;
	int col = 0;
	for(int i=0; i < strlen(input); i++) {
		if(input[i] == '/') {
			col = 0;
			row++;
			continue;
		}
		if('0' <= input[i] && input[i] <= '8') {
			int emptyCt = input[i] - '0';
			for(int j=0; j < emptyCt; j++) {
				board[row][col++] = empty;
			}
		} else {
			board[row][col++] = input[i];
		}
	}
	return true;
}

/*
	pre-req : char[][] board must be populated
	Returns the number of unoccupied squares on the board
	which are not attacked by any piece.
*/
int countUnattacked() {
	// initialize
	for(int i=0; i < 8; i++)
		for(int j=0; j < 8; j++)
			isAttacked[i][j] = false;
			

	for(int r=0; r < 8; r++) {
		for(int c=0; c < 8; c++) {
			char piece = board[r][c];
			if(piece == empty) continue;
			if( tolower(piece) == rook) {
				for(int i=0;  i < 4; i++) {
					int nextR = r + straightMove[i][0];
					int nextC = c + straightMove[i][1];
					while(isInBoard(nextR, nextC) && board[nextR][nextC] == empty) {
						isAttacked[nextR][nextC] = true;
						nextR += straightMove[i][0];
						nextC += straightMove[i][1];
					}
				}
			} else if( tolower(piece) == knight )  {
				for(int i=0; i < 8; i++) {
					int nextR = r + knightMove[i][0];
					int nextC = c + knightMove[i][1];
					if(isInBoard(nextR, nextC) && board[nextR][nextC] == empty)
						isAttacked[nextR][nextC] = true;
				}				
			} else if( tolower(piece) == bishop ) {
				for(int i=0; i < 4; i++) {
					int nextR = r + diagMove[i][0];
					int nextC = c + diagMove[i][1];
					while(isInBoard(nextR, nextC) && board[nextR][nextC] == empty) {
						isAttacked[nextR][nextC] = true;
						nextR += diagMove[i][0];
						nextC += diagMove[i][1];
					}
				}
			} else if( tolower(piece) == queen ) {
				for(int i=0;  i < 4; i++) {
					int nextR = r + straightMove[i][0];
					int nextC = c + straightMove[i][1];
					while(isInBoard(nextR, nextC) && board[nextR][nextC] == empty) {
						isAttacked[nextR][nextC] = true;
						nextR += straightMove[i][0];
						nextC += straightMove[i][1];
					}
				}
				for(int i=0; i < 4; i++) {
					int nextR = r + diagMove[i][0];
					int nextC = c + diagMove[i][1];
					while(isInBoard(nextR, nextC) && board[nextR][nextC] == empty) {	
						isAttacked[nextR][nextC] = true;
						nextR += diagMove[i][0];
						nextC += diagMove[i][1];
					}
				}
			} else if( tolower(piece) == king ) {
				for(int i=0; i < 8; i++) {
					int nextR = r + kingMove[i][0];
					int nextC = c + kingMove[i][1];
					if(isInBoard(nextR, nextC) && board[nextR][nextC] == empty)
						isAttacked[nextR][nextC] = true;
				}

			} else if( piece == upPawn) {
				for(int i=0; i < 2; i++) {
					int nextR = r + upPawnMove[i][0];
					int nextC = c + upPawnMove[i][1];
					if(isInBoard(nextR, nextC) && board[nextR][nextC] == empty)
						isAttacked[nextR][nextC] = true;
				}

			} else if ( piece == downPawn ) {
				for(int i=0; i < 2; i++) {
					int nextR = r + downPawnMove[i][0];
					int nextC = c + downPawnMove[i][1];
					if(isInBoard(nextR, nextC) && board[nextR][nextC] == empty)
						isAttacked[nextR][nextC] = true;
				}
			}
		}
	}

	int res = 0;
	for(int i=0; i < 8; i++)
		for(int j=0; j < 8; j++)
			if(board[i][j] == empty && !isAttacked[i][j]) res++;

	return res;
}

int main() {

}