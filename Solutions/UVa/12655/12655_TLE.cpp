#include <iostream>
#include <vector>
using namespace std;

#define MAXV 20010

struct edge{
	int other; // other end of the edge
	int cap;
	edge(int o, int w) {
		other = o;
		cap = w;
	}
};
typedef struct edge edge;

bool inTree[MAXV];
int flow[MAXV];

vector< edge > edges[MAXV];

int main() {
	int N, M, S;
	int A, B, W;
	int start, goal;

	while(cin>>N>>M>>S) {
		
		// initialize
		for(int i=1; i <= N; i++)
			edges[i].clear();


		while(M--) {
			cin>>A>>B>>W;
			edges[A].push_back(edge(B, W));
			edges[B].push_back(edge(A, W));
		}

		while(S--) {
			cin>>start>>goal;

			// initialize
			for(int i=1; i <= N; i++) {
				inTree[i] = false;
				flow[i] = -1;
			}

			flow[start] = 100010;
			int curNode = start;
			
			// Modified Dijkstra algorithm

			while(!inTree[curNode] && !inTree[goal]) {
				inTree[curNode] = true;
				for(int i=0; i < edges[curNode].size(); i++) {
					int nextNode = edges[curNode][i].other;
					int nextFlow = min(edges[curNode][i].cap, flow[curNode]);
					if( flow[nextNode] < nextFlow )
						flow[nextNode] = nextFlow;
				}

				curNode = start;
				int maxFlow = -1;
				for(int i=1; i <= N; i++)
					if(!inTree[i] && maxFlow < flow[i]) {
						curNode = i;
						maxFlow = flow[i];
					}
			}
			cout<<flow[goal]<<endl;
		}
	}

	return 0;
}
