#include <cstdio>
#include <cstdlib>
using namespace std;

int arr[1010];

int main() {
	int N, M, query, cid=1;

	while(scanf("%d", &N) && N != 0) {
		for(int i=0; i < N; i++)
			scanf("%d", &arr[i]);

		printf("Case %d:\n", cid++);
		scanf("%d", &M);
		for(int i=0; i < M; i++) {
			scanf("%d", &query);
			int res = arr[0] + arr[1];
			int minDiff = abs(res - query);
			
			for(int j=0; j < N; j++) {
				for(int k=j+1; k < N; k++) {
					int curSum = arr[j] + arr[k];
					int curDiff = abs(curSum - query);
			
					if(curDiff < minDiff) {
						res = curSum;
						minDiff = curDiff;
					}
				}
			}

			printf("Closest sum to %d is %d.\n", query, res);
		}
	}

	return 0;
}