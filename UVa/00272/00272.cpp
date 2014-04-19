#include <cstring>
#include <iostream>
using namespace std;

int main() {
	bool isOpen = true;
	string line;

	while(getline(cin, line)) {
		for(int i=0; i < line.size(); i++) {
			if(line[i] == '"') {
				if(isOpen) cout<<"``";
				else cout<<"''";
				isOpen = !isOpen;
			} else cout<<line[i];
		}
		cout<<endl;
	}

	return 0;
}