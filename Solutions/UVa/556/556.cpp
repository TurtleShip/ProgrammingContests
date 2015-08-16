#include <iostream>
#include <string>
using namespace std;

/*
	Contains helpful functions to simulate 2 dimensional board.
	Related problems
	UVa
		( 556, Amazing )
*/
typedef struct Dir {
	int dr, dc;
	Dir() {};
	Dir(int _dr, int _dc) {
		dr = _dr;
		dc = _dc;
	}

	bool operator==(Dir other) {
		return dr == other.dr && dc == other.dc;
	}
} Dir;

Dir north = Dir(-1, 0);
Dir south = Dir( 1, 0);
Dir west  = Dir( 0,-1);
Dir east  = Dir( 0, 1);

// returns a direction when turned left from cur direction
Dir turnLeft(Dir cur) {
	if(cur == north) return west;
	if(cur == west) return south;
	if(cur == south) return east;
	return north; // cur == east
}

// return a direction when turned right from cur direction
Dir turnRight(Dir cur) {
	if(cur == north) return east;
	if(cur == east) return south;
	if(cur == south) return west;
	return north; // cur == west
}



int main() {
	int nR, nC;
	int count[5];
	string str;
	
	while(cin>>nR>>nC && !(nR == 0 && nC == 0)) {
		bool isWall[nR+2][nC+2];
		// fill the boundaries
		for(int r=0; r < (nR + 2); r++)
			isWall[r][0] = isWall[r][nC+1] = true;

		for(int c=0; c < (nC + 2); c++)
			isWall[0][c] = isWall[nR+1][c] = true;

		for(int r=1; r <= nR; r++) {
			cin>>str;
			for(int c=1; c <= nC; c++) {
				isWall[r][c] = str[c-1] == '1';
			}
		}

		for(int i=0; i <= 4; i++)
			count[i] = 0;

		int board_record[nR+2][nC+2];
		for(int r=1; r <= nR; r++)
			for(int c=1; c <= nC; c++)
				board_record[r][c] = 0;

		int cur_row = nR;
		int cur_col = 1;
		board_record[cur_row][cur_col] = 0;
		Dir cur_dir = east;

		// keep the simulation going until we come back 
		// to the starting point
		while(board_record[nR][1] != 1) {

			// check if we can go
			int next_row = cur_row + cur_dir.dr;
			int next_col = cur_col + cur_dir.dc;

			if(isWall[next_row][next_col]) {
				// we are blocked. turn left
				cur_dir = turnLeft(cur_dir);
			} else {

				// Next block is open. Check if there is a wall right to us
				Dir next_right_dir = turnRight(cur_dir);
				int next_right_row = next_row + next_right_dir.dr;
				int next_right_col = next_col + next_right_dir.dc;

				board_record[next_row][next_col]++;
				cur_row = next_row;
				cur_col = next_col;

				if(!isWall[next_right_row][next_right_col]) {
					// We can go, but make a right turn.
					cur_dir = next_right_dir;
				}
			}
		}

		for(int r=1; r <= nR; r++)
			for(int c=1; c<= nC; c++)
				if(!isWall[r][c] && board_record[r][c] <= 4)
					count[board_record[r][c]]++;


		for(int i=0; i <= 4; i++) {
			cout.width(3);
			cout<<right<<count[i];
		}
		cout<<endl;

	}



	return 0;
}