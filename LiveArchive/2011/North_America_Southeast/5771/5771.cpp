#include <cstdio>
#include <algorithm>
using namespace std;

int hexa[12];
bool used[12];
int cur[12];
int sum;
int fixedSum;
int minSum;

/*
I am indexing hexagram as below
      4
0   1   2   3
  5       7
6   9   10   8
     11
*/
int solve(int idx) {
	bool isGood = false;
	switch(idx-1) {
		case 3:
		sum = cur[0] + cur[1] + cur[2] + cur[3];
		if(fixedSum != -1 && fixedSum != sum) return 0;
		if(sum <= minSum) return 0;
		break;

		case 6:
		if(sum != (cur[4] + cur[1] + cur[5] + cur[6])) return 0;
		break;

		case 8:
		if(sum != (cur[4] + cur[2] + cur[7] + cur[8]) ) return 0;
		break;

		case 10:
		if(sum != (cur[6] + cur[9] + cur[10] + cur[8]) ) return 0;
		break;

		case 11:
		if(sum != (cur[0] + cur[5] + cur[9] + cur[11]) ) return 0;
		if(sum != (cur[3] + cur[7] + cur[10] + cur[11]) ) return 0;
		fixedSum = sum;
		return 1;
	}

	int res = 0;
	for(int i=0; i < 12; i++) {
		if(used[i]) continue;
		used[i] = true;
		cur[idx] = hexa[i];
		res += solve(idx+1);
		used[i] = false;
	}
	return res;
}

int main() {
	while(scanf(" %d",&hexa[0]) != EOF) {
		for(int i=1; i < 12; i++)
			scanf(" %d", &hexa[i]);
		sum = 0;
		
		for(int i=0; i < 12; i++)
			sum += hexa[i];
	
		if(sum == 0) break;
		sort(hexa, hexa+12);
		minSum = hexa[0] + hexa[1] + hexa[2] + hexa[11];

		for(int i=0; i < 12; i++)
			used[i] = false;
		fixedSum = -1;
		sum = solve(0) / 12;
		printf("%d\n", sum);
	}
	return 0;
}