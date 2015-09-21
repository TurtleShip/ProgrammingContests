#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int p, t, N, M, s, u, v, c, T;

vector< pair<int,int> > adj[10010]; //adj[i].first = cost, adj[i].second = dst
vector <pair<int,int> > rv_adj[10010];
int dist[10010];
int rv_dist[10010];
vector<int> froms;
vector<int> tos;
vector<int> costs;
int INF = 1000000;
int res, numEdges;
// edge info


int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d %d %d", &N, &M, &s, &t, &p);
		
		numEdges = 0;
		for(int i=1; i <= N; i++)
			adj[i].clear();
		for(int i=1; i <= N; i++)
			rv_adj[i].clear();
		froms.clear();
		tos.clear();
		costs.clear();

		while(M--) {
			scanf("%d %d %d", &u, &v, &c);
			adj[u].push_back(make_pair(c, v));
			rv_adj[v].push_back(make_pair(c, u));
			froms.push_back(u);
			tos.push_back(v);
			costs.push_back(c);
		}
		for(int i=1; i <= N; i++)
			dist[i] = INF;
		for(int i=1; i <= N; i++)
			rv_dist[i] = INF;

		priority_queue< pair<int,int> > pq;
		pq.push(make_pair(0, s));
		dist[s] = 0;

		while(!pq.empty()) {
			pair<int,int> edge = pq.top();
			pq.pop();
			int cur_node = edge.second;
			for(pair<int,int> next_edge : adj[cur_node]) {
				int next_cost = dist[cur_node] + next_edge.first;
				if(next_cost < dist[next_edge.second]) {
					dist[next_edge.second] = next_cost;
					pq.push(make_pair(next_cost, next_edge.second));
				}
			}
		}

		pq.push(make_pair(0, t));
		rv_dist[t] = 0;
		while(!pq.empty()) {
			pair<int,int> edge = pq.top();
			pq.pop();
			int cur_node = edge.second;
			for(pair<int,int> next_edge : rv_adj[cur_node]) {
				int next_cost = rv_dist[cur_node] + next_edge.first;
				if(next_cost < rv_dist[next_edge.second]) {
					rv_dist[next_edge.second] = next_cost;
					pq.push(make_pair(next_cost, next_edge.second));
				}
			}
		}

		int res = -1;
		for(int i=0; i < froms.size(); i++) {
			int from = froms[i];
			int to = tos[i];
			if((dist[from] + costs[i] + rv_dist[to]) <= p && res < costs[i])
				res = costs[i];
		}
		
		printf("%d\n", res);
	}

	return 0;
}
