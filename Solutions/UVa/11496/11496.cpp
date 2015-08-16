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

const int maxN = 10010;
int arr[maxN];

int main()
{
	int N, res;
	while(cin>>N) {
		if(N == 0) break;

		for(int i=1; i <= N; i++)
			cin>>arr[i];

		arr[0] = arr[N];
		arr[N+1] = arr[1];

		res = 0;
		for(int i=1; i <= N; i++) {
			if( arr[i] < arr[i-1] && arr[i] < arr[i+1] ) {
				res++;
			} else if( arr[i] > arr[i-1] && arr[i] > arr[i+1] ) {
				res++;
			}
				
		}

		cout<<res<<endl;
	}
	
    return 0;

}