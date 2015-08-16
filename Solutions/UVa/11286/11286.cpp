#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
	int N;
	while(cin>>N && N != 0) {
		map<string, int> dic;
		int best = 0;
		while(N--) {
			vector<string> V(5);
			for(int i=0; i < 5; i++) {
				cin>>V[i];
			}
			sort( all(V) );
			string rep = "";
			for(auto str : V) {
				rep += str;
			}
			if(dic.count(rep) == 0) dic[rep] = 1;
			else dic[rep]++;
			best = max(best, dic[rep]);
		}
		int res = 0;
		for(auto kv : dic)
			if(kv.second == best) res += best;
		cout<<res<<endl;
	}
	return 0;
}