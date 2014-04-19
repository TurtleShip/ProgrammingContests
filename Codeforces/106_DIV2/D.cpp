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

int mod = 1000000007;

int rec(int idx , int prevColor)
{
	//how do we ensure that exactly one of matching prbacket is colored
}

string eyes;


int main()
{
	/*
	*/
	cin>>eyes;
	int n;
	cin>>n;
	
	vector<string> words;
	for(int i=0; i < n; i++)
	{
		string temp;
		cin>>temp;
		words.push_back(temp);
	}
	
	vector< vector<int> >pos;
	int Alpha = 'Z' - 'A' + 1;
	
	pos.resize(Alpha);
	
	for(int i=0; i < eyes.size(); i++)
	{
		int ch = eyes[i] - 'A';
		pos[ch].push_back(i);
	}
	
	for(int i=0; i < words.size(); i++)
	{
		string cur = words[i];
		int sz = cur.size();
		
		int count = 0;
		for(int i=0; i < sz; i++)
		{
			
		}
	}
	
    return 0;
}