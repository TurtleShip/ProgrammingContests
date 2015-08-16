#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define MAXH 30
#define MAXW 30
#define MAXC 10
#define MAXD 5
#define MAXN 500

int deg[MAXN][MAXC];
int edgeId[MAXN][MAXC][MAXD];
int edgeSide[MAXN][MAXC][MAXD];
int W,H;
bool isVisited[MAXN][MAXC];

int getId(int r, int c) {
	return r*W + c;
}

int main() {
	int cid = 1;
	bool isFirst = true;
	string line;

	while(cin>>H>>W && !(W == 0 && H == 0)) {

		// clean out the board
		for(int i=0; i < W*H; i++)
			for(int j=0; j < 8; j++)
				deg[i][j] = 0;

		// make the default connections
		for(int r=0; r < H; r++) {
			for(int c=0; c < W; c++) {
				int id = getId(r,c);

				// check connection to top
				if(r > 0) {
					int upId = getId(r-1,c);
					edgeId[id][0][deg[id][0]] = upId;
					edgeSide[id][0][deg[id][0]] = 5;
					deg[id][0]++;

					edgeId[id][1][deg[id][1]] = upId;
					edgeSide[id][1][deg[id][1]] = 4;
					deg[id][1]++;
				}

				// check connection to bottom
				if(r < H-1) {
					int downId = getId(r+1,c);
					edgeId[id][5][deg[id][5]] = downId;
					edgeSide[id][5][deg[id][5]] = 0;
					deg[id][5]++;

					edgeId[id][4][deg[id][4]] = downId;
					edgeSide[id][4][deg[id][4]] = 1;
					deg[id][4]++; 
				}

				// check connection to left
				if(c > 0) {
					int leftId = getId(r, c-1);
					edgeId[id][7][deg[id][7]] = leftId;
					edgeSide[id][7][deg[id][7]] = 2;
					deg[id][7]++;

					edgeId[id][6][deg[id][6]] = leftId;
					edgeSide[id][6][deg[id][6]] = 3;
					deg[id][6]++;
				}

				// ceeck connection to right
				if(c < W-1) {
					int rightId = getId(r, c+1);
					edgeId[id][2][deg[id][2]] = rightId;
					edgeSide[id][2][deg[id][2]] = 7;
					deg[id][2]++;

					edgeId[id][3][deg[id][3]] = rightId;
					edgeSide[id][3][deg[id][3]] = 6;
					deg[id][3]++;
				}
			}
		}

		 int id;
		 int s,t;
		 string con;
		 getline(cin,line); // get rid of newline
		 while(getline(cin, line)) {
		 	if(line[0] == '0') break;

		 	stringstream ss;
		 	ss<<line;
		 	ss>>id;
		 	id--;
		 	
		 	while(ss>>con) {
		 		s = con[0] - 'A';
		 		t = con[1] - 'A';
		 		edgeId[id][s][deg[id][s]] = id;
		 		edgeSide[id][s][deg[id][s]] = t;
		 		deg[id][s]++;

		 		edgeId[id][t][deg[id][t]] = id;
		 		edgeSide[id][t][deg[id][t]] = s;
		 		deg[id][t]++;
		 	}
		 }


		 // now output answers
		 if(isFirst) isFirst = false;
		 else cout<<endl;
		 cout<<"Board "<<cid++<<":"<<endl;
		 getline(cin,line);
		 
		 stringstream ss;
		 ss<<line;
		 while(ss>>con) {
		 	id = 0;
		 	for(int i=0; i < con.size() - 1; i++) {
		 		id = id * 10;
		 		id += con[i] - '0';
		 	}
		 	id--;

		 	s = con[con.size()-1] - 'A';

		 	int prevId = id;
		 	int prevSide = s;
		 	int curId = id;
		 	int curSide = s;
		 	while(true) {
		 		int nextId = -1, nextSide = -1;
		 		for(int i=0; i < deg[curId][curSide]; i++) {
		 			// printf("curId = %d, curSide = %d, i = %d\n",curId, curSide, i);
		 			if(!(edgeId[curId][curSide][i] == prevId && edgeSide[curId][curSide][i] == prevSide)) {
		 				nextId = edgeId[curId][curSide][i];
		 				nextSide = edgeSide[curId][curSide][i];
		 			}
		 		}
		 		// printf("next : (%d, %d)\n", nextId,nextSide);
		 		if(nextId == -1)
		 			break;
		 		prevId = curId;
		 		prevSide = curSide;
		 		curId = nextId;
		 		curSide = nextSide;
		 	}
		 	cout<<con<<" is connected to "<<(curId + 1)<<char(curSide + 'A')<<endl;
		 }

		 
	}

	return 0;
}