#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getInt(string str) {
	int ten = 1;
	int res = 0;

	for(int  i = str.size() - 1; i >= 1; i--) {
		res += (str[i] - '0') * ten;
		ten *= 10;
	}

	return res;
}

string getDiff(string small, string big) {
	string res;
	int idx = 0;
	while(idx < small.size() && small[idx] == big[idx])
		idx++;
	
	for(int i=idx; i < small.size(); i++)
		res.push_back(big[i]);
	return res;
}

int main() {
	int N, cid = 1;
	vector<string> V;
	vector<int> VI;
	vector<string> res;
	string str;

	while(cin>>N && N != 0) {
		V.clear();
		V.resize(N);
		VI.resize(N);

		for(int i=0; i < N; i++) {
			cin>>V[i];
			VI[i] = getInt(V[i]);
		}

		int st = 0;
		int idx = 0;
		bool hit_end = false;
		cout<<"Case "<<cid++<<":"<<endl;

		while(idx < N && !hit_end) {
			st = idx;
		
			while( (idx+1) < N && (VI[idx] + 1) == VI[idx+1] )
				idx++;
			
			if(st == idx) cout<<V[idx]<<endl;
			else cout<<V[st]<<"-"<<getDiff(V[st], V[idx])<<endl;
			idx++;
		}

		cout<<endl;
	}

	return 0;
}
