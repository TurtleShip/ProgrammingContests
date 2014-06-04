#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 0x3F3F3F3F;

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int getDist(const pair<int,int>& a, const pair<int,int>& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
	int M, num, cur, best;
	char ch;

	while(scanf("%d", &M) != EOF) {
		vector< pair<int, int> > oneLoc;
		vector< pair<int, int> > threeLoc;
		for(int i=0; i < M; i++) {
			for(int j=0; j < M; j++) {
				scanf(" %c", &ch);
				cur = int(ch - '0');
				if(cur == 1) oneLoc.pb( mp(i,j) );
				else if(cur == 3) threeLoc.pb( mp(i,j) );
			}
		}

		best = 0;
		for(auto one : oneLoc) {
			cur = INF;
			for(auto three : threeLoc)
				cur = min(cur, getDist(one, three));
			best = max(cur, best);
		}

		printf("%d\n", best);
	}
	return 0;
}