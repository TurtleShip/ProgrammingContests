#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXV 110

int cap[MAXV][MAXV]; // cap[i][j] = capacity of the road from node i to node j
int flow[MAXV]; // maximum flow you can push
int edges[MAXV][MAXV];
int degree[MAXV];

int main() {
	int N, R, S, D, T, idx = 1;

	while(cin>>N>>R) {
		if(N == 0 && R == 0) break;

		// initialize
		for(int i=1; i <= N; i++)
			for(int j=1; j <= N; j++)
				cap[i][j] = -1;
			
		
		for(int i=1; i <= N; i++) {
			degree[i] = 0;
			flow[i] = 0;
		}
		
		int x,y,c, maxFlow = 0;

		while(R--) {
			cin>>x>>y>>c;
			cap[x][y] = cap[y][x] = c;
			edges[x][degree[x]++] = y;
			edges[y][degree[y]++] = x;
			maxFlow = max(maxFlow, c);
		}

		cin>>S>>D>>T;
		queue<int> Q;
		Q.push(S);
		flow[S] = maxFlow;

		while(!Q.empty()) {
			int curNode = Q.front(); Q.pop();
			int curFlow = flow[curNode];

			for(int i=0; i < degree[curNode]; i++) {
				int nextNode = edges[curNode][i];
				int nextFlow = min(curFlow, cap[curNode][nextNode]);

				if(flow[nextNode] < nextFlow) {
					flow[nextNode] = nextFlow;
					Q.push(nextNode);
				}
			}
		}

		maxFlow = flow[D];
		maxFlow--; // The guide needs to always ride the bus
		int res = T / maxFlow;
		if( (T % maxFlow) != 0 ) res++;
		cout<<"Scenario #"<<idx++<<endl;
		cout<<"Minimum Number of Trips = "<<res<<endl;
		cout<<endl;
	}


	
	return 0;
}