#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char in[1000];

char isValid(char ch) {
	return ( 'a' <= ch && ch <= 'z');
}

int main() {
	char notEat[50] = "You won't be eaten!";
	char uhoh[10] = "Uh oh..";
	int s, t, N;
	bool isPalin;
	while(scanf("%[^\n]\n", in) && strcmp(in, "DONE") != 0) {
		N = strlen(in);
		s = 0, t = N-1;
		isPalin = true;
		for(int i=0; i < N; i++)
			in[i] = tolower(in[i]);
		while(isPalin && s < t) {
			if(!isValid(in[s])) {
				s++;
				continue;
			}
			if(!isValid(in[t])) {
				t--;
				continue;
			}
			if(in[s] != in[t]) isPalin = false;
			s++; t--;
		}

		printf("%s\n", isPalin ? notEat : uhoh);
	}
	return 0;
}