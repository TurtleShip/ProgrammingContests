#include <iostream>
using namespace std;

int main() {
	for(int i=0; i < 500; i++) {
		for(int j=0; j < 500; j++) {
			if((i != 499 || i != 200) && (j == 250 || j == 450 )) cout <<"#";
			else cout<<'.';

		}
			
		cout<<endl;
	}
	return 0;
}