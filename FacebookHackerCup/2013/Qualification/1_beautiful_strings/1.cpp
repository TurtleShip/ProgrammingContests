#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<int> V(26, 0);
    int N;
    int res;
    int idx = 0;
    string str;

    cin>>N;
    getline(cin, str); //get rid of \n
    while(++idx <= N) {
    	getline(cin, str);
    	fill_n(V.begin(), V.size(), 0);
    	transform(str.begin(), str.end(), str.begin(), ::tolower);
    	for(int i=0; i < str.size(); i++) {
    		if(!isalpha(str[i])) continue;
    		V[str[i] - 'a']++;
    	}
    	sort(V.rbegin(), V.rend());
    	res = 0;
    	for(int i=0; i < V.size(); i++)
    		res += (26-i) * V[i];
    	cout<<"Case #"<<idx<<": "<<res<<endl;
    }
	return 0;
}
