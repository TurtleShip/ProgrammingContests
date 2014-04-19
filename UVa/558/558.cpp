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

const int maxN = 1010;
const int INF = 99999;
int edge[maxN][maxN];
vector<int> out[maxN];
int initCost[maxN];


typedef struct info {
	int node;
	int cost;
	set<int> visitList;
} info;

int main()
{
	int C, N, M, x, y, t;
	cin>>C;

	while(C--) {
		cin>>N>>M;

		// initialize
		for(int i=0; i < N; i++)
			out[i].clear();

		while(M--) {

			cin>>x>>y>>t;

			edge[x][y] = t;
			out[x].push_back(y);
		}

		info st;
		st.node = 0;
		st.cost = 0;

		stack<info> S;
		S.push(st);

		bool hasNeg = false;

		while(!S.empty()) {
			info cur = S.top(); S.pop();
			// cout<<"node : "<<cur.node<<" , cost : "<<cur.cost<<endl;

			if(cur.visitList.count(cur.node) != 0) {
				if(cur.cost < initCost[cur.node]) {
					hasNeg = true;
					break;
				}

				continue;
			}

			initCost[cur.node] = cur.cost;

			for(int i=0; i < out[cur.node].size(); i++) {
				info next;
				next.node = out[cur.node][i];
				next.visitList = cur.visitList;
				next.visitList.insert(cur.node);
				next.cost = cur.cost + edge[cur.node][next.node];

				S.push(next);
			}
		}

		if(hasNeg) cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;


	}

	
    return 0;

}