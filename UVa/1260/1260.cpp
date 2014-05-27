#include <cstdio>
using namespace std;

int arr[1010];

int main() {
	int T, N, sum;

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0; i < N; i++)
			scanf("%d", &arr[i]);
		
		sum = 0;
		for(int i=1; i < N; i++)
			for(int j=0; j < i; j++)
				if(arr[j] <= arr[i])
					sum++;

		printf("%d\n", sum);
		
	}
	return 0;
}