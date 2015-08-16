#include <iostream>
using namespace std;
const int maxn = 1010;
int sum[maxn][maxn]; //sum[i][j] = sum from (1,1) to (i,j)
int board[maxn][maxn];

// r1 <= r2  , c1 <= c2
int rect_sum(int r1, int c1, int r2, int c2) {
	if(r1 == r2 && c1 == c2) return board[r1][c1];
	if(r1 == r2) return sum[r1][c2] - sum[r1][c1-1];
	if(c1 == c2) return sum[r2][c1] - sum[r1-1][c1];
	return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

int main() {
	int R,C;
	while(cin>>R>>C && (R+C != 0)) {
		bool has_one = false;
		for(int r=1;r <= R; r++)
			for(int c=1; c <= C; c++) {
				cin>>board[r][c];
				if(!has_one && board[r][c]) has_one = true;
			}
		if(!has_one) {
			cout<<0<<endl;
			continue;
		}

		for(int r=1; r <= R; r++)
			for(int c=1; c<= C; c++)
				sum[r][c] = sum[r-1][c] + sum[r][c-1] - sum[r-1][c-1] + board[r][c];
		
		int res = 1;
		for(int r=1; r <= (R-res); r++) 
			for(int c=1; c <= (C-res); c++) {
				int cur_len = res;
				while( (r + cur_len) <= R && (c + cur_len) <= C ) {
					if(rect_sum(r,c,r+cur_len, c+cur_len) != (cur_len+1) * (cur_len+1) ) break;
					cur_len++;
				}
				res = max(res, cur_len);
			}
		cout<<res<<endl;
	}
}