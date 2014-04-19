#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pb(x) push_back(x)


bool subtractKing(vector<char> hand) {
	return hand.size() == 1 && hand[0] == 'K';
}

bool subtractQueen(vector<char> hand) {
	return find(hand.begin(), hand.end(), 'Q') != hand.end()
	&& hand.size() <= 2;
}

bool subtractJack(vector<char> hand) {
	return find(hand.begin(), hand.end(), 'J') != hand.end() && hand.size() <= 3;
}

bool checkStopped(vector<char> hand) {
	return find(hand.begin(), hand.end(), 'A') != hand.end()
	|| (find(hand.begin(), hand.end(), 'K') != hand.end() && hand.size() >= 2)
	|| (find(hand.begin(), hand.end(), 'Q') != hand.end() && hand.size() >= 3);
}

void printSuit(vector<char> hand) {
	for(int i=0; i < hand.size(); i++)
		cout<<hand[i]<<" ";
	cout<<endl;
}

int main() {

	string cur;

	while(cin>>cur) {
		vector<string> hand;
		hand.pb(cur);
		for(int i=0; i < 12; i++) {
			cin>>cur;
			hand.pb(cur);
		}
		int point = 0;
		vector< vector<char> > V(4, vector<char>());
		for(int i=0; i < hand.size(); i++) {
			cur = hand[i];
			if(cur[0] == 'A') point += 4;
			else if(cur[0] == 'K') point += 3;
			else if(cur[0] == 'Q') point += 2;
			else if(cur[0] == 'J') point += 1;

			if(cur[1] == 'S') V[0].pb(cur[0]);
			else if(cur[1] == 'H') V[1].pb(cur[0]);
			else if(cur[1] == 'D') V[2].pb(cur[0]);
			else V[3].pb(cur[0]);
		}
		bool isStopped = true;
		int ct = 0;
		for(vector<char> suit : V) {
			if(subtractKing(suit)) point -= 1;
			if(subtractQueen(suit)) point -= 1;
			if(subtractJack(suit)) point -= 1;
			isStopped &= checkStopped(suit);
		}

		if(point >= 16 && isStopped) {
			cout<<"BID NO-TRUMP"<<endl;
			continue;
		}

		for(vector<char> suit : V) {
			if(suit.size() == 2) point += 1;
			else if(suit.size() == 1) point += 2;
			else if(suit.size() == 0) point += 2;
		}

		if(point < 14) {
			cout<<"PASS"<<endl;
			continue;
		}

		int sz = 0;
		char best = 'X';
		for(int i=0; i < V.size(); i++) {
			if(V[i].size() > sz) {
				sz = V[i].size();
				if(i == 0) best = 'S';
				else if(i == 1) best = 'H';
				else if(i == 2) best = 'D';
				else best = 'C';
			}
		}

		cout<<"BID "<<best<<endl;


		
	}


	return 0;

}