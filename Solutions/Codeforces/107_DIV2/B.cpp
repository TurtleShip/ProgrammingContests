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

struct Data
{
	string name;
	int taxi;
	int pizza;
	int girl;
	Data(string str)
	{
		name = str;
		taxi = 0;
		pizza = 0;
		girl = 0;
	}
};

int getType(string num)
{
	bool isTaxi = false;
	bool isPizza = true;
	
	if(count(num.begin(), num.end(), num[0]) == 6) isTaxi = true;
	
	string con = "";
	con += num.substr(0,2) + num.substr(3,2) + num.substr(6);
	
	for(int i=0; i < 5; i++)
	{
		if(con[i] <= con[i+1])
		{
			isPizza = false;
			break;
		}
	}
	
	if(isTaxi) return 0;
	
	if(isPizza) return 1;

	return 2;
}

int main()
{
	int n;
	cin>>n;
	
	vector<Data> info;
	
	for(int i=0; i < n; i++)
	{
		int m;
		string str;
		cin>>m; cin>>str;

		Data cur(str);
		info.push_back(cur);
		for(int j=0; j < m; j++)
		{
			string phoneNum;
			cin>>phoneNum;
			int res = getType(phoneNum);
			if(res == 0) info[i].taxi++;
			if(res == 1) info[i].pizza++;
			if(res == 2) info[i].girl++;
            
		}
	}
	
	string taxiGuy = "";
	string pizzaGuy = "";
	string girlGuy = "";
	
	int taxiBest = 0;
	int pizzaBest = 0;
	int girlBest = 0;
	
	for(int i=0; i < n; i++)
	{
        taxiBest = max(taxiBest, info[i].taxi);
        pizzaBest = max(pizzaBest, info[i].pizza);
        girlBest = max(girlBest, info[i].girl);
	}
    
    for(int i=0; i < n; i++)
    {
        if(info[i].taxi == taxiBest) taxiGuy += ", " + info[i].name;
            
        if(info[i].pizza == pizzaBest) pizzaGuy += ", " + info[i].name;
        
        if(info[i].girl == girlBest) girlGuy += ", " + info[i].name;
    }
    
	taxiGuy = taxiGuy.substr(2);
	pizzaGuy = pizzaGuy.substr(2);
	girlGuy = girlGuy.substr(2);
	
	taxiGuy +=".";
	pizzaGuy +=".";
	girlGuy +=".";


	cout<<"If you want to call a taxi, you should call: "<<taxiGuy<<endl;
	cout<<"If you want to order a pizza, you should call: "<<pizzaGuy<<endl;
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: "<<girlGuy<<endl;
	
	
    return 0;
}