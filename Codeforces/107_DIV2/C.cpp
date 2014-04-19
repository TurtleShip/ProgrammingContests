#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;
//returns true if n is prime
bool isPrime(ll n)
{
	if(n <= 1) return false;
	if(n == 2) return true;
	if(n%2 == 0)return false;
	ll m = (ll)sqrt(n);
	for(ll i=3; i <=m; i+=2ll)
		if(n%i == 0)
			return false;
	return true;
}

ll findFactor(ll n)
{
	if(n <= 1) return -1ll;
	if(n == 2) return -1ll;
	
	if(n%2 == 0) return 2ll;
	ll m = (ll)sqrt(n);
	for(ll i=3; i <=m; i+=2ll)
		if(n%i == 0)
		{
			return i;
		}
		
	return -1ll;
}

int main()
{
	
	ll q;
	cin>>q;
	
	/*
	If q is a prime, or 1, first player wins.
	It q is made of prime * prime, second player wins.
	If q is made of more than 2 primes, first player wins.
	*/
	if(q == 1 || isPrime(q))
	{
		cout<<"1"<<endl;
		cout<<"0"<<endl;
		return 0;
	}
	
	/*

	*/
	ll firstFac = findFactor(q);
	ll q_next = q/firstFac;
	
	ll secondFac = findFactor(q_next);
	
	if(secondFac == -1)
	{
		cout<<"2"<<endl;
	}
	else
	{
		cout<<"1"<<endl;
		cout<<(firstFac * secondFac)<<endl;
	}
	
	return 0;
}