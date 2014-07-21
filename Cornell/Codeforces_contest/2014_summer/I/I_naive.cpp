#include <cstdio>
using namespace std;

int main() {
	int a,b,w,x,c, res = 0;

	scanf("%d %d %d %d %d", &a, &b, &w, &x, &c);
	while(c > a) {
		c--;
		if(b >= x) b -= x;
		else {
			a--;
			b = w - (x-b);
		}
		res++;
	}
	printf("%d\n", res);
	return 0;
}