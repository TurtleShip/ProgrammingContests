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

typedef long long ll;

int howMany[1010];
bool isPalin[1010];



bool isFairAndSquare(int num) {
	// check square root
	int root = round(sqrt(num));
	if(root*root != num)
		return false;

	if(!isPalin[root]) return false;
	return isPalin[num];
}

void preprocess() {
	howMany[0] = 0;
	howMany[1] = 1;
	isPalin[1] = 1;
	string str;
	for(int i=2; i <= 1000; i++) {
		stringstream ss;
		ss << i;
		ss >> str;
		int s = 0;
		int t = str.size() - 1;
		isPalin[i] = true;
		while(s < t) {
			if(str[s] != str[t]) {
				isPalin[i] = false;
				break;
			}
			s++;
			t--;
		}

		howMany[i] = howMany[i-1];
		if(isFairAndSquare(i))
			howMany[i]++;
	}
}

int main()
{
	preprocess();
	int T, A, B, res;
	int idx = 0;

	cin>>T;

	while((++idx) <= T) {
		cout<<"Case #"<<idx<<": ";
		cin>>A>>B;
		res = howMany[B] - howMany[A-1];
		cout<<res<<endl;
	}

    return 0;

}