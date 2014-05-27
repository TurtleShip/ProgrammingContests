#include <cstdio>
using namespace std;

int arr[15];

int main() {
	int K;
	bool isFirst = true;
	while(scanf("%d", &K) && K != 0) {
		if(isFirst) isFirst = false;
		else printf("\n");

		for(int i=0; i < K; i++)
			scanf("%d", &arr[i]);

		for(int i0=0; i0 < K-5; i0++)
			for(int i1=i0+1; i1 < K-4; i1++)
				for(int i2=i1+1; i2 < K-3; i2++)
					for(int i3=i2+1; i3 < K-2; i3++)
						for(int i4=i3+1; i4 < K-1; i4++)
							for(int i5=i4+1; i5 < K; i5++)
								printf("%d %d %d %d %d %d\n", arr[i0], arr[i1], arr[i2], arr[i3], arr[i4], arr[i5]);
	}
	return 0;
}