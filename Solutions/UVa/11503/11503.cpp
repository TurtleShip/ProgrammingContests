#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

class IdGenerator {
	private:
		int sz;
		map<string, int> M;

	public:
		IdGenerator() {
			sz = 0;
		}

		int getId(string key) {
			if(M.count(key) == 0) {
				M[key] = sz++;
			}
			return M[key];
		}
};

#include <iostream>
#include <vector>
using namespace std;


// Shameless copy from Competitive Programming 3
class UnionFind {                                           
	private:
		set<int> members;
		vector<int> p, rank, setSize;
		
		void fitElement(int x) {
			if(p.size() <= x) {
				p.resize(x + 10, -1);
				setSize.resize(x+10, -1);
				rank.resize(x+10, -1);
			}
		}
	public:

		UnionFind() {
			p.assign(1000, -1); // guessing the size
			setSize.assign(1000, -1);
			rank.assign(1000, -1);
		}


		int findSet(int i) {
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}

		bool isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}

		void unionSet(int i, int j) { 
			if(members.count(i) == 0) {
				members.insert(i);
				fitElement(i);
				p[i] = i;
				setSize[i] = 1;
			}
			if(members.count(j) == 0) {
				members.insert(j);
				fitElement(j);
				p[j] = j;
				setSize[j] = 1;
			}

			if (!isSameSet(i, j)) {
				int x = findSet(i);
				int y = findSet(j);

				// rank is used to keep the tree short
				if (rank[x] > rank[y]) { 
					p[y] = x;
					setSize[x] += setSize[y];
				} else {
					p[x] = y;
					setSize[y] += setSize[x];
					if (rank[x] == rank[y]) rank[y]++;
				} 
			} 
		}
		
		int sizeOfSet(int i) { 
			return setSize[findSet(i)]; 
		}
};


int main() {
	int T, F;
	string xName, yName;
	cin>>T;
	while(T--) {
		cin>>F;
		IdGenerator gen;
		UnionFind uf;
		while(F--) {
			cin>>xName>>yName;
			int x = gen.getId(xName);
			int y = gen.getId(yName);
			uf.unionSet(x,y);
			cout<<uf.sizeOfSet(x)<<endl;
		}
	}

	return 0;
}
