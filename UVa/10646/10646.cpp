#include <cstdio>
#include <string>
using namespace std;

int before[100];
char beforeCard[100];
char beforeSuit[100];
int afterCard[100];
char afterSuit[100];

char card;

int main() {
	int T, Y, X, top, res, left;
	scanf("%d", &T);

	for(int cid=1; cid<=T; cid++) {
		for(int i=52; i >= 1; i--) {
			scanf(" %c%c", &beforeCard[i], &beforeSuit[i]);
			card = beforeCard[i];
			if('2' <= card && card <= '9') before[i] = (card - '0');
			else before[i] = 10;
		}

		Y = 0;
		top = 26;
		for(int i=0; i < 3; i++) {
			X = before[top];
			Y += X;
			top += 1 + (10 - X);
		}
		
		// put 25 cards on top
		for(int i=1; i <= 25; i++) {
			afterCard[i] = beforeCard[i];
			afterSuit[i] = beforeSuit[i];
		}

		// cards left from the game
		left = 52 - top + 1;
		for(int i=0; i < left; i++) {
			afterCard[i+26] = beforeCard[i+top];
			afterSuit[i+26] = beforeSuit[i+top];
		}
		printf("Case %d: %c%c\n", cid, afterCard[25 + left - Y + 1], afterSuit[25 + left - Y + 1]);

	}

	
	return 0;
}