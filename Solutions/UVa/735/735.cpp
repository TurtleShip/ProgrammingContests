#include <cstdio>
using namespace std;

bool isValid[100];

int main() {
	int score, combi, permu;
	for(int i=0; i <= 60; i++)
		isValid[i] = (i <= 20 
			|| (i % 2 == 0 && i/2 <= 20) 
			|| (i % 3 == 0 && i/3 <= 20)
			|| i == 50);

	while(scanf("%d", &score) && score > 0) {
		// init
		combi = permu = 0;
		if(score <= 180) {
			for(int i=0; i <= 60; i++) if(isValid[i])
				for(int j=i; j <= 60; j++) if(isValid[j])
					for(int k=j; k <= 60; k++) if(isValid[k])
						if(i + j + k == score) {
							combi++;
							if(i == j && j == k) permu++;
							else if(i != j && j != k) permu += 6;
							else permu += 3;
						}
			
		}


		if(combi == 0) {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
		} else {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, combi);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, permu);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	
	return 0;
}