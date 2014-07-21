#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	string line;
	set<char> res;
	getline(cin, line);
	for(char ch : line) {
		if('a' <= ch && ch <= 'z')
			res.insert(ch);
	}
	cout<<res.size()<<endl;
	return 0;
}