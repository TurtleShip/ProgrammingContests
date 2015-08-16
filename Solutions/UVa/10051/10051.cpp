#include <iostream>
#include <string>
using namespace std;

#define MAXN 550
#define MAXSIDE 6
/*
color[i][j] = color of (i)th Cube's (j)th 
maxDist[i][j] = Maximum number of tower of cubes that can be built
where (i)th cube's (j)th side is the top side of the very bottom cube
opSide[i] = opposite side of (i)th side

sol[i][0] = Id of (i)th cube in the solution
sol[i][1] = Side of (i)th cube in the solution
*/
int color[MAXN][MAXSIDE];
int maxDist[MAXN][MAXSIDE];
int topId[MAXN][MAXSIDE];
int topSide[MAXN][MAXSIDE];
int opSide[MAXSIDE] = {1,0,3,2,5,4};
int sol[MAXN][2];
string sideName[MAXSIDE] = {"front", "back", "left", "right", "top", "bottom"};

int main() {
	int caseId = 1;
	bool isFirst = true;
	int N;
	while(cin>>N) {
		if(N==0) break;
		if(isFirst) isFirst = false;
		else cout<<endl;

		for(int i=0; i < N; i++)
			for(int j=0; j < MAXSIDE; j++)
				cin>>color[i][j];

		int solVal = -1;
		int solBotId = -1;
		int solBotSide = -1;

		for(int curId=0; curId < N; curId++) {
			for(int curSide=0; curSide < MAXSIDE; curSide++) {
				int maxVal = 1;// we can always build a tower of one using itself
				int maxCubeId = -1;
				int maxCubeSide = -1;

				// Look through lighter cubes and update the current one
				// We are basically looking for a tower of cubes where
				// the current cube can go to the bottom
				for(int nextId=0; nextId < curId; nextId++) {
					for(int nextSide=0; nextSide < MAXSIDE; nextSide++) {

						// the opposite side of nextSide should have the same color as the curSide
						if(color[nextId][opSide[nextSide]] == color[curId][curSide]){
							if(maxVal < maxDist[nextId][nextSide] + 1) {
								maxVal = maxDist[nextId][nextSide]+1;
								maxCubeId = nextId;
								maxCubeSide = nextSide;
							}
						}
					}
				}
				maxDist[curId][curSide] = maxVal;
				topId[curId][curSide] = maxCubeId;
				topSide[curId][curSide] = maxCubeSide;

				if(solVal < maxVal) {
					// note that we want the bottom one :-) 
					// Be careful not to do solBotId = maxCubeId
					// maxCubeId is the upper cube of the current one
					solVal = maxVal;
					solBotId = curId;
					solBotSide = curSide;
				}
			}
		}

		// Build solution
		int tmpId, tmpSide;
		for(int i=0; i < solVal; i++) {
			// printf("solBotId = %d, solBotSide = %d\n",solBotId, solBotSide);
			sol[i][0] = solBotId;
			sol[i][1] = solBotSide;
			tmpId = solBotId, tmpSide = solBotSide;

			solBotId = topId[tmpId][tmpSide];
			solBotSide = topSide[tmpId][tmpSide];
		}

		cout<<"Case #"<<caseId++<<endl;
		cout<<solVal<<endl;
		for(int i=solVal-1; i >= 0; i--) {
			cout<<(sol[i][0]+1)<<" "<<sideName[sol[i][1]]<<endl;
		}


	}
	return 0;
}