#include <cstdio>
#include <algorithm>
using namespace std;

char rook = 'r';
char knight = 'k';
char queen = 'Q';
char king = 'K';

/*
Given R x C chess board,
return the maximum number of pieces of type 'pieceType'
such that no piece will attack each other.

Related problem
Uva : ( 278 , Chess )
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
		There are T = R*C tiles in the board.å
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



int main() {
	int M, N;
	while(scanf("%d %d", &M, &N) && !(M==0 && N == 0)) {
		int res = findMaximumPiece(M,N, knight);
		printf("%d knights may be placed on a %d row %d column board.\n",
			res, M, N);
	}

}