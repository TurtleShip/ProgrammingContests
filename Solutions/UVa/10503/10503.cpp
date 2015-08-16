#include <cstdio>
#include <cstring>
using namespace std;

bool used[15];
int front[15];
int back[15];
int N, M, st, end;

bool recurse(int idx, const int& prev, const int& end) {
	if(idx == N) return prev == end;
	bool found = false;
	for(int i=0; !found && i < M; i++) {
		if(used[i]) continue;
		used[i] = true;
		if(front[i] == prev) {
			found |= recurse(idx+1, back[i], end);
		} else if(back[i] == prev) {
			found |= recurse(idx+1, front[i], end);
		}
		used[i] = false;
	}
	return found;
}

int main() {
	bool found;

	while(scanf("%d %d", &N, &M) && N != 0) {
		scanf("%*d %d", &st);
		scanf("%d %*d", &end);
		for(int i=0; i < M; i++)
			scanf("%d %d", &front[i], &back[i]);
		memset(used, false, sizeof(used));
		if(recurse(0, st, end)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}