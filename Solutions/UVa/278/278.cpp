#include <cstdio>
#include <algorithm>
using namespace std;

char piece;
char rook = 'r';
char knight = 'k';
char queen = 'Q';
char king = 'K';

int main() {
	int T, R, C;

	scanf("%d", &T);

	while(T--) {
		scanf(" %c %d %d", &piece, &R, &C);
		int res = -1;
		if(piece == rook) {
			res =  min(R,C);
		} else if(piece == king) {
			res = ((R+1)/2) * ((C+1)/2);
		} else if(piece == knight) {
			/*
			There are T = R*C tiles in the board.
			Half of them are white, and the other half is black.
			Since knight can only attack pieces that are on
			the opposite color tile, placing knights on the same
			colored tiles will be the best answer.
			Note that when T is odd, we will choose the color
			that has 1 more tile.
			*/
			res = (R*C + 1) / 2;
		} else if(piece == queen) {
			res = min(R,C);
		}
		
		printf("%d\n", res);
		
	}
	
	return 0;
}