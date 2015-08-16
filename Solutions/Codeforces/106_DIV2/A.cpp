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
	int k;
	vector<int> water;
	
	cin>>k;
	for(int i=0; i < 12; i++)
	{
		int temp;
		cin>>temp;
		water.push_back(temp);
	}
	int N = water.size();
	
	sort(water.begin(), water.end());
	
	int sum = 0;
	int month = 0;
	bool found = false;
	
	if(k == 0){
		cout<<0<<endl;
		found = true;
	}
	for(int i=N-1; i >= 0 && !found; i--)
	{
		sum += water[i];
		month++;
		if(sum >= k)
		{
			cout<<month<<endl;
			found = true;
			break;
		}
	}
	
	if(!found)
		cout<<-1<<endl;
	
	
    return 0;
}