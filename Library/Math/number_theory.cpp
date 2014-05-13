#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

//a and b cannot both be 0
// Greatest Common Denominator
int GCD(int a, int b) {
	if(b==0) return a;
	return GCD(b, a%b);
}

// Least Common Multiple
int LCM(int a, int b) {
	return b * a / GCD(a,b);
}

//returns true if n is prime
bool isPrime(int n) {
	if(n <= 1) return false;
	if(n == 2) return true;
	if(n%2 == 0)return false;
	int m = (int)sqrt(n);
	for(int i=3; i <=m; i+=2)
		if(n%i == 0)
			return false;
	return true;
}


ll pascal[11][11];

//makes pascal table. It can be used to get a combination.
//For example, pascal[10][5] is the same as number of ways to pick 5 items out of 10 items
void combiPascal()
{
	memset(pascal, 0, sizeof(pascal));

	pascal[0][0] = 1;
	for(int i=0; i <=20; i++)
		pascal[i][0] = 1;

	for(int i=1; i <= 20; i++)
		for(int j=1; j <= 20; j++)
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
}



/*
 Sieve of Eratosthenes
It generates all the primes from 2 to a given number n.
It begins by assuming that all numbers are prime.
 It then takes the first prime number and removes all of its multiples.
It then applies the same method to the next prime number.
This is continued until all numbers have been processed.
*/
const int maxN = 1000000;
bool sievePrime[maxN+1];
void sieve(int n)
{
    memset(sievePrime, true, sizeof(sievePrime));
	sievePrime[0] = false;
	sievePrime[1] = false;
	int m = (int)sqrt(n);

	for(int i=2; i <=m; i++)
		if(sievePrime[i])
			for(int k= i*i; k <= maxN; k+=i)
				sievePrime[k] = false;
}


int main() {

	return 0;
}
