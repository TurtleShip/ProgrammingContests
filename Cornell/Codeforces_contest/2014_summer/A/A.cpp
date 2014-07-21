#include <iostream>
#include <algorithm>
#include <bitset>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool canTell(const vector<int>&, const int&, const int& );

int main() {
	int N;
	string card;
	
	map<string,int> cardMapper;
	string letters = "RGBYW";
	string numbers = "12345";

	for(int i=0; i < letters.size(); i++)
		for(int j=0; j < numbers.size(); j++) {
			string tmp(2, 'a');
			tmp[0] = letters[i];
			tmp[1] = numbers[j];
			cardMapper[tmp] = (1<<(5+i)) + (1<<j);
		}

	cin>>N;
	vector<int> V(N);

	for(int i=0; i < N; i++) {
		cin>>card;
		V[i] = cardMapper[card];
	}

	// there are 10 possible hints, and 2^10 combinations of them. 
	// Brute-force is good enough.
	int res = 1010;
	for(int mask = 0; mask < (1<<10); mask++) {
		if(canTell(V, N, mask)) {
			bitset<10> bit(mask);
			res = min(res, int(bit.count()));
		}
	}

	cout<<res<<endl;

	return 0;
}

bool canTell(const vector<int>& cards, const int& N, const int& mask) {
	for(int i=0; i < N; i++) {
		for(int j=i+1; j < N; j++) {
			if(cards[i] == cards[j]) continue;
			if((cards[i] & mask) == (cards[j] & mask)) return false;
		}
	}
	return true;
}