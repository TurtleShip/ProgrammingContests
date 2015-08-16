#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define all(v) (v).begin(), (v).end()
class IdGenerator {
	private: 
		int sz;
		map<char, int> ids;
	public:
		IdGenerator() {
			sz = 0;
		}
		int getId(char ch) {
			if(ids.count(ch) == 0) {
				ids[ch] = sz++;
			}
			return ids[ch];
		}
};

int main() {
	int N, C;
	string line;
	while(cin>>N>>C>>line) {
		vector<bool> isAwake(N, false);
		vector< vector<bool> > isLinked(N, vector<bool>(N, false));
		IdGenerator idGen;
		for(int i=0; i < line.size(); i++) {
			int id = idGen.getId(line[i]);
			isAwake[id] = true;
		}
		for(int i=0; i < C; i++) {
			cin>>line;
			int x = idGen.getId(line[0]);
			int y = idGen.getId(line[1]);
			isLinked[x][y] = isLinked[y][x] = true;
		}

		// see how long it would take	
		int wakenAreas = 3;
		int years = 0;
		while(wakenAreas < N) {
			bool canWake = false;
			vector<bool> prevAwake(all(isAwake));

			for(int i=0; i < N; i++) {
				if(prevAwake[i]) continue;
				int ct = 0;
				for(int j=0; j < N; j++)
					if(isLinked[i][j] && prevAwake[j]) ct++;
				if(ct >= 3) {
					isAwake[i] = true;
					wakenAreas++;
					canWake = true;
				}
			}
			years++;
			if(!canWake) break;			
		}

		if(wakenAreas == N) cout<<"WAKE UP IN, "<<years<<", YEARS"<<endl;
		else cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
	}

	return 0;
}
