#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)

vector<int> neighbors[110];
bool isBlack[110];
int maxBlack;
int res[110];
int N, M;

/* 
	nodes < curNode have all been visited,
	and nodes > curNode have not been visited
*/
void solve(int curNode, int curBlack) {
	if(curNode == (N+1)) {
		if(maxBlack < curBlack) {
			maxBlack = curBlack;
			int idx = 0;
			for(int i=1; i <= N; i++)
				if(isBlack[i])
					res[idx++] = i;
		}
		return;
	}

	bool canBeBlack = true;
	for(int nearNode : neighbors[curNode]) {
		if(nearNode < curNode && isBlack[nearNode]) {
			canBeBlack = false;
			break;
		}
	}

	if(canBeBlack) {
		isBlack[curNode] = true;
		solve(curNode+1, curBlack+1);
		isBlack[curNode] = false;
	}
	solve(curNode+1, curBlack);
}

int main() {
	int E, n1, n2;

	scanf("%d", &M);

	while(M--) {

		scanf("%d %d", &N, &E);
		for(int i=1; i <= N; i++) {
			neighbors[i].clear();
			isBlack[i] = false;
		}

		for(int i=0; i < E; i++) {
			scanf("%d %d", &n1, &n2);
			neighbors[n1].pb(n2);
			neighbors[n2].pb(n1);
		}

		maxBlack = 0;
		solve(1, 0);

		printf("%d\n", maxBlack);
		for(int i=0; i < maxBlack; i++) {
			if(i > 0) printf(" ");
			printf("%d", res[i]);
		}

		printf("\n");
	}



		
	return 0;
}
