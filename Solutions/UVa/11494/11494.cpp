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
	int r1,c1,r2,c2;

	while(cin>>r1>>c1>>r2>>c2) {
		if(r1 == 0 && c1 == 0 && r2 == 0 && c2 == 0)
			break;

		// answer is 0, 1, or 2
		if(r1 == r2 && c1 == c2) {
			cout<<0<<endl;
		} else if(abs(r1-r2) == abs(c1-c2) || r1 == r2 || c1 == c2) {
			cout<<1<<endl;
		} else {
			cout<<2<<endl;
		}
	}
	
    return 0;

}