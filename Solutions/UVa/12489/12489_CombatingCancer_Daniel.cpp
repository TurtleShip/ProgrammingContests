#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <map>
using namespace std;
int N;

// tree is stored as adjacency list. For each node there is a vector<int>
//  with its neighbors.
vector<int> tree1[10010], tree2[10010];

// two last vertices on the BFS (first == last, second == second-to-last)
pair<int,int> findRoots(vector<int>* tree) {
	pair<int, int> roots;
	vector<int> degree(N);
	queue<int> Q;
	for (int i = 0; i < N; ++i) {
		degree[i] = tree[i].size();
		if (degree[i] == 1) Q.push(i);
	}
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		roots.second = roots.first;
		roots.first = v;
		for (int i = 0; i < tree[v].size(); ++i) {
			degree[tree[v][i]]--;
			if (degree[tree[v][i]] == 1) Q.push(tree[v][i]);
		}
	}
	return roots;
}
// Children is the "set" for each node as I explained in the board
vector<int> children[10010];
// The map of types
map<vector<int>, int> types;
// The type of each node (basically, type[i] == types[children[i]])
int type[10010];

// Finds the type of node R in the tree.
int returnType(vector<int>* tree, int R) {
	if (type[R] != -1) return type[R];
	// If the node is "open" we mark it with -2
	type[R] = -2;
	for (int i = 0; i < tree[R].size(); ++i) {
		int t = returnType(tree, tree[R][i]);
		// If t == -2 it means that tree[R][i] is the parent of R
		if (t != -2) children[R].push_back(t);
	}
	sort(children[R].begin(), children[R].end());
	// The following line is a trick to try to insert a new pair (key, value)
	//  to a map. If the key is new, it returns the new value. Otherwise it 
	//  returns the old value. Check cppreference.com (or cplusplus.com) for
	//  the method insert of a map.
	return type[R] = types.insert(make_pair(children[R], types.size())).first->second;
}

bool iso() {
	pair<int,int> R1 = findRoots(tree1);
	pair<int,int> R2 = findRoots(tree2);
	types.clear();
	fill_n(children, N, vector<int>());
	fill_n(type, N, -1);
	int t1 = returnType(tree1, R1.first);
	fill_n(children, N, vector<int>());
	fill_n(type, N, -1);
	int t21 = returnType(tree2, R2.first);
	fill_n(children, N, vector<int>());
	fill_n(type, N, -1);
	int t22 = returnType(tree2, R2.second);
	return t1 == t21 || t1 == t22; 
}

int main() {
	while (scanf("%d", &N) != EOF) {
		fill_n(tree1, N, vector<int>());
		fill_n(tree2, N, vector<int>());
		for (int i = 0; i < N-1; ++i) {
			int a,b;
			scanf("%d %d", &a, &b); a--; b--;
			tree1[a].push_back(b); tree1[b].push_back(a);
		}
		for (int i = 0; i < N-1; ++i) {
			int a,b;
			scanf("%d %d", &a, &b); a--; b--;
			tree2[a].push_back(b); tree2[b].push_back(a);
		}

		if (iso()) printf("S\n");
		else printf("N\n");
	}
	return 0;
}
