#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define pb(x) push_back(x)

typedef long long LL;

vector<int> neighbor[1010];
int treeSize[1010];
int INF = 1010;

int getSize(int curNode, int parentNode) {
	treeSize[curNode] = 1; // curNode is a part of this tree
	for(int i=0; i < neighbor[curNode].size(); i++) {
		int child = neighbor[curNode][i];
		if(child != parentNode) {
			treeSize[curNode] += getSize(child, curNode);
		}
	}
	return treeSize[curNode];
}

void initSize(int rootNode) {
	getSize(rootNode, rootNode);
}

/*
	Returns number of nodes to delete to keep
	node "curNode" whose parent node is "parentNode"
*/
int solve(int curNode, int parentNode) {
	vector<int> children;
	for(int i=0; i < neighbor[curNode].size(); i++) {
		int child = neighbor[curNode][i];
		if(child != parentNode) {
			children.push_back(child);
		}
	}
	int numNodesToDelete = INF;
	int N = children.size();
	if(N == 0) {
		numNodesToDelete = 0;
	} else if(N == 1) {
		numNodesToDelete = treeSize[children[0]];
	} else if(N == 2) {
		numNodesToDelete = solve(children[0], curNode) + solve(children[1], curNode);
	} else {
		/*
			We keep 2, and discard all others.
			Try all possible combinations.
			The worst case is
			(1000 * 999) / 2 , which isn't that big.
		*/
		for(int i=0; i < N; i++) {
			int firstChild = children[i];
			for(int j=i+1; j < N; j++) {
				
				int secondChild = children[j];
				int curResult = 0;
				
				// we delete all children except for first and second
				for(int k=0; k < N; k++) {
					if(k == i || k == j) continue;
					curResult += treeSize[children[k]];
				}
				curResult += solve(firstChild, curNode) + solve(secondChild, curNode);
				numNodesToDelete = min(numNodesToDelete, curResult);
			}
		}
	}
	return numNodesToDelete;
}

int main() {
	int T, N;
	int x, y;

	cin>>T;
	for(int cid=1; cid <= T; cid++) {
		cin>>N;

		for(int i=1; i <= N; i++) {
			neighbor[i].clear();
		}

		for(int i=0; i < N-1; i++) {
			cin>>x>>y;
			neighbor[x].pb(y);
			neighbor[y].pb(x);
		}

		int res = INF;

		// try all nodes
		for(int root = 1; root <= N; root++) {
			initSize(root);
			res = min(res, solve(root, root));
		}

		cout<<"Case #"<<cid<<": ";
		cout<<res<<endl;



	}
    
}
