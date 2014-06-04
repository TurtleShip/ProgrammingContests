#include <cstdio>
using namespace std;

typedef long long LL;

int main() {
	// There are total of 949 solutions
	LL divisor = 100ll * 100ll * 100ll;
	printf("\"");
	for(int a=2; a <= 2000; a++) {
		for(int b=a; b <= 2000 - a; b++) {
			for(int c=b; c <= 2000 - a - b; c++) {
				
				LL product = LL(a) * LL(b) * LL(c);
				LL sum = a + b + c;
				if(product <= divisor) continue;
				int d = (sum * divisor) / (product - divisor);
				sum += d;

				if(sum > 2000 || d < c) continue;
				if(sum * divisor != (product * LL(d))) continue;				
				printf("%d.%02d %d.%02d %d.%02d %d.%02d\\n", 
					a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
			}
		}
	}
	printf("\"");
	return 0;
}