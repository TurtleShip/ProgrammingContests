#include <cstdio>
#include <algorithm>
using namespace std;

int pos[1000010];
int jump[110];
int none = -1;

int main() {
	int T, numPlayer, numSL, numRolls, mouth, tail, move;

	scanf("%d", &T);

	while(T--) {
		scanf("%d %d %d", &numPlayer, &numSL, &numRolls); 
			// initialize s points
		for(int i=1; i <= 100; i++)
			jump[i] = none;
		for(int i=0; i < numSL; i++) {
			scanf("%d %d", &mouth, &tail);
			jump[mouth] = tail;
		}
		// initialize players
		for(int i=1; i <= numPlayer; i++)
			pos[i] = 1;
		int player = 1;
		int rolls = 0;
		while(rolls++ < numRolls) {
			scanf("%d", &move);
			pos[player] = min(pos[player] + move, 100);
			if(jump[pos[player]] != none)
				pos[player] = jump[pos[player]];
			if(pos[player] == 100) break;

			player++;
			if(player > numPlayer) player = 1;
		}

		while(rolls++ < numRolls) {
			scanf("%*d");
		}

		for(int i=1; i <= numPlayer; i++) {
			printf("Position of player %d is %d.\n", i, pos[i]);
		}

	}
	

	return 0;
}