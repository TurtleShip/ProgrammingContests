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

int countNum(int n) {
	int res = 1;
	while( n != 1) {
		if(n % 2) {
			n = 3*n + 1;
		} else {
			n = n/2;
		}
		res++;
	}
	return res;
}

// res[i] = maxium result from 0 <= .. <= i
const int CAP = 1000000;
int res[CAP];
void preprocess() {
	res[0] = 1;
	res[1] = 1;
	for(int i = 2; i < CAP; i++) {
		res[i] = max(res[i-1], countNum(i));
	}
}

int main()
{
	int i,j;
	//preprocess();
	while(cin>>i>>j) {
		int res = 0;
		int oriI = i;
		int oriJ = j;
		if(i > j) 
			swap(i,j);

		for(int k = i; k <= j; k++)
			res = max(res, countNum(k));
		cout<<oriI<<" "<<oriJ<<" "<<res<<endl;
	}

	
    return 0;

}