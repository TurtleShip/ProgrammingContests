#include <vector>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;

#define pb(x) push_back(x)
#define rall(v) (v).rbegin(), (v).rend()

int num[15];

int main() {
	int T, N, sum, idx;
	bool hasDup;

	while(scanf("%d %d", &T, &N) && N != 0) {
		for(int i=0; i < N; i++)
			scanf("%d", &num[i]);

		vector< vector<int> >res;
		for(int mask = 0; mask < (1<<N); mask++) {
			bitset<12> combi(mask);
			sum = 0;
			for(int i=0; i < N; i++)
				if(combi[i])
					sum += num[i];

			if(sum == T) {
				vector<int> cur(combi.count());
				idx = 0;
				hasDup = false;
				for(int i=0; i < N; i++)
					if(combi[i])
						cur[idx++] = num[i];
				sort(rall(cur));

				// check for duplicates
				for(int i=0; !hasDup && i < res.size(); i++) {
					if(res[i].size() != cur.size()) continue;
					bool isSame = true;
					for(int j=0; isSame && j < cur.size(); j++)
						isSame &= res[i][j] == cur[j];
					hasDup |= isSame;
				}
				if(!hasDup) res.pb(cur);
			}
		}

		printf("Sums of %d:\n", T);
		if(res.size() == 0) {
			printf("NONE\n");
		} else {
			sort(rall(res));
			for(auto V : res) {
				printf("%d", V[0]);
				for(int i=1; i < V.size(); i++)
					printf("+%d", V[i]);
				printf("\n");
			}
		}
	}
	return 0;
}