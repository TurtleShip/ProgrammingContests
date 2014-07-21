#include <cstdio>
#include <cstring>
using namespace std;

bool played[1010][1010];
int main() {
	int N, M, K; // variables described in the problem.
	int maxGames; // The maximum number of games can be played
	int requiredGames; // the number of games required to have possible outcome

	scanf("%d %d", &N, &K);

	maxGames = (N * (N-1)) / 2;
	requiredGames = N * K;
	memset(played, false, sizeof(played));

	if(requiredGames > maxGames) {
		printf("-1\n");
	} else {
		printf("%d\n", requiredGames); // forgot to print this in the first submission
		for(int a=1; a <= N; a++) {
			int win = 0;
			for(int b=1; win < K && b<= N; b++) {
				if(a == b || played[a][b]) continue;
				win++;
				played[a][b] = played[b][a] = true;
				printf("%d %d\n", a, b);
			}
		}
	}

	return 0;
}