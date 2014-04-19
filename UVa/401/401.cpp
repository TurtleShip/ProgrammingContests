#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<char, char> rev;
char E = '!'; // empty
char in[30];
char mirror[30];
char value[35] = {'A',E,E,E,'3',E,E,'H','I','L',E,'J','M',E,'O',E,E,E,'2','T','U','V','W','X','Y','5','1','S','E',E,'Z',E,E,'8',E};

bool isPalin() {
	int s = 0, t = strlen(in) - 1;
	while(s < t) {
		if(in[s] != in[t]) return false;
		s++;
		t--;
	}
	return true;
}

bool isMirrored() {
	int N = strlen(in);
	for(int i=0; i < N; i++) {
		if(rev[in[i]] == E) return false;
		mirror[i] = rev[in[i]];
	}

	for(int i=0; i < N; i++)
		if(in[i] != mirror[N-1-i]) return false;
		
	return true;
}

int main() {
	char ch = 'A';
	for(int i=0; i < 26; i++)
		rev[ch++] = value[i];
	ch = '1';
	for(int i=26; i < 35; i++)
		rev[ch++] = value[i];

	while(scanf("%s", in) != EOF) {
		bool pal = isPalin();
		bool mir = isMirrored();
		printf("%s", in);
		if(pal && mir) printf(" -- is a mirrored palindrome.\n");
	 	else if(pal) printf(" -- is a regular palindrome.\n");
	 	else if(mir) printf(" -- is a mirrored string.\n");
	 	else printf(" -- is not a palindrome.\n");
	 	printf("\n");
	}
	return 0;
}