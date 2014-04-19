#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

typedef long long ll;

char M[4][4];
bool hasDot = false;

bool isWon(char ch) {
	// check rows
	for(int r=0; r < 4; r++) {
		bool isGood = true;
		bool hasT = false;
		for(int c=0; c < 4; c++) {
			if(M[r][c] != ch) {
				if(M[r][c] == 'T' && !hasT) {
					hasT = true;
				} else {
					isGood = false;
					break;
				}
			}
		}
		if(isGood) return true;
	}

	// check cols
	for(int c=0; c < 4; c++) {
		bool isGood = true;
		bool hasT = false;
		for(int r=0; r < 4; r++) {
			if(M[r][c] != ch) {
				if(M[r][c] == 'T' && !hasT) {
					hasT = true;
				} else {
					isGood = false;
					break;
				}
			}
		}
		if(isGood) return true;
	}

	// check diagonals
	bool isGood = true;
	bool hasT = false;
	for(int i=0; i < 4; i++) {
		if(M[i][i] != ch) {
			if(M[i][i] == 'T' && !hasT) {
				hasT = true;
			} else {
				isGood = false;
				break;
			}
		}
	}

	if(isGood) return true;

	isGood = true;
	hasT = false;

	for(int i=0; i < 4; i++) {
		if(M[i][3-i] != ch) {
			if(M[i][3-i] == 'T' && !hasT) {
				hasT = true;
			} else {
				isGood = false;
				break;
			}
		}
	}
	return isGood;
}


int main()
{
	string xWon = "X won";
	string oWon = "O won";
	string draw = "Draw";
	string notOver = "Game has not completed";
	int N; // number of test cases
	int idx = 0;

	cin>>N;

	while((++idx) <= N) {
		cout<<"Case #"<<idx<<": ";
		for(int i=0; i < 4; i++)
			for(int j=0; j < 4; j++)
				cin>>M[i][j];


		hasDot = false;

		// check if X won
		if(isWon('X')) {
			cout<<xWon<<endl;
			continue;
		}

		// check if Y Won
		if(isWon('O')) {
			cout<<oWon<<endl;
			continue;
		}

		// check for dots
		for(int i=0; !hasDot && i < 4; i++)
			for(int j=0; j < 4; j++)
				if(M[i][j] == '.') {
					hasDot = true;
					break;
				}

		if(hasDot) {
			cout<<notOver<<endl;
			continue;
		}

		// The game must be a draw
		cout<<draw<<endl;
	}




    return 0;

}