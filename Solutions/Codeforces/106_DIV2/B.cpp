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

int toInt(char ch)
{
	if('0' <= ch && ch <= '9')
		return (ch - '0');
		
	return (ch - 'A' + 10);
}


int toDecimal(string num, int b)
{
	int result = 0;
	int mult = 1;
	
	for(int i=(num.size() - 1); i >= 0; i--)
	{
		result += toInt(num[i]) * mult;
		mult *= b;
	}
	return result;
}


int main()
{
	string input;
	cin>>input;
	
	bool found = false;
	
	int hourSt = -1;
	int mid = 0;
	int minSt = -1;
	

	for(int i=0; i < input.size(); i++)
	{
		if(input[i] == ':')
		{
			mid = i;
			break;
		}
	}
	
	for(int i=0; i < mid; i++)
	{
		if(input[i] != '0')
		{
			hourSt = i;
			break;
		}
	}
	
	for(int i=mid+1; i < input.size(); i++)
	{
		if(input[i] != '0')
		{
			minSt = i;
			break;
		}
		
	}
	
	
	string HH = (hourSt == -1) ? "0" : input.substr(hourSt,(mid-hourSt));
	string MM = (minSt == -1) ? "0" : input.substr(minSt);
	
	

	/*
	infinite case is when both number are single digit.
	*/
	bool isValid = true;
	if( HH.size() == 1 && MM.size() == 1)
	{
		if(toInt(HH[0]) >= 24)
			cout<<0;
		else
			cout<<-1;
		isValid = false;
	}
	
	
	int base = 0;
	for(int i=0; i < HH.size(); i++)
	{
		base = max(base, toInt(HH[i]));
	}
	
	for(int i=0; i < MM.size(); i++)
	{
		base = max(base, toInt(MM[i]));
	}

	base++;
	int count = 0;
	if(toDecimal(HH, base) < 24 && toDecimal(MM,base) < 60 && isValid)
	{
		count++;
		cout<<base;
	}
		

	base++;
	while(true && isValid)
	{
		if(toDecimal(HH, base) < 24 && toDecimal(MM,base) < 60)
		{
			cout<<" "<<base;
			base++;
			count++;
		}
		else break;
	}
	
	if(count==0 && isValid)
		cout<<"0";
	
    return 0;
}