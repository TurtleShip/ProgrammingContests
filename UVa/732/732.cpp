#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define pb(x) push_back(x)
#define all(v) (v).begin(), (v).end()

void solve(string srcWord, string stackWord, string resWord, string curPath, const string& target, vector<string>& res, const int& N) {
	
	// This line is crucial. Stop if the current result is invalid
	if(resWord != target.substr(0, resWord.size())) return;

	if(curPath.size() == N) {
		if(resWord == target) {
			res.pb(curPath);	
		}
		return;
	}

	if(srcWord.size() > 0) { // can push
		solve(srcWord.substr(1), stackWord + srcWord[0], resWord, curPath + "i", target, res, N);
	}

	if(stackWord.size() > 0) { // can pop
		solve(srcWord, stackWord.substr(0, stackWord.size() - 1), resWord + stackWord[stackWord.size() - 1],
			curPath + "o", target, res, N);
	}
}

int main() {

	string src, target;

	while(cin>>src>>target) {
		vector<string> res;
		
		// do precheck
		string tmpSrc = src;
		string tmpTarget = target;
		sort( all(tmpSrc) );
		sort( all(tmpTarget) );
		if(tmpSrc == tmpTarget) {
			solve(src, "", "", "", target, res, target.size() * 2);	
		}

		sort( all(res) );
		cout<<"["<<endl;
		for(string str : res) {
			cout<<str[0];
			for(int i=1; i < str.size(); i++)
				cout<<" "<<str[i];
			cout<<endl;
		}
		cout<<"]"<<endl;
	}

	return 0;
}
