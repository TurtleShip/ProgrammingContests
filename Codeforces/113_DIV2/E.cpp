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
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;

int mod = 1000000007ll;

int main() {
	int N;
	cin >> N;

	ll ans = 0;
	if (N == 1) {
		cout << 0;
		return 0;
	}
    
	ll threes = 1;
	ll prev = 0;
	ll cur = 0;
	for (int i = 2; i <= N; i++) {
		threes = 3ll*threes;
		cur = threes - prev;
		if (cur < 0) cur +=mod;
		threes %= mod;
		cur %= mod;
		prev = cur;
	}
	
	cout << cur;
	return 0;
}