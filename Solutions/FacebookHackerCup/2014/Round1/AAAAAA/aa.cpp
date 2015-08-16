#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int DOWN = 0, RIGHT = 1, UP = 2, LEFT = 3;

bool is_free[510][510];
int best_move_with_turn[510][510][4];
int best_move_only_normal[510][510][4];

int normal[2][2] = {{0,1},{1,0}}; // right and down are "normal" moves
int R,C;

bool isValid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

bool shouldGo(int nr, int nc, int cur_move, int dir, bool can_turn) {
	if(!isValid(nr,nc) || !is_free[nr][nc]) return false;
	if( (cur_move + 1) <= best_move_only_normal[nr][nc][dir] ) return false;
	if( !can_turn && (cur_move+1) <= best_move_with_turn[nr][nc][dir] ) return false;
	return true;
}

/*
cr = current row
cc = current column
prev_move_ct = number of moves it took to get to the current position
can_turn = true if I can make "turn", which is either left or up
going_left = true if I am going left
going_up = true if I am going up
*/
int pathFinder(int cr, int cc, int prev_move_ct, int prev_dir, bool can_turn, bool going_left, bool going_up) {
	is_free[cr][cc] = false;
	
	if(can_turn) best_move_only_normal[cr][cc][prev_dir] = prev_move_ct + 1;
	else best_move_with_turn[cr][cc][prev_dir] = prev_move_ct + 1;

	int best_move = 0;

	// try down
	int nr = cr + 1;
	int nc = cc;
	if(shouldGo(nr,nc,prev_move_ct+1, DOWN, can_turn))
		best_move = max(best_move, pathFinder(nr,nc, prev_move_ct+1, DOWN, can_turn, false, false) );

	// try right
	nr = cr;
	nc = cc + 1;
	if(shouldGo(nr,nc,prev_move_ct+1, RIGHT, can_turn))
		best_move = max(best_move, pathFinder(nr,nc, prev_move_ct+1, RIGHT, can_turn, false, false) );	

	// try going up
	if(can_turn || going_up) {
		nr = cr - 1;
		nc = cc;
		if(shouldGo(nr,nc,prev_move_ct+1, UP, false))
			best_move = max(best_move, pathFinder(nr, nc, prev_move_ct+1, UP, false, false, true));
	}

	// try going left
	if(can_turn || going_left) {
		nr = cr;
		nc = cc - 1;
		if(shouldGo(nr,nc,prev_move_ct+1, LEFT, false))
			best_move = max(best_move, pathFinder(nr, nc, prev_move_ct+1, LEFT, false, true, false));
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
				for(int i=0; i < 4; i++) {
					best_move_with_turn[r][c][i] = 0;
					best_move_only_normal[r][c][i] = 0;
				}
			}
		}

		/*
		I think I can solve this problem using backtrack. Let's try.
		prev_dir for the initial position doesn't matter.
		*/
		int res = pathFinder(0, 0, 0, DOWN, true, false, false);

		cout<<"Case #"<<cid<<": "<<res<<endl;

	}
}