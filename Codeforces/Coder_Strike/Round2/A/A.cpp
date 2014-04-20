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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll; 
int arr[500];
int main() {
	int N, M, small, big;

	cin>>N>>M>>small>>big;

	for(int i=0; i < M; i++)
		cin>>arr[i];

	int curMin = arr[0];
	int curMax = arr[0];

	for(int i=0; i < M; i++) {
		curMin = min(curMin, arr[i]);
		curMax = max(curMax, arr[i]);
	}

	bool correct = true;
	if(curMin < small) correct = false;
	if(curMax > big) correct = false;
	if(correct) {
		int needed = 0;
		needed += (curMin == small) ? 0 : 1;
		needed += (curMax == big) ? 0 : 1;

		if(small == big) needed -= 1; // This shouldn't happen 1 <= min < max <= 100

		if(needed > (N-M)) correct = false;
	}

	if(correct) cout<<"Correct"<<endl;
	else cout<<"Incorrect"<<endl;

	return 0;
}



