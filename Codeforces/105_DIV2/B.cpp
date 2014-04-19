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
	/*
	Princess runs at vp miles per hour.
	Dragon flies at vd miles per hour.
	*/
	double vp, vd, t, f, c;
	cin>>vp;
	cin>>vd;
	cin>>t;
	cin>>f;
	cin>>c;
	
	double distP = vp * t; //distance traveled by princess
	double distD = 0; //distance traveled by dragon
	int cookie = 0;
	bool chk = true;
	if(vp >= vd)
	{
		chk = false;
	}
	while(distP < c && chk)
	{
		//calculate time until dragon catches princess
		double t1 = distP / (vd - vp);
		
		//update princess's movement
		distP += t1 * vp;
		if(distP >= c) break;
		cookie++;
		
		//calculate time for dragon to go back to the cave and straignten things out.
		double t2 = t1 + f;
		
		//update princess's movement
		distP += t2 * vp;
	}
	
	cout<<cookie<<endl;
	
    return 0;
}