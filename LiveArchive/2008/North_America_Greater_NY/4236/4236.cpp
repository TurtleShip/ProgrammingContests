#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAXN 26
double P[MAXN];
int bestKey[MAXN];
int tmpKey[MAXN];
double bestRes;
double memo[30][30][30][10];
double dp[30][30][10];
int K;
/*
keyLeft = number of keys left, not including the current one
curPos = current character position
*/

void findBest(int keyLeft, int curPos, int curKey, int curFreq, double res) {

	if(curPos == 26) {
		if(keyLeft == 0 && res < bestRes) {
			bestRes = res;
			for(int i=0; i < MAXN; i++)
				bestKey[i] = tmpKey[i];
		}
		return;
	}

	if(keyLeft == 0) return;
	if(memo[keyLeft][curPos][curKey][curFreq] <= res) return;
	memo[keyLeft][curPos][curKey][curFreq] = res;

	

	double curVal = double(curFreq) * P[curPos] + res;

	// try using the  current keypad
	if(curFreq < 8) {
		tmpKey[curPos] = curKey;
		findBest(keyLeft, curPos+1, curKey, curFreq+1, curVal);
	}

	// move on to the other keypad
	if(curFreq >= 1) {
		tmpKey[curPos] = curKey;
		findBest(keyLeft-1, curPos+1, curKey+1, 1, curVal);
	}
}

// each key contains [1,8] letters
int main() {
	int N;
	int caseId = 1;
	cin>>N;
	cout<<fixed<<setprecision(3);
	while(N--) {
		
		cin>>K;
		for(int i=0; i < MAXN; i++)
			cin>>P[i];

		bestRes = 100000000.0;
		
		for(int i=0; i < 30; i++)
			for(int j=0; j < 30; j++)
				for(int k=0; k < 30; k++)
					for(int l=0; l < 10; l++)
						memo[i][j][k][l] = bestRes;


		findBest(K,0,0,1,0.0);

		bestRes /= 100.0;


		// divide by 
		cout<<caseId++<<" "<<bestRes<<" ";
		char ch = 'A';
		cout<<ch++;
		for(int i=1; i < MAXN; i++) {
			if(bestKey[i] != bestKey[i-1]) cout<<" ";
			cout<<ch++;
		}
		cout<<endl;
	}
	return 0;
}