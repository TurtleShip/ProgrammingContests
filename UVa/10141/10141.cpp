#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, p, bestReq, curReq, cid = 1;
	double bestPrice, curPrice;
	char curName[100];
	char bestName[100];
	
	bool isFirst = true;

	while(scanf("%d %d\n", &n, &p) && (n+p != 0)) {
		
		for(int i=0; i < n; i++)
			scanf("%*[^\n]\n");
		
		bestReq = -1;
		for(int i=0; i < p; i++) {
			scanf("%[^\n]\n", curName);
			scanf("%lf %d\n", &curPrice, &curReq);
			
			
			for(int j=0; j < curReq; j++)
				scanf("%*[^\n]\n");

			
			if(curReq > bestReq || (curReq == bestReq && curPrice < bestPrice)) {
				bestReq = curReq;
				bestPrice = curPrice;
				strcpy(bestName, curName);
			}
		}
		
		if(isFirst) isFirst = !isFirst;
		else printf("\n");
		printf("RFP #%d\n%s\n", cid++, bestName);
	}
	return 0;
}