#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

char input[10010];
char filter[10010];
char board[100][100];
char no[20] = "No magic :(";
char word[110];

int main() {
	int T, N, K;
	scanf("%d\n", &T);
	for(int cid=1; cid <= T; cid++) {
		scanf("%[^\n]\n", input);
		N = 0;
		for(int i=0; i < strlen(input); i++)
			if('a' <= input[i] && input[i] <= 'z')
				filter[N++] = input[i];

		printf("Case #%d:\n", cid);

		K = sqrt(N);
		if(K*K != N) {
			printf("%s\n", no);
			continue;
		}
		for(int r=0; r < K; r++)
			for(int c=0; c < K; c++)
				board[r][c] = filter[r*K+c];
		for(int i=0; i < K; i++)
			word[i] = filter[i];
		word[K] = '\0';
		
		bool isGood = true;

		// check (0,0) moving down
		for(int i=0; isGood && i < K; i++)
			isGood &= word[i] == board[i][0];

		// check (K-1, K-1) moving left
		for(int i=0; isGood && i < K; i++)
			isGood &= word[i] == board[K-1][K-1-i];

		// check (K-1, K-1) moving up
		for(int i=0; isGood && i < K; i++)
			isGood &= word[i] == board[K-1-i][K-1];

		if(isGood) printf("%d\n", K);
		else printf("%s\n", no);
	}

	return 0;
}