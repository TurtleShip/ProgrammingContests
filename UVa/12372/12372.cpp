#include <cstdio>
using namespace std;

int main() {
	int T, L, W, H;
	scanf("%d", &T);
	for(int cid=1; cid <= T; cid++) {
		scanf("%d %d %d", &L, &W, &H);
		if(L > 20 || W > 20 || H > 20) printf("Case %d: bad\n", cid);
		else printf("Case %d: good\n", cid);
	}
}
