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

int main()
{
	int K;
	int N, M;
	int x,y;

	while(cin>>K) {
		if(K == 0) break;
		cin>>N>>M;

		while(K--) {
			cin>>x>>y;

			// find border
			if(x == N || y == M) {
				cout<<"divisa"<<endl;
			} else if( y > M) {
				if(x > N) cout<<"NE"<<endl;
				else cout<<"NO"<<endl;
			} else {
				if(x > N) cout<<"SE"<<endl;
				else cout<<"SO"<<endl;
			}

		}
	}
	
    return 0;

}