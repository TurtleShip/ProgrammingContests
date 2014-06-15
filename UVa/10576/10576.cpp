#include <cstdio>
#include <bitset>
#include <cstdlib>
using namespace std;


int main() {
	int d, s, res, sum;
	
	while(scanf("%d %d", &s, &d) != EOF) {
		res = -1;
		d = -d;
		
		for(int mask = 0; mask < (1<<12); mask++) {
			bitset<12> isLoss(mask);

			sum = 0;
			for(int i=0; i <= 4; i++)
				sum += isLoss[i] ? d : s;

			for(int i=5; sum < 0 && i < 12; i++) {
				sum -= isLoss[i-5] ? d : s;
				sum += isLoss[i] ? d : s;
			}


			if(sum < 0) {
				sum = 0;
				for(int i=0; i < 12; i++)
					sum += isLoss[i] ? d : s;
				res = max(res, sum);
			}
		}
		if(res < 0) printf("Deficit\n");
		else printf("%d\n", res);
	}
	return 0;
}