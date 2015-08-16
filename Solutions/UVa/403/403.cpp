#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define pb(x) push_back(x)

int max_N = 60;
char page[65][65];


// I copied this array from 
// http://online-judge.uva.es/board/viewtopic.php?f=5&t=5118
// I didn't want to waste time typing this.
// It would've been nice if UVa provided a function such that
// give row, col, and character of c5 it returns the corresponding
// character. Or at least they could've provided a 2-d array like
// the one below.
char c5_convert[26][31] = 
{ 
".***..*...*.*****.*...*.*...*.", 
"****..*...*.****..*...*.****..", 
".****.*...*.*.....*......****.", 
"****..*...*.*...*.*...*.****..", 
"*****.*.....***...*.....*****.", 
"*****.*.....***...*.....*.....", 

".****.*.....*..**.*...*..***..", 
"*...*.*...*.*****.*...*.*...*.", 
"*****...*.....*.....*...*****.", 
"..***....*.....*..*..*...**...", 
"*...*.*..*..***...*..*..*...*.", 
"*.....*.....*.....*.....*****.", 
"*...*.**.**.*.*.*.*...*.*...*.", 
"*...*.**..*.*.*.*.*..**.*...*.", 
".***..*...*.*...*.*...*..***..", 
"****..*...*.****..*.....*.....", 
".***..*...*.*...*.*..**..****.", 
"****..*...*.****..*..*..*...*.", 
".****.*......***......*.****..", 
"*****.*.*.*...*.....*....***..", 
"*...*.*...*.*...*.*...*..***..", 
"*...*.*...*..*.*...*.*....*...", 
"*...*.*...*.*.*.*.**.**.*...*.", 
"*...*..*.*....*....*.*..*...*.", 
"*...*..*.*....*.....*.....*...", 
"*****....*....*....*....*****." 
}; 

void printC5(int row, int col, char c5_letter) {
	int cur_row, cur_col;
	for(int r = 0; r < 5 && (row + r) <= max_N; r++) {
		for(int c = 0; c < 6 && (col + c) <= max_N; c++) {
			cur_row = row + r;
			cur_col = col + c;
			if(1 <= cur_row && cur_row <= max_N && 1 <= cur_col && cur_col <= max_N) {
				char ch = c5_letter == ' ' ? '.' : c5_convert[c5_letter - 'A'][r*6 + c];
				if(ch != '.') page[row + r][col + c] = ch;	
			}
		}
	}
}

void printC1(int row, int col, char c1_letter) {
	if(1 <= row && row <= max_N &&
		1 <= col && col <= max_N && 
		c1_letter != '.' && c1_letter != ' ') page[row][col] = c1_letter;
}
// .P command
void placeString(bool isC1, int row, int col, char* str) {

	int cur_col = col;
	for(int i = 0; i < strlen(str); i++) {
		if(isC1) {
			printC1(row, cur_col, str[i]);
			cur_col++;	
		} else {
			printC5(row, cur_col, str[i]);
			cur_col += 6;
		}
	}
}

void leftJustify(bool isC1, int row, char* str) {
	placeString(isC1, row, 1, str);
}

void rightJustify(bool isC1, int row, char* str) {
	int cur_col = isC1 ? 60 : 55;
	for(int i = strlen(str) - 1; i >= 0; i--) {
		if(isC1) {
			printC1(row, cur_col, str[i]);
			cur_col--;
		} else {
			printC5(row, cur_col, str[i]);
			cur_col -= 6;
		}
	}
}

void center(bool isC1, int row, char* str) {
	int N = strlen(str);
	int left, right, left_idx, right_idx;
	left = isC1 ? 30 : 25;
	right = 31;
	if(!isC1 && N % 2 == 1) {
		left -= 3;
		right -= 3;
	}
	left_idx = (N / 2) - 1;
	right_idx = left_idx + 1;

	while(0 <= left_idx) {
		if(isC1) {
			printC1(row, left, str[left_idx]);
			left--;
		} else {
			printC5(row, left, str[left_idx]);
			left -= 6;
		}
		left_idx--;
	}

	while(right_idx < N) {
		if(isC1) {
			printC1(row, right, str[right_idx]);
			right++;
		} else {
			printC5(row, right, str[right_idx]);
			right += 6;
		}
		right_idx++;
	}
}

void printAll() {
	for(int r=1; r <= max_N; r++) {
		for(int c=1; c <= max_N; c++) {
			printf("%c", page[r][c]);
		}
		printf("\n");
	}
	printf("\n");
	printf("------------------------------------------------------------\n");
	printf("\n");

}

void initPage() {
	for(int r=1; r <= max_N; r++)
		for(int c=1; c<= max_N;c++) 
			page[r][c] = '.';
}

int main() {

	char line[150];
	char cmd;
	int c_num, row, col;
	char arg[70];

	initPage();
	while( scanf(" %[^\n]\n", line) != EOF ) {
		cmd = line[1];
		if(cmd == 'P') {
			sscanf(line, "%*s %*c%d %d %d |%[^\n|]", &c_num, &row, &col, arg);
			placeString(c_num == 1, row, col, arg);

		} else if (cmd == 'L') {
			sscanf(line, "%*s %*c%d %d |%[^\n|]", &c_num, &row, arg);
			leftJustify(c_num == 1, row, arg);

		} else if (cmd == 'R') {
			sscanf(line, "%*s %*c%d %d |%[^\n|]", &c_num, &row, arg);
			rightJustify(c_num == 1, row, arg);

		} else if (cmd == 'C') {
			sscanf(line, "%*s %*c%d %d |%[^\n|]", &c_num, &row, arg);
			center(c_num == 1, row, arg);

		} else {
			printAll();
			initPage();
		}

	}
	return 0;
}