#include <iostream>
#include <vector>
using namespace std;

#define pb(x) push_back(x)

int main() {
	vector<int> resInfo[10010];
	vector<int> resNum[10010];

	int R, C;
	while(cin>>R>>C) {
		for(int c=1; c <= C; c++) {
			resInfo[c].clear();
			resNum[c].clear();
		}

		for(int r=1; r <= R; r++) {
			int curC;
			cin>>curC;
			vector<int> colInfo(curC);
			for(int i=0; i < curC; i++)
				cin>>colInfo[i];
			int num;
			for(int i=0; i < curC; i++) {
				cin>>num;
				resInfo[colInfo[i]].pb(r);
				resNum[colInfo[i]].pb(num);
			}
		}

		// output result
		cout<<C<<" "<<R<<endl;
		for(int c=1; c <= C; c++) {
			cout<<resInfo[c].size();
			for(int x : resInfo[c]) {
				cout<<" "<<x;
			}
			cout<<endl;
			for(int i=0; i < resNum[c].size(); i++) {
				if(i > 0) cout<<" ";
				cout<<resNum[c][i];
			}
			cout<<endl;
		}
	}
	
	return 0;
}