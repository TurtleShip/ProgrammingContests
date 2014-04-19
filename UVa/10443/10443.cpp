#include <cstdio>
#include <cstring>
using namespace std;

char rock = 'R';
char scissor = 'S';
char paper = 'P';

char before[110][110];
char after[110][110];
int move[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

/*
	Returns true if 'me' wins 'you'
	Related problem
	UVa
		(10443 , Rock)
*/
bool isWin(char me, char you) {
	if(me == rock) return you == scissor;
	else if(me == scissor) return you == paper;
	else return you == rock;
}

int main() {
	int T, N, nR, nC, nextR, nextC;
	bool isFirst = true;
	scanf("%d", &T);
	while(T--) {

		scanf("%d %d %d", &nR, &nC, &N);
		for(int i=0; i < nR; i++)
			scanf("%s", before[i]);

		// Simulate it.
		// Runtime : 100 x 100 x 100 x 8 = 8,000,000. Good enough.

		// Copy before to after
		for(int r=0; r < nR; r++)
			strcpy(after[r], before[r]);

		for(int n = 0; n < N; n++) {
			for(int r = 0; r < nR; r++) {
				for(int c =0; c < nC; c++) {
					for(int i=0; i < 4; i++) {
						nextR = r + move[i][0];
						nextC = c + move[i][1];
						if(0 <= nextR && nextR < nR && 0 <= nextC && nextC < nC) {
							if(isWin(before[r][c], before[nextR][nextC]))
								after[nextR][nextC] = before[r][c];
						}
					}
				}
			}
			
			for(int r = 0; r < nR; r++)
				strcpy(before[r], after[r]);
		}

		if(isFirst) isFirst = false;
		else printf("\n");

		for(int r=0; r < nR; r++) {
			printf("%s\n", after[r]);
		}
	}


	return 0;
}