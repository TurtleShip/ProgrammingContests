#include <vector>
#include <iostream>
using namespace std;

#define pb(x) push_back(x)

const int maxN = 100000;
vector<int> neighbors[maxN + 10];
vector<int> goal(maxN + 10);

void flip(vector<int>& config, int parent, int idx, bool shouldFlip, int& res, vector<int>& V) {
	if(shouldFlip) {
		if(config[idx] == goal[idx]) {
			// We shouldn't  flip this one. So flip one more time.
			res++;
			V.pb(idx);

			return;
		}
		config[idx] ^= 1;
	}
	for(int i=0; i < neighbors[idx].size(); i++) {
		if(parent == neighbors[idx][i]) continue;
		flip(config, idx, neighbors[idx][i], !shouldFlip, res, V);
	}
}

void solve(vector<int>& config, int parent, int idx, int& res, vector<int>& V) {
	if(config[idx] != goal[idx]) {
		res++;
		V.pb(idx);
		flip(config, parent, idx, true, res, V);
	}

	for(int i=0; i < neighbors[idx].size(); i++) {
		if(parent == neighbors[idx][i]) continue;
		solve(config, idx, neighbors[idx][i], res, V);
	}
}
int main() {
	int N;
	cin>>N;

	int u,v;
	for(int i=0; i < N-1; i++) {
		cin>>u>>v;
		neighbors[u].pb(v);
		neighbors[v].pb(u);
	}

	vector<int> init(N+10);

	for(int i=1; i <= N; i++)
		cin>>init[i];

	for(int i=1; i <= N; i++)
		cin>>goal[i];

	int res = 0;
	vector<int> V;
	solve(init, 1, 1, res, V);
	cout<<res<<endl;
	for(int i=0; i < V.size(); i++)
		cout<<V[i]<<endl;

	return 0;
}
