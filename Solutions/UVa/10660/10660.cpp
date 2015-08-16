#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define mp(x,y) make_pair(x,y)

const int INF = 0x3F3F3F3F;

int area[10][10];
int res[5];

int getDist(const int& a, const int& b) {
	return (abs(a/5 - b/5) + abs(a%5 - b%5)) * area[b/5][b%5];
}

int main() {
	int T, N, r, c, pop, sum, best, dist;

	scanf("%d", &T);

	while(T--) {
		for(int i=0; i < 5; i++)
			for(int j=0; j < 5; j++)
				area[i][j] = 0;
		scanf(" %d", &N);
		for(int i=0; i < N; i++) {
			scanf(" %d %d %d", &r, &c, &pop);
			area[r][c] = pop;
		}

		best = INF;
		for(int a=0; a < 25; a++)
			for(int b=a+1; b < 25; b++)
				for(int c=b+1; c < 25; c++)
					for(int d=c+1; d < 25; d++)
						for(int e=d+1; e < 25; e++) {
							sum = 0;
							for(int i=0; i < 25; i++) {
								if(area[i/5][i%5] == 0) continue;
								dist = min(getDist(a,i), getDist(b,i));
								dist = min(dist, min(getDist(c,i), getDist(d,i)));
								dist = min(dist, getDist(e,i));
								sum += dist;
							}
							if(sum < best) {
								res[0] = a, res[1] = b, res[2] = c, res[3] = d, res[4] = e;
								best = sum;
							}
						}
		for(int i=0; i < 4; i++)
			printf("%d ", res[i]);
		printf("%d\n", res[4]);
	}
	return 0;
}