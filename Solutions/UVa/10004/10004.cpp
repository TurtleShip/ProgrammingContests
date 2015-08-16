#include <iostream>
#include <queue>
using namespace std;

#define MAXV 210

typedef struct {
	int edges[MAXV][MAXV];
	int degree[MAXV];
	int num_vert;
	int num_edge;
} graph;

void insert_edge(graph* g, int x, int y, bool directed) {
	g->edges[x][g->degree[x]++] = y;
	if(directed) g->num_edge++;
	else insert_edge(g,y,x,true);
}

int color[MAXV];

int main() {
	int N; // number of different nodes
	int E; // number of edges
	bool isDirected = false; // not a directed graph
	bool isBicolorable = true;
	string yes = "BICOLORABLE.";
	string no = "NOT BICOLORABLE.";

	while(cin>>N>>E) {
		if(N==0) break;
		graph g;
		g.num_vert = N;
		g.num_edge = E;
		for(int i=0; i < N; i++)
			g.degree[i] = 0;

		// get edge info
		int tmp = E;
		int x,y;
		while(tmp--) {
			cin>>x>>y;
			insert_edge(&g,x,y,isDirected);
		}

		// 0 = no color, 1 = color #1, 2 = color #2
		for(int i=0; i < N; i++)
			color[i] = 0;

		// perform BFS
		isBicolorable = true;
		queue<int> Q;
		
		Q.push(0);
		color[0] = 1;

		while(!Q.empty()) {
			int cur = Q.front(); Q.pop();
			int curColor = color[cur];
			int nextColor = (curColor == 1) ? 2 : 1;

			for(int i=0; i < g.degree[cur]; i++) {
				int next = g.edges[cur][i];
				if(color[next] == 0) {
					color[next] = nextColor;
					Q.push(next);
				} else if(color[next] == curColor) {
					isBicolorable = false;
					break;
				}
			}

			if(!isBicolorable) break;
		}

		if(isBicolorable) cout<<yes<<endl;
		else cout<<no<<endl;

	}

	return 0;
}