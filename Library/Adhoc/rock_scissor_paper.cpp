#include <cstdio>
using namespace std;
char rock = 'R';
char scissor = 'S';
char paper = 'P';

/*
	Returns true if 'me' wins 'you'
*/
bool isWin(char me, char you) {
	if(me == rock) return you == scissor;
	else if(me == scissor) return you == paper;
	else return you == rock;
}

int main() {
	return 0;
}
