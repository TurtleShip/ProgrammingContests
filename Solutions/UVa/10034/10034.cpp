#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAXV 110
#define INF numeric_limits<int>::max()

typedef struct edge {
	int v;
	double w;
	edge() {v = -1, w = -1.0;};
	edge(int _v, double _w) {v = _v; w = _w;};
} edge;

edge edges[MAXV][MAXV];
int deg[MAXV];
int nV;
bool inTree[MAXV];
double dist[MAXV];
pair<double,double> dot[MAXV];

int main() {
	int T;
	cin>>T;
	double x,y, len;
	bool isFirst = true;

	// print only 2 decimal places
	cout<<setprecision(2)<<fixed;
	while(T--) {
		if(!isFirst) cout<<endl;
		else isFirst = false;

		cin>>nV;
		for(int i=0; i < nV; i++) {
			deg[i] = 0;
			inTree[i] = false;
			dist[i] = INF;
		}

		for(int i=0; i < nV; i++) {
			cin>>x>>y;
			dot[i] = make_pair(x,y);
		}

		// make edges
		for(int i=0; i < nV; i++)
			for(int j=i; j < nV; j++) {
				x = abs(dot[i].first - dot[j].first);
				y = abs(dot[i].second - dot[j].second);
				len = sqrt(x*x + y*y);
				edges[i][deg[i]++] = edge(j,len);
				edges[j][deg[j]++] = edge(i,len);
			}

		// find MST using Prim's algorithm
		double res = 0.0;
		int cur, next, start = 0;
		double weight;
		double minDist = 0.0;

		dist[start] = 0.0;
		cur = start;
		while(!inTree[cur]) {
			inTree[cur] = true;
			res += minDist;
			for(int i=0; i < deg[cur]; i++) {
				next =edges[cur][i].v;
				weight = edges[cur][i].w;
				if( dist[next] > weight && !inTree[next])
					dist[next] = weight;
			}
			cur = start;
			minDist = INF;
			for(int i=0; i < nV; i++)
				if(!inTree[i] && minDist > dist[i] ) {
					minDist = dist[i];
					cur = i;
				}
		}

	
		cout<<res<<endl;
	}

	return 0;
}
