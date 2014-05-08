#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

#define pb(x) push_back(x)

int main() {
	string str;
	int cid = 1;
	while(cin>> str && str != "end") {
		vector< stack<char> >V;

		for(char ch : str) {
			bool found = false;
			for(stack<char>& stk : V) {
				if(stk.top() >= ch) {
					stk.push(ch);
					found = true;
					break;
				}
			}
			if(!found) {
				stack<char> stk;
				stk.push(ch);
				V.pb(stk);
			}
		}
		cout<<"Case "<<cid++<<": "<<V.size()<<endl;
	}
	return 0;
}