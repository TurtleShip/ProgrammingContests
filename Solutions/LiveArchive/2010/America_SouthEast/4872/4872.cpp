#include <iostream>
#include <cmath>
#include <limits>
#include <cstdio>
using namespace std;

#define MAXV 1010 // maximum number of vertices
#define MAXDEGREE 1010 // maximum vertex outdegree
#define INF numeric_limits<double>::max()
typedef struct edge {
	int v; // the other end of edge
	double w; // edge weight

	edge() {v = -1; w = -1.0;};
	edge(int _v, double _w) { v = _v; w = _w; };
} edge;

edge edges[MAXV][MAXDEGREE]; // edge[x][i] = y : Node x's (i)th edge is conneceted to node y
int deg[MAXV]; //outdegree of each vertex
int nV; // number of vertices
bool inTree[MAXV];
double X[MAXV];
double Y[MAXV];
double dist[MAXV]; // distance from the currently constructed tree
int parent[MAXV]; // path info
double res;

// Prim's Algorithm to find MST (Minimum Spanning Tree)
void prim(int start) {
	int cur, next;
	double weight;
	double minDist;

	for(int i=0; i < nV; i++) {
		inTree[i] = false;
		dist[i] = INF;
		parent[i] = -1;
	}

	dist[start] = 0.0;
	cur = start;
	while(!inTree[cur]) {
		inTree[cur] = true;
		
		// cout<<cur<<endl;

		for(int i=0; i < deg[cur]; i++) {
			next = edges[cur][i].v;
			weight = edges[cur][i].w;
			if( dist[next] > weight && !inTree[next] ) {
				dist[next] = weight;
				// parent[next] = cur;
			}
		}
		cur = start;
		minDist = INF;
		for(int i=0; i < nV; i++)
			if(!inTree[i] && minDist > dist[i] ) {
				minDist = dist[i];
				// res += minDist;
				cur = i;
			}
		res += dist[cur];
	}
}

int main() {
	while(cin>>nV && nV) {
		double x,y;
		for(int i=0; i < nV; i++) {
			cin>>X[i]>>Y[i];
		}
		for(int i=0; i < nV; i++)
			deg[i] = 0;

		// construct edges
		for(int i=0; i < nV; i++) {
			for(int j=i+1; j < nV; j++) {
				double dx = X[j] - X[i];
				double dy = Y[j] - Y[i];
				double cur = sqrt(dx*dx + dy*dy);
				edges[i][deg[i]++] = edge(j,cur);
				edges[j][deg[j]++] = edge(i,cur);
			}
		}

		res = 0.0;
		prim(0);
		// for(int i=0; i < nV; i++)
		// 	res += dist[i];
		printf("%.2f\n", res);


	}
	return 0;
}