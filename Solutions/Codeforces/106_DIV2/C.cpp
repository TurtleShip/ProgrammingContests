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

typedef long long ll;

int main()
{
	int n;
	cin>>n;
	
	vector< pair<int,int> > boys;
	
	for(int i=1; i <= n; i++)
	{
		int temp;
		cin>>temp;
		boys.push_back(make_pair(temp,i));
	}
	
	sort(boys.begin(), boys.end());
	
	vector< pair<int,int> > x;
	vector< pair<int,int> > y;
	long long xSum = 0;
	long long ySum = 0;
	long long maxP = boys[n-1].first;
	
	for(int i=(n-1); i >= 0; i--)
	{
		if(i%2 == 0)
		{
			x.push_back( boys[i] );
			xSum += boys[i].first;
		}
		else
		{
			y.push_back( boys[i] );
			ySum += boys[i].first;
		}
	}
	
	while( (xSum - ySum) > maxP && abs( int(x.size() - y.size())  ) <= 1)
	{
		int point = x[0].first;
		int num = x[0].second;
		
		x.erase(x.begin());
		xSum -= point;
		ySum += point;
		
		y.push_back( make_pair(point,num));
	}
	
	cout<<x.size()<<endl;
	for(int i=0; i < x.size(); i++)
	{
		cout<<x[i].second<<" ";
	}
	cout<<endl;
	
	cout<<y.size()<<endl;
	for(int i=0; i < y.size(); i++)
	{
		cout<<y[i].second<<" ";
	}
	cout<<endl;
	
    return 0;
}