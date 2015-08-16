#include <cstdio>
#include <bitset>
using namespace std;

const int maxTower = 20;
typedef struct info {
	int towers;
	int numCustomers;
} info;
int customers[maxTower + 10];
info common[maxTower + 10];


int main() {
	int N, target, M, tmp, t, cid = 1;

	while(scanf("%d %d", &N, &target) && N != 0 && target != 0) {
		for(int i=0; i < N; i++) {
			scanf("%d", &customers[i]);
		}
		scanf("%d", &M);

		for(int i=0; i < M; i++) {
			scanf("%d", &t);
			common[i].towers = 0;
			for(int j=0; j < t; j++) {
				scanf("%d", &tmp);
				tmp--;
				common[i].towers |= 1 << tmp;
			}
			scanf("%d", &common[i].numCustomers);
		}

		/*
			There are at most 20 towers.
			2^20 = (2^10)^2 ~ (10^3)^2 = 1,000,000
			Small enough to simulate.
		*/
		int maxCustomer = 0;
		int bestCombo;

		for(int mask = 0; mask < (1<<N); mask++) {
			bitset<maxTower> towers(mask);
			if(towers.count() == target) {
				int cur = 0;
				for(int i=0; i < N; i++)
					if(towers[i]) {
						cur += customers[i];
					}

				for(int i=0; i < M; i++) {
					bitset<maxTower> shared(mask & common[i].towers);
					if(shared.count() >= 2) {
						cur -= common[i].numCustomers * (shared.count() - 1);
					}
				}
			
				if(maxCustomer < cur) {
					maxCustomer = cur;
					bestCombo = mask;
				}
			}
		}

		printf("Case Number  %d\n", cid++);
		printf("Number of Customers: %d\n", maxCustomer);
		printf("Locations recommended: ");
		bool isFirst = true;
		for(int i=0; i < N; i++) {
			if(bestCombo & (1<<i)) {
				if(isFirst) isFirst = false;
				else printf(" ");
				printf("%d", (i+1));
			}
		}
		printf("\n");
		printf("\n"); // extra line after each case
	}
	return 0;
}