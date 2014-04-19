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
	string s,t;
	string yes = "Yes";
	string no = "No";

	while(cin>>s>>t) {
		int n = s.size();
		int m = t.size();

		if(n > m) {
			cout<<no<<endl;
			continue;
		}

		int i = 0;
		for(int j=0; j < m; j++) {
			if(s[i] == t[j]) {
				i++;
			}
 		}
 		if( i == n) {
 			cout<<yes<<endl;
 		} else {
 			cout<<no<<endl;
 		}

	}
	
    return 0;

}