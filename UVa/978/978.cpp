#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define all(v) (v).begin(), (v).end()

void printTeam(priority_queue<int>& Q) {
	while(!Q.empty()) {
		cout<<Q.top()<<endl;
		Q.pop();
	}
}

int main() {
	int N, B, SG, SB;
	bool isFirst = true;
	cin>>N;
	while(N--) {
		if(isFirst) isFirst = false;
		else cout<<endl;

		cin>>B>>SG>>SB;

		priority_queue<int> greenBarrack;
		priority_queue<int> blueBarrack;
		vector<int> greenArmy(B);
		vector<int> blueArmy(B);
		
		int greenSolider, blueSoldier;
		while(SG--) {
			cin>>greenSolider;
			greenBarrack.push(greenSolider);
		}

		while(SB--) {
			cin>>blueSoldier;
			blueBarrack.push(blueSoldier);
		}

		while(!greenBarrack.empty() && !blueBarrack.empty()) {
			int greenArmySize = 0;
			int blueArmySize = 0;
			
			while(greenArmySize < B && !greenBarrack.empty()) {
				greenArmy[greenArmySize++] = greenBarrack.top();
				greenBarrack.pop();
			}

			while(blueArmySize < B && !blueBarrack.empty()) {
				blueArmy[blueArmySize++] = blueBarrack.top();
				blueBarrack.pop();
			}

			int limit = min(greenArmySize, blueArmySize);
			for(int i=0; i < limit; i++) {
				greenSolider = greenArmy[i];
				blueSoldier = blueArmy[i];
				greenArmy[i] -= blueSoldier;
				blueArmy[i] -= greenSolider;	
			}

			for(int i=0; i < greenArmySize; i++)
				if(greenArmy[i] > 0)
					greenBarrack.push(greenArmy[i]);

			for(int i=0; i < blueArmySize; i++)
				if(blueArmy[i] > 0)
					blueBarrack.push(blueArmy[i]);
			
		}

		if(greenBarrack.empty() && blueBarrack.empty()) {
			cout<<"green and blue died"<<endl;
		} else if(greenBarrack.empty()) {
			cout<<"blue wins"<<endl;
			printTeam(blueBarrack);
		} else { // blue.empty()
			cout<<"green wins"<<endl;
			printTeam(greenBarrack);
		}
	}
	return 0;
}