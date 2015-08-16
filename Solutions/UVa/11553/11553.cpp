#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;

int grid[10][10];
int main() {
	int T, N, curSum, curCol, best, usedRow;

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int r=0; r < N; r++)
			for(int c=0; c < N; c++)
				scanf("%d", &grid[r][c]);
		vector<int> order(N);
		best = INF;
		for(int i=0; i < N; i++)
			order[i] = i;
		/*
			Note that Bob has total control over what Alice gets.
			i.e. Bob can decide which tile Alice gets to select.
		*/
		do {
			vector<bool> used(N, false);
			curSum = 0;
			for(int r=0; r < N; r++)
				curSum += grid[r][order[r]];

			best = min(best, curSum);
		} while(next_permutation(order.begin(), order.end()));

		printf("%d\n", best);
	}

	return 0;
}