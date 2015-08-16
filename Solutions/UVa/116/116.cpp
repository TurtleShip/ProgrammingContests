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

const int maxR = 20;
const int maxC = 110;
pair<int, vector<int> > dp[maxR][maxC];
int cost[maxR][maxC];


int main()
{
	int R,C;
	
	while(cin>>R>>C) {
		for(int i=0; i < R; i++)
			for(int j=0; j < C; j++)
				cin>>cost[i][j];

		for(int i=0; i < R; i++) {
			dp[i][0].first = cost[i][0];
			dp[i][0].second.clear();
			dp[i][0].second.push_back(i);
		}

		for(int c=1; c < C; c++) {

			for(int r=0; r < R; r++) {
				
				// int up = dp[(r == 0) ? (R-1) : (r-1)][c-1].first;
				// int mid = dp[r][c-1].first;
				// int low = dp[(r == R-1) ? 0 : (r+1)][c-1].first;

				pair< int, vector<int> > one = dp[(r+R-1)%R][c-1];
				pair< int, vector<int> > two = dp[r][c-1];
				pair< int , vector<int> > three = dp[(r+1)%R][c-1];

				dp[r][c] = min(min(one, two), three);
				dp[r][c].first += cost[r][c];
				dp[r][c].second.push_back(r);
			}
		}

		pair<int, vector<int> > res = dp[0][C-1];
		
		for (int i = 1; i < R; i++) res = min(res, dp[i][C-1]);

		cout<<(res.second[0] + 1);
		for(int i=1; i < C; i++)
			cout<<" "<<(res.second[i] + 1);
		cout<<endl;
		cout<<res.first<<endl;
	}

	
    return 0;

}