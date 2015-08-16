#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define pb(x) push_back(x)

const int maxSum = 35;
int circle[20];
vector< vector<int> > res;
int N;
bool isPrime[maxSum + 10];
bool taken[20];

void fillCircle(const int& idx) {
	if(idx == N) {
		// bool sanityCheck = true;
		if(isPrime[circle[0] + circle[N-1]]) {
			vector<int> curRes(N,0);
			for(int i=0; i < N; i++)
				curRes[i] = circle[i];
			res.pb(curRes);
		}
		return;
	}

	for(int i=1; i <= N; i++) {
		if(!taken[i]) {
			taken[i] = true;
			circle[idx] = i;
			if(isPrime[circle[idx] + circle[idx-1]]) fillCircle(idx + 1);
			taken[i] = false;
		}
	}
}

int main() {
	int cid = 1;
	memset(isPrime, true, sizeof(isPrime));
	
	for(int i=2; i <= maxSum; i++) {
		if(isPrime[i]) {
			for(int j=2*i; j <= maxSum; j += i)
				isPrime[j] = false;
		}
	}

	while(scanf("%d", &N) != EOF) {
		res.clear();
		circle[0] = 1;
		taken[1] = true;
		if(N > 1) fillCircle(1);
		if(cid > 1) printf("\n");

		printf("Case %d:\n", cid++);
		for(auto curRes : res) {
			printf("%d", curRes[0]);
			for(int i=1; i < N; i++)
				printf(" %d", curRes[i]);
			printf("\n");		
		}
	}

	return 0;
}