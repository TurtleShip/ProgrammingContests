#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	int N, a, b, s, d;

	// a + b = s
	// abs(a - b) = d  => a - b = -d  or a - b = d
	// a + b = s && a - b = -d  => a = (s - d) / 2, b = s - a
	// a + b = s && a - b = d   => a = (s + d) / 2, b = s - a
 	scanf("%d", &N);
	while(N--) {
		scanf("%d %d", &s, &d);
		a = b = -1;
		a = (s - d ) / 2;
		b = s - a;
		if( (a + b == s) && abs(a-b) == d && a >= 0 && b >= 0 ) printf("%d %d\n", max(a,b), min(a,b));
		else {
			a = (s + d) / 2;
			b = s - a;
			if( (a + b == s) && abs(a-b) == d && a >= 0 && b >= 0 ) printf("%d %d\n", max(a,b), min(a,b));
			else printf("impossible\n");
		}
	}

	return 0;
}