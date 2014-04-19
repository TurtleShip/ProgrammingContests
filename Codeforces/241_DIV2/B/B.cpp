#include <cstdio>
#include <algorithm>
using namespace std;

/*
startTime[i][j]
= The time that takes for (j)th painter to paint (i)th paint.
*/
int timeTook[50010][10];
int timeSpent[50010];

int main() {
	int numOfPictures, numOfPainters;

	scanf("%d %d", &numOfPictures, &numOfPainters);

	for(int i=0; i < numOfPictures; i++) {
		for(int j=0; j < numOfPainters; j++) {
			scanf("%d", &timeTook[i][j]);
		}
	}

	for(int i=0; i < numOfPictures; i++)
		timeSpent[i] = 0;

	for(int painter = 0; painter < numOfPainters - 1; painter++) {
		int curTime = 0;
		for(int i=0; i < numOfPictures; i++) {
			if(curTime >= timeSpent[i]) {
				timeSpent[i] += (curTime - timeSpent[i]) + timeTook[i][painter];
				curTime += timeTook[i][painter];
			} else { // curTime < timeSpent[i]
				int waitTime = timeSpent[i] - curTime;
				timeSpent[i] += timeTook[i][painter];
				curTime += waitTime + timeTook[i][painter];
			}
		}
	}

	int curTime = 0;
	for(int i=0; i < numOfPictures; i++) {
		if(curTime >= timeSpent[i]) {
			curTime += timeTook[i][numOfPainters - 1];
		} else { // curTime < timeSpent[i]
			int waitTime = timeSpent[i] - curTime;
			curTime += waitTime + timeTook[i][numOfPainters-1];
		}
		printf("%d ", curTime);
	}
	printf("\n");

	return 0;
}