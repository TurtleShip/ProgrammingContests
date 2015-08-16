#include <cstdio>
using namespace std;

/*
  Node structure for doubly-linked list
  Related problems
  UVa
  	( 12356, Army Buddies )
*/
typedef struct Node {
	int id;
	Node* left;
	Node* right;
	Node() {}
	Node(int _id) {
		id = _id;
		left = right = NULL;
	}

	Node(int _id, Node* _left, Node* _right) {
		id = _id;
		left = _left;
		right = _right;
	}
} Node;

Node buddies[100010];

int main() {
	int S, B, L, R;
	
	while(scanf("%d %d", &S, &B) && S != 0) {
		
		for(int i=1; i <= S; i++) {
			buddies[i] = Node(i);
		}

		for(int i=1; i <= S; i++) {
			buddies[i].left = &buddies[i-1];
			buddies[i].right = &buddies[i+1];
		}

		buddies[1].left = buddies[S].right = NULL;

		for(int i=0; i < B; i++) {
			scanf("%d %d", &L, &R);
			Node* leftBuddy = buddies[L].left;
			Node* rightBuddy = buddies[R].right;

			if(leftBuddy == NULL) printf("* ");
			else printf("%d ", leftBuddy->id);

			if(rightBuddy == NULL) printf("*\n");
			else printf("%d\n", rightBuddy->id);

			// update
			if(leftBuddy != NULL) leftBuddy->right = rightBuddy;
			if(rightBuddy != NULL) rightBuddy->left = leftBuddy;
		}

		printf("-\n");
	}
	return 0;
}