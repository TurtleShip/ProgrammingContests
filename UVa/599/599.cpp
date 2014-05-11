#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pb(x) push_back(x)
#define NONE -1

const int maxVert = 26;

int main() {
	int N;
	string str;
	cin>>N;

	while(N--) {
		vector< vector<int> > edges(maxVert);
		vector<int> parent(maxVert, NONE);
		vector<bool> isInForest(maxVert, false);

		while(cin>>str && str[0] != '*') {
			int x = int(str[1] - 'A');
			int y = int(str[3] - 'A');
			edges[x].pb(y);
			edges[y].pb(x);
		}

		cin>>str;
		for(int i=0; i < str.size(); i+=2) {
			int x = int(str[i] - 'A');
			isInForest[x] = true;
		}

		int acorns = 0;
		int trees = 0;
		for(int root=0; root < maxVert; root++) {
			if(isInForest[root]) {
				if(edges[root].size() == 0) {
					acorns++;
				} else if(parent[root] == NONE) {
					// check that this tree doesn't contain cycles
					parent[root] = root;
					queue<int> Q;
					Q.push(root);
					bool foundCycle = false;
					// We keep filling other nodes whose parents are NONE
					// even after find a cycle so that we can minimize
					// the number of times we look for cycles.
					while(!Q.empty()) {
						int cur = Q.front(); Q.pop();
						for(int x : edges[cur]) {
							if(parent[x] == NONE) {
								parent[x] = root;
								Q.push(x);
							} else if(parent[x] != root) {
								foundCycle = true;
							}
						}
					}
					if(!foundCycle) trees++;
				}
			}
		}
		cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s)."<<endl;
	}


	return 0;
}