#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

void makeUnique(string &str) {
	sort(str.begin(), str.end());
	str.resize( distance(str.begin(), unique(str.begin(), str.end())));
}

int main() {
	int T, right;
	string win = "You win.";
	string lose = "You lose.";
	string chicken = "You chickened out.";
	string ans, guess;

	while(cin>>T && T != -1) {
		cin>>ans>>guess;
		right = 0;
		set<char> wrong;
		set<char> right;
		makeUnique(ans);

		for(int i=0; right.size() != ans.size() && wrong.size() != 7 && i < guess.size(); i++) {
			char curGuess =guess[i];
			if(wrong.find(curGuess) != wrong.end())
				continue;
			bool found = false;
			for(int j=0; j < ans.size(); j++)
				if(curGuess == ans[j]) {
					found = true;
					right.insert(curGuess);
				}
			if(!found)
				wrong.insert(curGuess);
		}
		cout<<"Round "<<T<<endl;
		if(right.size() == ans.size()) cout<<win<<endl;
		else if(wrong.size() == 7) cout<<lose<<endl;
		else cout<<chicken<<endl;

	}
	return 0;
}