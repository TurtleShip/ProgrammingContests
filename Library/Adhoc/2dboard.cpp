#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
	Contains helpful functions to simulate 2 dimensional board.
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

// Given a SQUARE board ( N by N ), rotate the board 90 degrees clockwise.
template<typename T>
void rotate90(vector< vector<T> >& board) {
	int N = board.size();
	vector<T> copied(board.begin(), board.end());

	for(int r=0; r < N; r++) {
		for(int c=0; c < N; c++) {
			board[c][N-1-r] = copied[r][c];
		}
	}
}

template<typename T>
void printBoard(vector< vector<T> >& board) {
	int R = board.size();
	int C = board[0].size();
	for(int r=0; r < R; r++) {
		for(int c=0; c < C; c++) {
			cout<<board[r][c];
		}
		cout<<endl;
	}
}

int main() {

	return 0;
}