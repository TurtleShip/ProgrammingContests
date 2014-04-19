#include <cstdio>
using namespace std;

int saved[5];

int main() {
	int T, firstAns, secondAns, curNum, res, ct;
	bool isBadMagician = false;

	scanf("%d", &T);

	for(int cid=1; cid <= T; cid++) {
		ct = 0;
		scanf("%d", &firstAns);
		for(int r=1; r<= 4; r++)
			for(int c=1; c<= 4; c++)
				if(r != firstAns) scanf("%*d");
				else scanf("%d", &saved[c]);

		scanf("%d", &secondAns);
		for(int r=1; r <= 4; r++) {
			for(int c=1; c<= 4; c++) {
				if(r != secondAns) scanf("%*d");
				else {
					scanf("%d", &curNum);
					for(int i=1; i <= 4; i++)
						if(saved[i] == curNum) {
							ct++;
							res = curNum;
						}
				}
			}
		}

		printf("Case #%d: ", cid);
		if(ct == 0) printf("Volunteer cheated!\n");
		else if(ct ==1) printf("%d\n", res);
		else printf("Bad magician!\n");

	}
	return 0;
}