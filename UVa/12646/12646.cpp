#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	while(cin>>a>>b>>c) {
		int num = a * 100 + b * 10 + c;
		switch(num) {
			case 100:
			case 11:
			cout<<"A"<<endl;
			break;
			case 10:
			case 101:
			cout<<"B"<<endl;
			break;
			case 1:
			case 110:
			cout<<"C"<<endl;
			break;
			default:
			cout<<"*"<<endl;
		}
	}
	return 0;
}