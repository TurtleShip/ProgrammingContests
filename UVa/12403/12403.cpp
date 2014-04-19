#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, cur, amt = 0;
	string cmd;
	cin>>T;
	while(T--) {
		cin>>cmd;
		if(cmd[0] == 'r') cout<<amt<<endl;
		else {
			cin>>cur;
			amt += cur;
		}
	}
	return 0;
}