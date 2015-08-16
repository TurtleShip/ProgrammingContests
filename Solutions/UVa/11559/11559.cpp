#include <cstdio>
using namespace std;

int main() {
	int N, B, H, W, minCost, p, a, curCost;
	int maxCost = 500010;
	
	while(scanf("%d %d %d %d\n", &N, &B, &H, &W) != EOF) {
		minCost = maxCost;
		for(int i=0; i < H; i++) {
			scanf("%d\n", &p);
			for(int j=0; j < W; j++) {
				scanf("%d\n", &a);
				if(a < N) continue;
				curCost = N * p;
				if(curCost < minCost && curCost <= B)
					minCost = curCost;
			}
		}

		if(minCost == maxCost) printf("stay home\n");
		else printf("%d\n", minCost);
	}

	return 0;
}