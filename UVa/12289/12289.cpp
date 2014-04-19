#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, ct;
	string word, one = "one";
	cin>>N;
	while(N--) {
		cin>>word;
		if(word.size() == 5) cout<<3<<endl;
		else {
			ct = 0;
			for(int i=0; i < 3; i++)
				if(word[i] == one[i]) ct++;
			if(ct >= 2) cout<<1<<endl;
			else cout<<2<<endl;
		}
	} 

	return 0;
}