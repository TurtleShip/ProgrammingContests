#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[76];
const ll maxNum = 1000000001000000000ll;

bool isPrime[200];
int M[200];

//returns true if n is prime
bool checkPrime(int n)
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

ll helper(int cur, int p_idx) {
	
	ll res = maxNum;
	for(int i=2; i < cur; i++) {
		if(cur % i == 0) {
			ll power = 1ll;
			// power
			for(int j=0; j < i-1; j++)
				power *= M[p_idx];

			if(power <= 0ll) continue;
			ll tmp = power * helper(cur/i, p_idx+1);
			if(tmp <= 0ll) continue;
			res = min(res, tmp);
		}
	}
	ll power = 1ll;
	for(int j=0; j < cur-1; j++)
		power *= M[p_idx];

	if(power > 0ll)
		res = min(res, power);

	return res;
}

ll solve(int N) {
	ll one = helper(2*N, 0);
	ll two = helper(2*N-1, 0);
	if(one <= 0ll) return two;
	if(two <= 0ll) return one;	
	return min(one,two);
}

void preprocess() {
	int idx = 0;
	int cur = 2;
	while(idx < 200) {
		if(checkPrime(cur))
			M[idx++] = cur;
		cur++;
	}
	for(int i=1; i <= 75; i++)		
		arr[i] = solve(i);
}

int main() {
	preprocess();
	
	int n;
	while(cin>>n && n != 0) {
		cout<<arr[n]<<endl;
	}
	return 0;
}