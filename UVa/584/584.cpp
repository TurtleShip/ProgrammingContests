#include <cstdio>
#include <cstring>
using namespace std;

int score[15];
char in[100];

/*
	Calculates the base score at index idx.
	Note that this function doesn't calculate the bonus point
	from either strike or spare.
*/
int getScore(int idx) {
	if('0' <= in[idx] && in[idx] <= '9') return in[idx] - '0';
	if(in[idx] == '/') return 10 - (in[idx-2] - '0');
	return 10;
}

int main() {

	int curFrame, score, idx, N;
	char cur;
	while(scanf("%[^\n]\n", in) && in[0] != 'G') {
		curFrame = score = idx = 0;
		N = strlen(in);

		while(curFrame < 10) {
			char cur = in[idx];

			// normal
			if('0' <= cur && cur <= '9') {
				score += getScore(idx) + getScore(idx+2);
				if(in[idx+2] == '/')
					score += getScore(idx+4);
				idx += 4;
			} else if(cur == 'X') {
				score += getScore(idx) + getScore(idx+2) + getScore(idx+4);
				idx += 2;
			}
			curFrame++;
		}

		printf("%d\n", score);
	}

	return 0;
}