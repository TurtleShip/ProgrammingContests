#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define pb(x) push_back(x)

int main() {
	vector<int> A(3, 0);
	vector<int> B(3, 0);
	vector<int> P;
	P.pb(0);
	P.pb(1);
	P.pb(2);

	while(scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &B[0], &B[1]) && A[0] != 0) {
		
		
		int res = -1;
		for(int cur = 1; cur <= 52; cur++) {
			bool isOkay = true;
			for(int i=0; i < 3; i++)
				isOkay &= cur != A[i];
			for(int i=0; i < 2; i++)
				isOkay &= cur != B[i];
			if(!isOkay) continue;

			// see if the prince always wins
			bool canLose = false;
			B[2] = cur;
			sort(P.begin(), P.end());	
			do {
				int win = 0;
				for(int i=0; i < 3; i++) {
					if(A[P[i]] < B[i]) win++;
				}
				if(win < 2) canLose = true;
			} while(!canLose && next_permutation(P.begin(), P.end()));

			if(!canLose) {
				res = cur;
				break;
			}
		}
		printf("%d\n", res);

	}
	return 0;
}
