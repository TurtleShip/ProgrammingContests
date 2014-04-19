#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool is_free[510][510];
int normal[2][2] = {{0,1},{1,0}}; // right and down are "normal" moves
int R,C;

bool isValid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

bool shouldGo(int nr, int nc) {
	return isValid(nr,nc) && is_free[nr][nc];
}

/*
cr = current row
cc = current column
prev_move_ct = number of moves it took to get to the current position
can_turn = true if I can make "turn", which is either left or up
going_left = true if I am going left
going_up = true if I am going up
*/
int pathFinder(int cr, int cc, bool can_turn, bool going_left, bool going_up) {
	is_free[cr][cc] = false;
	
	int best_move = 0;

	//try normal move
	for(int i=0; i < 2; i++) {
		int nr = cr + normal[i][0];
		int nc = cc + normal[i][1];
		if(shouldGo(nr,nc))
			best_move = max(best_move, pathFinder(nr,nc, can_turn, false, false));
	}

	// try going left
	if(can_turn || going_left) {
		int nr = cr;
		int nc = cc - 1;
		if(shouldGo(nr,nc))
			best_move = max(best_move, pathFinder(nr, nc, false, true, false));
	}

	// try going up
	if(can_turn || going_up) {
		int nr = cr - 1;
		int nc = cc;
		if(shouldGo(nr,nc))
			best_move = max(best_move, pathFinder(nr, nc, false, false, true));
	}

	best_move += 1; // we are stepping on the current spot
	is_free[cr][cc] = true;
	return best_move;
}


int main() {
	int T;
	string str;
	cin>>T;
	for(int cid=1; cid <= T; cid++) {
		cin>>R>>C;
		for(int r=0; r < R; r++) {
			cin>>str;
			for(int c=0; c < C; c++) {
				is_free[r][c] = str[c] == '.';
			}
		}

		/*
		I think I can solve this problem using backtrack. Let's try
		*/
		int res = pathFinder(0, 0, true, false, false);

		cout<<res<<endl;

	}
}