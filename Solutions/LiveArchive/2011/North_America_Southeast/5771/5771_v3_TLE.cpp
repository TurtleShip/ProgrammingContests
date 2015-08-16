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
		sum = hexa[cur[0]] + hexa[cur[1]] + hexa[cur[2]] + hexa[cur[3]];
		if(fixedSum != -1 && fixedSum != sum) return 0;
		if(sum <= minSum) return 0;
		break;

		case 6:
		if(sum != (hexa[cur[4]] + hexa[cur[1]] + hexa[cur[5]] + hexa[cur[6]])) return 0;
		break;

		case 8:
		if(sum != (hexa[cur[4]] + hexa[cur[2]] + hexa[cur[7]] + hexa[cur[8]]) ) return 0;
		break;

		case 10:
		if(sum != (hexa[cur[6]] + hexa[cur[9]] + hexa[cur[10]] + hexa[cur[8]]) ) return 0;
		break;

		case 11:
		if(sum != (hexa[cur[0]] + hexa[cur[5]] + hexa[cur[9]] + hexa[cur[11]]) ) return 0;
		if(sum != (hexa[cur[3]] + hexa[cur[7]] + hexa[cur[10]] + hexa[cur[11]]) ) return 0;
		fixedSum = sum;
		return 1;
	}

	int res = 0;
	for(int i=0; i < 12; i++) {
		if(used[i]) continue;
		used[i] = true;
		cur[idx] = i;
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