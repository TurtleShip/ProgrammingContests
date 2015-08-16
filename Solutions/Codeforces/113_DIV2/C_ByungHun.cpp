#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <queue>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX_N	1500
int S[1500];
int main() {

	int N, avg;
	cin >> N >> avg;
	
	for (int i = 0; i < N; i++) cin >> S[i];
	
	sort(S,S+N);
	if (avg < S[0]) {
		cout << N;
		return 0;
	} 
	if (avg > S[N-1]) {
		cout << 1+N;
		return 0;
	}
	int low = lower_bound(S,S+N,avg)-S;
	int high = upper_bound(S,S+N,avg)-S;

	int front, back;
	bool added = false;
	if (high - low == 0) {
		N++;
		S[N-1] = avg;
		sort(S,S+N);
		added = true;
	}

	low = lower_bound(S,S+N,avg)-S;
	high = upper_bound(S,S+N,avg)-S	;

	int ans = 1000;
	for (int i = low; i < high; i++) {
		front = i;
		back = N-1-i;
		
		int temp = 0;
		if (front < back-1) {
			temp = back-1-front;
		} else if (front > back) {
			temp = front - back;
		}
		if (temp < ans) ans = temp;
	}
	if (added) ans++;
	cout << ans;
	return 0;
}