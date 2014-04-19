#include <iostream>
#include <algorithm>
using namespace std;

#define MAXV 55
int adj[MAXV][MAXV];
int deg[MAXV];
int path[100000];
int path_idx;
int nV, nE, maxColor;

void euler_cycle(int cur) {
	for(int i=1; i <= maxColor; i++) {
		if(adj[cur][i]) {
			adj[cur][i]--;
			adj[i][cur]--;
			euler_cycle(i);
			path[path_idx++]=cur;
		}
	}
}

int main() {
	string no = "some beads may be lost";
	int T;
	cin>>T;
	int idx = 0;
	while(++idx <= T) {
		if(idx != 1) cout<<endl;
		cin>>nE;
		// initialize
		for(int i=0; i < MAXV; i++)
			for(int j=i; j < MAXV; j++)
				adj[i][j] = adj[j][i] = 0;
	
		for(int i=0; i < MAXV; i++)
			deg[i] = 0;

		nV = nE;
		maxColor = -1;
		int x,y;
		while(nE--) {
			cin>>x>>y;
			adj[x][y]++;
			adj[y][x]++;
			deg[x]++; deg[y]++;
			maxColor = max(maxColor, max(x,y));
		}

		bool isPossible = true;
		for(int i=1; i <= maxColor; i++)
			if(deg[i] % 2 != 0) {
				isPossible = false;
				break;
			}
		
		if(isPossible) {
			int st = 1;
			while(st <= maxColor && deg[st] == 0)
				st++;
			path_idx = 0;
			if(st <= maxColor) euler_cycle(st);
			if(path_idx != nV) isPossible = false;
		}

		cout<<"Case #"<<idx<<endl;
		if(isPossible) {
			path[path_idx] = path[0];
			for(int i=0; i < path_idx; i++)
				cout<<path[i]<<" "<<path[i+1]<<endl;
		} else {
			cout<<no<<endl;
		}
	}
	return 0;
}