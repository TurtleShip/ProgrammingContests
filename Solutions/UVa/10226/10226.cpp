#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) (v).begin(), (v).end()

int main() {
	int T;
	cin>>T;
	bool isFirst = true;
	string str;

	// Ignore first blank line
	getline(cin,str);
	getline(cin,str);
		
	while(T--) {
		// Print a blank line between 2 consecutive data sets.
		if(isFirst) isFirst = false;
		else cout<<endl;
		map<string, int> dic;
		int total = 0;
		while(getline(cin,str) && str != "") {
			if(dic.count(str) == 0) dic[str] = 1;
			else dic[str]++;
			total++;
		}

		vector< pair<string, double> > res;
		for(auto kv : dic) {
			res.pb( mp(kv.first, 100.0 * double(kv.second)/double(total)) );
		}
		sort( all(res) );
		for(auto kv : res) {
			cout<<kv.first<<" "<<fixed<<setprecision(4)<<kv.second<<endl;
		}
	}


}