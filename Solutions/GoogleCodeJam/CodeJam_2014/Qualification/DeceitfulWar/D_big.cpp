#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int playOptimal(vector<double>, vector<double>);

int main() {
	int T, N, kenOptimal, naomiOptimal;
	vector<double> naomi;
	vector<double> ken;

	scanf("%d", &T);
	for(int cid=1; cid <= T; cid++) {
		scanf("%d", &N);

		naomi.resize(N);
		ken.resize(N);

		for(int i=0; i < N; i++)
			scanf("%lf", &naomi[i]);
		
		for(int i=0; i < N; i++)
			scanf("%lf", &ken[i]);

		kenOptimal = playOptimal(ken, naomi);
		naomiOptimal = playOptimal(naomi, ken);

		printf("Case #%d: %d %d\n", cid, naomiOptimal, N - kenOptimal);
	}

	return 0;
}

int playOptimal(vector<double> me, vector<double> opponent) {
	sort(me.begin(), me.end());
	sort(opponent.begin(), opponent.end());

	int myIdx = 0, oppIdx = 0, win = 0, N = me.size();
 	while(myIdx < N) {
		if(me[myIdx] > opponent[oppIdx]) {
			myIdx++;
			oppIdx++;
			win++;
		} else {
			myIdx++;
		}
	}

	return win;
}
