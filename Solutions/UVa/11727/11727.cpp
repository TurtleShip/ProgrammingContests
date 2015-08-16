#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	vector<int> V(3,0);
	scanf("%d", &T);
	for(int cid=1; cid <= T; cid++) {
		for(int i=0; i < 3; i++)
			scanf("%d", &V[i]);
		sort(V.begin(),V.end());
		printf("Case %d: %d\n", cid, V[1]);
	}
	return 0;
}