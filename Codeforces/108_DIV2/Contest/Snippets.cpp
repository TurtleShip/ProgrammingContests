//Converts number n in base b (2 <=b <=10) into a decimal number
int toDecimal(int n, int b)
{
	int result = 0;
	int multiplier = 1;
	
	while(n > 0)
	{
		result = (n%10) * multiplier;
		multiplier *= b;
		n /= 10;
	}
	
	return result;
}

//converts a decimal number n to a number in base b (2 <= b <= 10)
int fromDecimal(int n, int b)
{
	int result = 0;
	int multiplier = 1;
	
	while(n > 0)
	{
		result = (n%b) * multiplier;
		multiplier *= 10;
		n /= b;
	}
	return result;
}

//converts a decimal number n to a number in base b (2 <= b <= 20)
string fromDecimalString(int n, int b)
{
	string chars = "0123456789ABCDEFGHIJ";
	string result = "";
	
	while(n>0)
	{
		result = chars[n%b] + result;
		n /= b;
	}
	return result;
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

/* Sieve of Eratosthenes
   It generates all the primes from 2 to a given number n.
   It begins by assuming that all numbers are prime. It then takes the first prime number and removes all of its multiples.
   It then applies the same method to the next prime number.
   This is continued until all numbers have been processed.
   */
vector<bool> sieve(int n)
{
	vector<bool> primes(n+1);
	fill(primes.begin(), primes.end(), true);
	primes[0] = false;
	primes[1] = false;
	int m = (int)sqrt(n);
	
	for(int i=2; i <=m; i++)
		if(primes[i])
			for(int k= i*i; k <= n; k+=i)
				primes[k] = false;
	
	return primes;
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


//a and b cannot both be 0
int GCD(int a, int b)
{
	if(b==0) return a;
	return GCD(b, a%b);
}

int LCM(int a, int b)
{
	return b * a / GCD(a,b);
}


bool DescendingSort(int a, int b)
{
	if(a > b) return true;
	return false;
}