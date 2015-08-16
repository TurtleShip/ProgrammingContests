#include <cstdio>
using namespace std;

char board[110][110];
int res[110][110];
int move[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {0,-1}, {1,-1}, {1,0}, {1,1} };

int main() {
	int R, C, cid = 1;

	while(scanf("%d %d", &R, &C) && (R + C != 0)) {
		for(int i=0; i < R; i++)
			scanf("%s", board[i]);
		for(int i=0; i < R; i++)
			for(int j=0; j < C; j++)
				res[i][j] = 0;

		for(int i=0; i < R; i++)
			for(int j=0; j < C; j++)
				if(board[i][j] == '*') {
					for(int k=0; k < 8; k++) {
						int nextR = i + move[k][0];
						int nextC = j + move[k][1];
						if(0 <= nextR && nextR < R && 0 <= nextC && nextC < C) {
							res[nextR][nextC]++;
						}
					}
				}

		if(cid != 1) printf("\n");
		printf("Field #%d:\n", cid++);

		for(int r=0; r < R; r++) {
			for(int c=0; c < C; c++) {
				if(board[r][c] == '*') printf("*");
				else printf("%d", res[r][c]);
			}
			printf("\n");
		}
	
	}

	return 0;
}