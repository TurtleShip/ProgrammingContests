#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

#define pb(x) push_back(x)

int main() {
	string in;
	string mut;
	vector<string> dic;
	vector<string> trans;
	int ct, N;

	while(cin>>in && in != "#") {
		dic.pb(in);
		transform(in.begin(), in.end(), in.begin(), ::tolower);
		sort(in.begin(), in.end());
		trans.pb(in);
	}

	N = dic.size();

	sort(dic.begin(), dic.end());
	for(int i=0; i < N; i++) {
		ct = 0;
		mut = dic[i];
		transform(mut.begin(), mut.end(), mut.begin(), ::tolower);
		sort(mut.begin(), mut.end());

		for(int j=0; ct < 2 && j < N; j++)
			if(mut == trans[j])
				ct++;
		
		if(ct == 1)
			cout<<dic[i]<<endl;
	}

	return 0;
}