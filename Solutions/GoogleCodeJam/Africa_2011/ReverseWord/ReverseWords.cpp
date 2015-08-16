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
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;

int main()
{
	int N;
	cin>>N;

	cin.ignore();
	for(int i=0; i < N; i++)
	{
		string str;
		getline(cin, str);
		
		stringstream ss;
		ss<<str;
		string word;
		string ans = "";
		while(ss>>word)
			ans = word + " " + ans;
		
		ans.erase(ans.size() - 1);
		
		
		cout<<"Case #"<<(i+1)<<": "<<ans<<endl;
	}
    return 0;
}