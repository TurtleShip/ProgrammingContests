#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool is_free[510][510];
int best_move_only_normal[510][510];
int best_move_with_turn[510][510];

int normal[2][2] = {{0,1},{1,0}}; // right and down are "normal" moves
int R,C;

bool isValid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

bool shouldGo(int nr, int nc, int cur_move, bool can_turn) {
	if(!isValid(nr,nc) || !is_free[nr][nc]) return false;
	if( (cur_move + 1) < best_move_only_normal[nr][nc] ) return false;
	if( !can_turn && (cur_move+1) < best_move_with_turn[nr][nc] ) return false;
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
int pathFinder(int cr, int cc, int prev_move_ct, bool can_turn, bool going_left, bool going_up) {
	is_free[cr][cc] = false;
	// printf("(%d, %d)\n", cr, cc);
	if(can_turn) best_move_only_normal[cr][cc] = prev_move_ct + 1;
	else best_move_with_turn[cr][cc] = prev_move_ct + 1;

	int best_move = 0;

	//try normal move
	for(int i=0; i < 2; i++) {
		int nr = cr + normal[i][0];
		int nc = cc + normal[i][1];
		if(shouldGo(nr,nc,prev_move_ct+1, can_turn))
			best_move = max(best_move, pathFinder(nr,nc, prev_move_ct+1, can_turn, false, false));
	}

	// try going left
	if(can_turn || going_left) {
		int nr = cr;
		int nc = cc - 1;
		if(shouldGo(nr,nc,prev_move_ct+1, false))
			best_move = max(best_move, pathFinder(nr, nc, prev_move_ct+1, false, true, false));
	}

	// try going up
	if(can_turn || going_up) {
		int nr = cr - 1;
		int nc = cc;
		if(shouldGo(nr,nc,prev_move_ct+1, false))
			best_move = max(best_move, pathFinder(nr, nc, prev_move_ct+1, false, false, true));
	}

	// if(best_move == 0) {
	// 	cout<<"Stopping with move of "<<prev_move_ct+1<<endl;
	// 	cout<<"Best move only normal"<<endl;
	// 	for(int i=0; i<R; i++) {
	// 		for(int j=0; j < C; j++)
	// 			cout<<best_move_only_normal[i][j]<<" ";
	// 		cout<<endl;
	// 	}
	// 	cout<<"======================="<<endl;
	// 	cout<<"Best move with turn"<<endl;
	// 	for(int i=0; i < R; i++) {
	// 		for(int j=0; j < C; j++)
	// 			cout<<best_move_with_turn[i][j]<<" ";
	// 		cout<<endl;
	// 	}
	// 	cout<<endl;
	// 	cout<<"=============================="<<endl;
	// }

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
				best_move_only_normal[r][c] = 0;
				best_move_with_turn[r][c] = 0;
			}
		}

		/*
		I think I can solve this problem using backtrack. Let's try
		*/
		int res = pathFinder(0, 0, 0, true, false, false);

		// cout<<"Best move only normal"<<endl;
		// for(int i=0; i<R; i++) {
		// 	for(int j=0; j < C; j++)
		// 		cout<<best_move_only_normal[i][j]<<" ";
		// 	cout<<endl;
		// }
		// cout<<"======================="<<endl;
		// cout<<"Best move with turn"<<endl;
		// for(int i=0; i < R; i++) {
		// 	for(int j=0; j < C; j++)
		// 		cout<<best_move_with_turn[i][j]<<" ";
		// 	cout<<endl;
		// }
		// cout<<endl;

		cout<<res<<endl;

	}
}