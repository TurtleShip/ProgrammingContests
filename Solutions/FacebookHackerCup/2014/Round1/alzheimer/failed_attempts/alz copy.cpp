#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

const int P = 35; // number of primes
const int MAXAGE = 149; // the maximum number an age can be
int primes[P];
int arr[20];
ll primeRep[MAXAGE + 1];

bool isPrime(int n);
void seeLogic();
void preprocess();




int main() {
	preprocess();
	int T, N, K;
	cin>>T;
	for(int cid=1; cid <= T; cid++) {
		cin>>N>>K;
		for(int i=0; i < N; i++)
			cin>>arr[i];

		

	}

    return 0;
}

//returns true if n is prime
bool isPrime(int n)
{
	if(n <= 1) return false;
	if(n == 2) return true;
	if(n%2 == 0)return false;
	int m = (int)sqrt(n);
	for(int i=3; i <=m; i+=2)
		if(n%i == 0)
			return false;
	return true;
}

void preprocess() {
	int ct = 0;
	int n = 2;
	while(ct < 35) {
		if(isPrime(n)) primes[ct++] = n;
		n++;
	}
	for(int i=0; i < MAXAGE; i++) {
		ll rep = 0ll;
		for(int j=0; j < P; j++) {
			if (rep % primes[j] == 0)
				rep |= (j << 1ll);
		}
		primeRep[i] = rep;
	}
}


void seeLogic() {

	// 20 primes that are bigger than 50
	int n = 51;
	int ct = 0;
	int overFifty[20];
	while(ct < 20) {
		if(isPrime(n)) overFifty[ct++] = n;
		n++;
	}
	printf("List of 20 primes over 50\n");
	for(int i=0; i < ct; i++)
		printf("overFifty[%d] = %d\n", i, overFifty[i]);
	printf("===============\n\n");

	// primes that are smaller than 50
	n = 2;
	vector<int> V;
	while(n < 50) {
		if(isPrime(n)) V.push_back(n);
		n++;
	}
	int N = V.size();
	printf("There are %d primes before 50.\n", N);
	for(int i=0; i < N; i++) {
		printf("primes[%d] = %d\n", i, V[i]);
	}
	printf("===============\n\n");

	printf("From these primes, we can make %d numbers that are coprimes to each other\n", N / 2);
	for(int i=0; i < N/2; i++)
		printf("%d * %d = %d\n", V[i], V[N-1-i], V[i] * V[N-1-i]);
	printf("===============\n\n");

	printf("This means that we need at most %d primes.\n", 20 - (N/2));
}

void preprocess() {
	int ct = 0;
	int n = 2;
	while(ct < 35) {
		if(isPrime(n)) primes[ct++] = n;
		n++;
	}
}