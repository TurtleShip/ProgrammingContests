#include <cstdio>
#include <bitset>
using namespace std;

int len[22];

int main() {
	int N, limit, space, bestLen, bestCombo, bestCount, curBest, curLen;

	while(scanf("%d %d", &limit, &N) != EOF) {
		for(int i=0; i < N; i++)
			scanf("%d", &len[i]);
		bestLen = 0; // no selection, so no length
		bestCombo = 0; // no selection
		bestCount = 0;
		
		for(int mask=0; mask < (1<<N); mask++) {
			bitset<20> records(mask);
			curLen = 0;
			for(int i=0; i < N; i++) {
				if(records[i]) {
					curLen += len[i];
				}
			}
			/*
				You should've specified the tie breaker condition,
				f**king author.
			*/
			if( (bestLen < curLen && curLen <= limit ) || 
				(bestLen == curLen && bestCount < records.count()) ) {
				bestLen = curLen;
				bestCombo = mask;
			}
		}

		for(int i=0; i < N; i++)
			if(bestCombo & (1<<i))
				printf("%d ", len[i]);
		printf("sum:%d\n", bestLen);
	} 
	return 0;
}
