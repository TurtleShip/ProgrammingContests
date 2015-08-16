#include <iostream>
#include <stack>
using namespace std;

#define MAXV 100
int R, C;
int id[MAXV][MAXV][2];
string maze[MAXV];
int num_cycle;
int max_len;
int move[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

/* This problem becomes quite easy once we make a key observation.
Think of a maze line as a bisecting line of a square. 
So think of '/' like the below
-----
|  /|   
| / |
|/  |
----
And '\' like the below
-----
|\  |
| \ |
|  \|
-----

Notice that the area of each triangle formed from the original square 
is exactly the size of the area of a small square described in the problem.

For '/' in maze[r][c], let id[r][c][0] denote the id of the left triangle
and id[r][c][1] denote the id of the right trangle.

The same goes for '\'

Then we do the below
1) Go though each triangle. 
2) If the current traingle is univisted, have its id as 1 and run dfs.
   Look at the code for more details on dfs
*/

void dfs(int r, int c, int side, int depth) {
	id[r][c][side] = depth;
	int nextDepth = depth + 1;

	for(int i=0; i < 4; i++) {
		int nextR = r + move[i][0];
		int nextC = c + move[i][1];
		int nextSide = -1;

		if( !(0 <= nextR && nextR < R && 0 <= nextC && nextC < C) )
			continue;

		switch(i) {
			case 0: // up
			if( (maze[r][c]=='/' && side == 0) || (maze[r][c] == '\\' && side == 1) ) {
				if(maze[nextR][nextC] == '/') nextSide = 1;
				else nextSide = 0;
			}
			break;

			case 1: // down
			if( (maze[r][c] == '/' && side == 1) || (maze[r][c] == '\\' && side == 0) ) {
				if(maze[nextR][nextC] == '/') nextSide = 0;
				else nextSide = 1;
			}
			break;

			case 2: // left
			if(side == 0) nextSide = 1;
			break;

			case 3: // right
			if(side == 1) nextSide = 0;
			break;
		}
		if(nextSide != -1) {
			if(id[nextR][nextC][nextSide] != -1) {
				if(id[nextR][nextC][nextSide] < (depth-1) ) {
					num_cycle++;
					max_len = max(max_len, depth);
				}
			} else {
				dfs(nextR, nextC, nextSide, nextDepth);
			}
		}
	}
}


int main() {

	string tmp;
	int idx = 1;

	while(cin>>C>>R) {
		if(C==0 && R ==0) break;

		for(int i=0; i < R; i++)
			cin>>maze[i];

		// initialize
		for(int i=0; i < R; i++)
			for(int j=0; j < C; j++)
				for(int k=0; k < 2; k++)
					id[i][j][k] = -1;

		num_cycle = 0;
		max_len = 0;

		for(int i=0; i < R; i++)
			for(int j=0; j < C; j++)
				for(int k=0; k < 2; k++)
					if(id[i][j][k] == -1)
						dfs(i,j,k,1);

		cout<<"Maze #"<<idx++<<":"<<endl;
		if(num_cycle == 0) cout<<"There are no cycles."<<endl;
		else cout<<num_cycle<<" Cycles; the longest has length "<<max_len<<"."<<endl;
		cout<<endl;

	}
	return 0;
}
