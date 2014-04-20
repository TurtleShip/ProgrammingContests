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

typedef long long LL; 

LL price[10000010];
set<int> auction;
vector<LL> goodStuff;

int main() {
	int N, M;
	cin>>N>>M;
	for(int i=1; i <= N; i++)
		cin>>price[i];

	int cur;
	for(int i=0; i < M; i++) {
		cin>>cur;
		auction.insert(cur);
		goodStuff.push_back(price[cur]);
	}
	LL point = 0ll;
	for(int i=1; i <= N; i++) {
		if(auction.count(i) == 0)
			point += price[i];
	}

	sort(goodStuff.begin(), goodStuff.end());

	for(int i= goodStuff.size() - 1; i >= 0; i--) {
		point += max(goodStuff[i], point);
	}
	cout<<point<<endl;


	return 0;

}