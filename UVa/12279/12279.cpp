#include <cstdio>
using namespace std;

int main() {
	int N, cur, res, cid = 1;
	
	while(scanf("%d", &N) && N != 0) {
		res = 0;
		for(int i=0; i < N; i++) {
			scanf("%d", &cur);
			res += (cur > 0) ? 1 : -1;
		}
		printf("Case %d: %d\n", cid++, res);
	}

	return 0;
}