#include <cstdio>
#include <cstdlib>
using namespace std;

int nums[150];

//a and b cannot both be 0
int GCD(int a, int b) {
	if(b==0) return a;
	return GCD(b, a%b);
}

int get_len(int num) {
	int len = 0;
	while(num > 0) {
		len++;
		num /= 10;
	}
	return len;
}

int main() {
	int N, sum, avg, up, down, gcd, len, up_len, down_len, total_len, cid = 1;
	bool is_neg;

	while(scanf("%d", &N) && N != 0) {
		sum = 0;
		for(int i=0; i < N; i++) {
			scanf("%d", &nums[i]);
			sum += nums[i];
		}
		avg = sum / N;

		printf("Case %d:\n", cid++);
		if(avg*N == sum) {
			if(avg < 0) printf("- ");
			printf("%d\n", abs(avg));
		} else {
			is_neg = sum < 0;
			sum = abs(sum);
			avg = abs(avg);
			up = sum - (avg*N);
			down = N;
			gcd = GCD(up, down);
			up /= gcd;
			down /= gcd;
			len = 0;
			
			if(is_neg) len += 2;

			up_len = get_len(up);
			down_len = get_len(down);
			total_len = down_len;
			if(is_neg) total_len += 2;
			if(avg != 0) total_len += get_len(avg);

			// print up
			for(int i=0; i < (total_len - up_len); i++)
				printf(" ");
			printf("%d\n", up);

			// print middle
			if(is_neg) printf("- ");
			if(avg != 0) printf("%d", avg);
			for(int i=0; i < down_len; i++)
				printf("-");
			printf("\n");

			// print bottom
			for(int i=0; i < (total_len - down_len); i++)
				printf(" ");
			printf("%d\n", down);

		}
	}
	return 0;
}