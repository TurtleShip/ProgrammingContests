#include <cstdio>
using namespace std;

int main() {
	int T, N, cur, res, cid = 1;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		res = 0;
		while(N--) {
			scanf("%d", &cur);
			if(cur >= res) res = cur;
		}
		printf("Case %d: %d\n", cid++, res);
	}
	return 0;
}