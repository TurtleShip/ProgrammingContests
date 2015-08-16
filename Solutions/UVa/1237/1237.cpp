#include <iostream>
#include <string>
using namespace std;

const int maxD = 10000;
int L[maxD + 10];
int H[maxD + 10];
string name[maxD + 10];

int main() {
	int T, D, Q, P;
	cin>>T;
	string undetermined = "UNDETERMINED";
	for(int cid=1; cid<= T; cid++) {
		if(cid > 1) cout<<endl;

		cin>>D;
		for(int i=0; i < D; i++) {
			cin>>name[i]>>L[i]>>H[i];
		}

		cin>>Q;
		while(Q--) {
			bool found = false;
			bool dup = false;
			string res = "";
			cin>>P;
			for(int i=0; !dup && i < D; i++) {
				if(L[i] <= P && P <= H[i]) {
					if(!found) found = true;
					else dup = true;
					res = name[i];
				}
			}
			if(!found || dup) cout<<undetermined<<endl;
			else cout<<res<<endl;
		}
	}
	return 0;
}