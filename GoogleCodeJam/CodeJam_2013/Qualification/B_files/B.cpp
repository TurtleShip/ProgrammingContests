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
int G[100][100];
bool hasNum[110];
bool isCut[100][100];
int main()
{
	int T;
	int idx = 0;
	int R;
	int C;
	string yes = "YES";
	string no = "NO";


	cin>>T;


	while((++idx) <= T) {
		cout<<"Case #"<<idx<<": ";
		memset(hasNum, false, sizeof(hasNum));
		vector<int> V;

		cin>>R>>C;
		for(int i=0; i < R; i++)
			for(int j=0; j < C; j++) {
				isCut[i][j] = false;
				cin>>G[i][j];
				if(!hasNum[G[i][j]]) {
					hasNum[G[i][j]] = true;
					V.push_back(G[i][j]);
				}
			}


		// sort in reverse order
		sort(V.rbegin(), V.rend());

		// trivial case
		if(R == 1 || C == 1) {
			cout<<yes<<endl;
			continue;
		}

		// let's think of impossible cases
	
		for(int v = 0; v < V.size(); v++) {
			int curNum = V[v];

			// for each row, check if it is possible to cut curNum
			for(int i=0; i < R; i++) {
				bool canCut = true;
				for(int j=0; j < C; j++) {
					if(isCut[i][j]) {
						canCut = false;
						break;
					}
				}

				if(canCut) {
					for(int j=0; j < C; j++) {
						if(G[i][j] == curNum) {
							isCut[i][j] = true;
						}
					}
				}
			}

			// check each column also
			for(int c=0; c < C; c++) {
				bool canCut = true;
				for(int r=0; r < R; r++) {
					if(isCut[r][c] && G[r][c] != curNum) {
						canCut = false;
						break;
					}
				}

				if(canCut) {
					for(int r=0; r < R; r++) {
						if(G[r][c] == curNum) {
							isCut[r][c] = true;
						}

					}
				}
			}

		}

		bool isYes = true;

		// check if all grasses are cut
		for(int i=0; isYes && i < R; i++)
			for(int j=0; isYes && j < C; j++)
				isYes = isCut[i][j]; 

		if(isYes) cout<<yes<<endl;
		else cout<<no<<endl;

	}


    return 0;

}