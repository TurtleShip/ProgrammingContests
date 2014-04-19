#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
using namespace std;

#define pb(x) push_back(x)

void erase_all_whitespace(string& str) {
	str.erase( remove_if(str.begin(), str.end(), ::isspace), str.end() );
}

int main() {
	int N, T;
	bool isFirst = true;
	bool isFirstBig;
	string str, mut;
	vector<string> ori; // original strings
	vector<string> rep; // representations
	vector< pair<string, string> > res; // result

	cin>>T;
	getline(cin,str);
	getline(cin,str);
		
	while(T--) {
		
		if(isFirst) isFirst = false;
		else cout<<endl;
		
		ori.clear();
		rep.clear();
		res.clear();

		getline(cin,str);
		
		while(str != "") {
			mut = str;
			erase_all_whitespace(mut);
			sort(mut.begin(), mut.end());
			ori.pb(str);
			rep.pb(mut);
			getline(cin,str);
		}
		
		N = ori.size();

		for(int i=0; i < N; i++) {
			for(int j=i+1; j < N; j++) {
				if(rep[i] == rep[j]) {
					if(ori[i] < ori[j]) res.pb( make_pair(ori[i], ori[j]) );
					else res.pb( make_pair(ori[j], ori[i]) );
				}
			}
		}
		sort(res.begin(), res.end());

		for(int i=0; i < res.size(); i++) {
			cout<<res[i].first<<" = "<<res[i].second<<endl;
		}
	}


	return 0;
}