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
	int n,k,l,c,d,p,nl,np;
	
	cin>>n;
	cin>>k;
	cin>>l; cin>>c; cin>>d; cin>>p; cin>>nl; cin>>np;
	
	int milk = k * l;
	int limes = c * d;
	
	int toast = min(milk/nl, limes);
	toast = min(toast , p/np);
	int ans = toast / n;
	
	cout<<ans<<endl;
    return 0;
}