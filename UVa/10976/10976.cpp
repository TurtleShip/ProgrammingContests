#include <cstdio>
using namespace std;

int xRes[10010];
int yRes[10010];

int main() {
	int k, x, y, N;
	
	while(scanf("%d", &k) != EOF) {
		N = 0;
		for(y=k+1; y <=2*k; y++) {
			if( (y*k) % (y-k) == 0 ) {
				xRes[N] = (y*k) / (y-k);
				yRes[N] = y;
				N++;
			}
		}
		printf("%d\n", N);
		for(int i=0; i < N; i++)
			printf("1/%d = 1/%d + 1/%d\n", k, xRes[i], yRes[i]);
	}
	return 0;
}
