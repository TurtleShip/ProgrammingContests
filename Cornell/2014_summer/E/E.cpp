#include <cstdio>
#include <cstring>
using namespace std;

int num[1010]; // num[i] = the number of neighbors of part i
int neighbor[1010][1010]; // neighbor[i][j] = the (j)th neighbor of part i
int energy[1010];
bool isRemoved[1010];

int main() {
	memset(isRemoved, false, sizeof(isRemoved));
	int N, M, a, b, res;
	
	scanf("%d %d", &N, &M);
	for(int i=1; i <= N; i++)
		scanf("%d", &energy[i]);

	for(int i=0; i < M; i++) {
		scanf("%d %d", &a, &b);
		neighbor[a][num[a]++] = b;
		neighbor[b][num[b]++] = a;
	}

	energy[0] = -10; // a value that is garauranteed to be smaller than any other energy

	res = 0;
	for(int total=0; total < N-1; total++) { // need to remove N-1

		int maxPart = 0;

		for(int part = 1; part <= N; part++) {
			if(isRemoved[part]) continue;
			if(energy[part] > energy[maxPart]) {
				maxPart = part;
			}
		}

		for(int i=0; i < num[maxPart]; i++) {
			int nextPart = neighbor[maxPart][i];
			if(isRemoved[nextPart]) continue;
			res += energy[nextPart];
		}
			
		isRemoved[maxPart] = true;
	}

	printf("%d\n", res);
	return 0;
}
