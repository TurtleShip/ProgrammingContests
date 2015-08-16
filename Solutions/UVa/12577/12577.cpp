#include <iostream>
#include <string>
using namespace std;

int main() {
	string pray;
	int cid = 1;
	while(cin>>pray && pray != "*") {
		cout<<"Case "<<cid++<<": ";
		if(pray == "Hajj") cout<<"Hajj-e-Akbar"<<endl;
		else cout<<"Hajj-e-Asghar"<<endl;
	}
	return 0;
}