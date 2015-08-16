#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool decreasingSort(double a, double b) {
	return a > b;
}

int main() {
	int T, N;
	int deceitWin;
	int normalWin;
	vector<double> naomi;
	vector<double> ken;
	scanf("%d", &T);

	for(int cid=1; cid <= T; cid++) {
		scanf("%d", &N);

		deceitWin = 0;
		normalWin = N;
		naomi.resize(N);
		ken.resize(N);

		for(int i=0; i < N; i++)
			scanf("%lf", &naomi[i]);
		for(int i=0; i < N; i++)
			scanf("%lf", &ken[i]);

		
		sort(naomi.begin(), naomi.end());
		
		do {
			int curWin = 0;
			for(int i=0; i < N; i++)
			if(naomi[i] > ken[i])
				curWin++;
			deceitWin = max(curWin,deceitWin);
			normalWin = min(curWin, normalWin);

		} while( next_permutation(naomi.begin(), naomi.end()) );
		

		printf("Case #%d: %d %d\n", cid, deceitWin, normalWin);
	}

	return 0;
}