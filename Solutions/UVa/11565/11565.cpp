#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define pb(x) push_back(x)

int main() {
	int N, A, B, C, x, y, z;
	vector<int> res(3);
	vector<int> cur(3);
	bool found;

	scanf("%d", &N);

	while(N--) {
		scanf("%d %d %d", &A, &B, &C);
		found = false;
		res[0] = res[1] = res[2] = 10010;

		for(x = 1; x*x<=B; x++)
			for(y=x+1; (x+y) < A && (x*x + y*y) < C && x*y <= B; y++) {
				z = A - x - y;
				if(x == z || y== z) continue;
				if((x+y+z) == A && (x*y*z) == B && (x*x + y*y + z*z) == C) {
					found = true;
					cur[0] = x, cur[1] = y, cur[2] = z;
					sort(cur.begin(), cur.end());
					if(cur < res) {
						res = cur;
					}
				}
			}

		for(x = -1; x*x<=B; x--)
			for(y=x+1; (x+y) < A && (x*x + y*y) < C && x*y <= B; y++) {
				z = A - x - y;
				if(x == z || y== z) continue;
				if((x+y+z) == A && (x*y*z) == B && (x*x + y*y + z*z) == C) {
					found = true;
					cur[0] = x, cur[1] = y, cur[2] = z;
					sort(cur.begin(), cur.end());
					if(cur < res) {
						res = cur;
					}
				}
			}

		if(found) printf("%d %d %d\n", res[0], res[1], res[2]);
		else printf("No solution.\n");

	}
	return 0;
}