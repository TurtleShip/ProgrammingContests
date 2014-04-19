#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	map<char, char> M;
	string in, code;

	cin>>N;
	int caseIdx = 0;
	getline(cin,in);
	while(++caseIdx <= N) {
		getline(cin, in);
		getline(cin, code);
		char ch = 'A';
		int idx = 0;
		while(ch<='Z') {
			M[ch++] = code[idx++];
		}

		cout<<caseIdx<<" ";
		for(int i=0; i < in.size(); i++) {
			if(in[i] == ' ') {
				cout<<' ';
				continue;
			}
			cout<<M[in[i]];

		}
			
		cout<<endl;
	}
	return 0;
}