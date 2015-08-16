#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class UnionFind {
	private:
		vector<int> root;

	public:
		UnionFind(int N) {
			root.assign(N+1, 0);
			for(int i=1; i <= N; i++)
				root[i] = i;
		}

		int findSet(int x) {
			return root[x] == x ? x : root[x] = findSet(root[x]);
		}

		bool isInSameSet(int x, int y) {
			return findSet(x) == findSet(y);
		}

		void unionSet(int x, int y) {
			if(!isInSameSet(x,y)) {
				int oldRoot = findSet(min(x,y));
				int newRoot = findSet(max(x,y));
				for(int i=1; i < root.size(); i++)
					if(root[i] == oldRoot)
						root[i] = newRoot;
			}
		}

};

int main() {
	// I hate questions where each dataset is delimited by empty line.
	// So fuck you, author.
	string line;
	int T;
	getline(cin, line);
	sscanf(line.c_str(), "%d", &T);
	getline(cin, line);

	for(int cid=1; cid <= T; cid++) {
		if(cid > 1) cout<<endl;
		int N;
		char cmd;
		int x, y;

		getline(cin,line);
		sscanf(line.c_str(), "%d", &N);
		UnionFind uf(N);
		int yes = 0;
		int no = 0;
		while(getline(cin, line) && line.size() != 0) {
			sscanf(line.c_str(), "%c %d %d", &cmd, &x, &y);
			if(cmd == 'c') uf.unionSet(x,y);
			else {
				if(uf.isInSameSet(x,y)) yes++;
				else no++;
			}
		}
		cout<<yes<<","<<no<<endl;
	}
	return 0;
}