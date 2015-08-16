#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

bool isAllowed(char ch) {
	if('a' <= ch && ch <= 'z') return true;
	if(ch == ' ') return true;
	if(ch == ':') return true;
	if(ch == '(') return true;
	if(ch == ')') return true;
	return false;
}

bool isOkay(int idx, int leftP) {
	if(leftP < 0) return false;
	if(idx == str.size()) return (leftP == 0);
	char ch = str[idx];
	if(!isAllowed(ch)) return false;
	if(ch == ':') {
		if(idx == str.size() - 1) return isOkay(idx+1, leftP);

		char nextCh = str[idx+1];
		if(nextCh == '(' || nextCh == ')') 
			return isOkay(idx+1, leftP) || isOkay(idx+2, leftP);
		return isOkay(idx+1, leftP);
	}

	if(ch == ')') return isOkay(idx+1, leftP-1);
	if(ch == '(') return isOkay(idx+1, leftP+1);

	return true;

}

int main() {
	int N;
	int caseID = 0;
	string res;
	cin>>N;
	getline(cin, str); //get rid of new line
	while(++caseID <= N) {
		getline(cin, str);
		res = (isOkay(0,0)) ? "YES" : "NO";
		cout<<"Case #"<<caseID<<": "<<res<<endl;
	}


	return 0;
}