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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)
typedef long long ll;

int main()
{
	int arr[4];
	int d;
	for(int i=0; i < 4; i++)
		cin>>arr[i];
		
	cin>>d;
	
	vector<bool> chk(d+1, false);
	
	for(int i=0; i < 4; i++)
	{
		int num = arr[i];
		while(num <= d)
		{
			chk[num] = true;
			num += arr[i];
		}
			
	}

	int ans = 0;
	for(int i=1; i <= d; i++)
		if(chk[i]) ans++;
		
	cout<<ans<<endl;
    return 0;
}