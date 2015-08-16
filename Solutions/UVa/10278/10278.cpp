#include <iostream>
#include <sstream>
#include <queue>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;

#define MAXV 550
#define MAXE 30
#define INF numeric_limits<int>::max()

typedef struct edge{
	int v; // the other end of edge
	int w; // edge weight

	edge() {v = -1; w = -1;};
	edge(int _v, int _w) { v = _v; w = _w; };
}edge;
edge edges[MAXV][MAXE];
int deg[MAXV];
int dist[MAXV];
int curDist[MAXV];
//dist[i] = distance from node i to the nearest fire station
int main () {
	int T;
	cin>>T;
	int F,V;
	bool isFirst = true;
	while(T--) {
		if(!isFirst) cout<<endl;
		else isFirst = false;

		cin>>F>>V;

		// initialize
		for(int i=1; i <= V; i++) {
			deg[i] = 0;
			dist[i] = INF;
		}
		queue<int> Q;
		int f;
		while(F--) {
			cin>>f;
			dist[f] = 0;
			Q.push(f);
		}

		int x,y,c;
		string tmp;
		stringstream ss;
		
		getline(cin,tmp);
		while(getline(cin,tmp)) {
			if(tmp.size() == 0) break;		
			ss<<tmp;
			ss>>x>>y>>c;
			ss.flush();ss.clear();
			edges[x][deg[x]++] = edge(y,c);
			edges[y][deg[y]++] = edge(x,c);
		}

		// calculate the initial maximum distance
		int maxDist = 0;
		while(!Q.empty()) {

			int cur = Q.front(); Q.pop();
			int curCost = dist[cur];
			for(int i=0; i < deg[cur]; i++) {
				int next = edges[cur][i].v;
				int nextCost = curCost + edges[cur][i].w;
				maxDist = max(maxDist, nextCost);
				if(nextCost < dist[next]) {
					dist[next] = nextCost;
					Q.push(next);
				}
			}
		}
		int res = 1;
		// run bfs on each of them
		for(int i=1; i <= V; i++) {
			if(dist[i] == 0) continue;
			
			for(int j=1; j <= V; j++)
				curDist[j] = dist[j];

			curDist[i] = 0;
			Q.push(i);
			
			while(!Q.empty()) {
				int cur = Q.front(); Q.pop();
				int curCost = curDist[cur];

				for(int i=0; i < deg[cur]; i++) {
					int next = edges[cur][i].v;
					int nextCost = curCost + edges[cur][i].w;
					if(nextCost < curDist[next]) {
						curDist[next] = nextCost;
						Q.push(next);
					}

				}
			}

			int curMax = 0;
			for(int j=1; j <= V; j++)
				curMax = max(curMax, curDist[j]);
			if(curMax < maxDist) {
				maxDist = curMax;
				res = i;
			}
		}

		cout<<res<<endl;
			
			
	}
	return 0;
}