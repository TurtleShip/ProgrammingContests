#include <cstdio>
#include <set>
using namespace std;

typedef long long LL;

int main() {

	int N, smallest, biggest, total, cur;
	LL res;

	while(scanf("%d", &N) && N != 0) {
		// init variables
		res = 0ll;
		multiset<int> S;
		while(N--) {
			scanf("%d", &total);
			
			for(int i=0; i < total; i++) {
				scanf("%d", &cur);
				S.insert(cur);
			}

			auto last = S.end(); 
			last--;
			biggest = *(last);
			smallest = *(S.begin());
			S.erase(last);
			S.erase(S.begin());
			res += LL(biggest - smallest);
		}

		printf("%lld\n", res);
	}
	return 0;
}