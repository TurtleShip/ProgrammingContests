#include <iostream>
#include <string>
using namespace std;

int getIdx(char ch) {
	return ch - 'A';
}
string left_str[3];
string right_str[3];
string measure[3];

bool isHeavy(char ch) {
	bool was_measured = false;
	for(int i=0; i < 3; i++) {
		bool found = false;
		for(int j=0; j < left_str[i].size(); j++)
			if(left_str[i][j] == ch) {
				found = true;
				if(measure[i] != "up") return false;
			}

		for(int j=0; j < right_str[i].size(); j++)
			if(right_str[i][j] == ch) {
				found = true;
				if(measure[i] != "down") return false;
			}
		if(!found && measure[i] != "even") return false;	
		was_measured |= found;
	}
	return was_measured;
}

bool isLight(char ch) {
	bool was_measured = false;
	for(int i=0; i < 3; i++) {
		bool found = false;
		for(int j=0; j < left_str[i].size(); j++)
			if(left_str[i][j] == ch) {
				found = true;
				if(measure[i] != "down") return false;
			}

		for(int j=0; j < right_str[i].size(); j++)
			if(right_str[i][j] == ch) {
				if(measure[i] != "up") return false;
				found = true;
			}

		if(!found && measure[i] != "even") return false;
		was_measured |= found;
	}
	return was_measured;
}

int main() {
	int T;

	cin>>T;

	while(T--) {
		for(int i=0; i < 3; i++)
			cin>>left_str[i]>>right_str[i]>>measure[i];

		for(char ch = 'A'; ch <= 'L'; ch++) {
			if(isHeavy(ch)) cout<<ch<<" is the counterfeit coin and it is heavy."<<endl;
			else if(isLight(ch)) cout<<ch<<" is the counterfeit coin and it is light."<<endl;
		}

	}

	return 0;
}