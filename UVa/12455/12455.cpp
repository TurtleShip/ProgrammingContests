#include <bitset>
#include <cstdio>
using namespace std;

int len[20];

int main() {
	int T, N, P, curLen;
	bool found;
	

	scanf("%d", &T);

	while(T--) {
		scanf("%d %d", &N, &P);
		for(int i=0; i < P; i++)
			scanf("%d", &len[i]);
		found = false;
		for(int mask=0; !found && mask < (1<<P); mask++) {
			bitset<20> bars(mask);
			curLen = 0;
			for(int i=0; i < P; i++)
				if(bars[i])
					curLen += len[i];
				found = curLen == N;
		}
		if(found) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}	