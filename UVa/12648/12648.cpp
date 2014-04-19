#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 550

/*
boss[x][i] = y : ith boss of x is y
bossDegree[x] = number of bosses of x
child[x][i] = y : (i)th child of x is y
childDegree[y] = number of children of y
*/
int boss[MAXN][MAXN];
int bossDegree[MAXN];
int child[MAXN][MAXN];
int childDegree[MAXN];
bool isVisited[MAXN];
int age[MAXN];
int tmpArr[MAXN];

int main() {
	int N,M,I;
	int x,y;
	char inst;
	int A, B, E;

	while(cin>>N>>M>>I) {

		// init
		for(int i=1; i <= N; i++)
			bossDegree[i] = childDegree[i] = 0;

		for(int i=1; i <= N; i++)
			cin>>age[i];

		while(M--) {
			cin>>x>>y;
			// x manages y directly
			child[x][childDegree[x]++] = y;
			boss[y][bossDegree[y]++] = x;
		}

		while(I--) {
			cin>>inst;
			if(inst == 'T') { // swap
				cin>>A>>B;
		
				//exchange children
				for(int i=0; i < childDegree[A]; i++)
					tmpArr[i] = child[A][i];
				for(int i=0; i < childDegree[B]; i++)
					child[A][i] = child[B][i];
				for(int i=0; i < childDegree[A]; i++)
					child[B][i] = tmpArr[i];
				swap(childDegree[A], childDegree[B]);

				// update children info
				for(int i=0; i < childDegree[A]; i++) {
					int curChild = child[A][i];
					for(int j=0; j < bossDegree[curChild]; j++)
						if(boss[curChild][j] == B) {
							boss[curChild][j] = A;
							break;
						}
				}
				for(int i=0; i < childDegree[B]; i++) {
					int curChild = child[B][i];
					for(int j=0; j < bossDegree[curChild]; j++)
						if(boss[curChild][j] == A) {
							boss[curChild][j] = B;
							break;
						}
				}

				// exchange boss
				for(int i=0; i < bossDegree[A]; i++)
					tmpArr[i] = boss[A][i];
				for(int i=0; i < bossDegree[B]; i++)
					boss[A][i] = boss[B][i];
				for(int i=0; i < bossDegree[A]; i++)
					boss[B][i] = tmpArr[i];
				swap(bossDegree[A], bossDegree[B]);

				// update boss info
				for(int i=0; i < bossDegree[A]; i++) {
					int curBoss = boss[A][i];
					for(int j=0; j < childDegree[curBoss]; j++)
						if(child[curBoss][j] == B) {
							child[curBoss][j] = A;
							break;
						}
				}
				for(int i=0; i < bossDegree[B]; i++) {
					int curBoss = boss[B][i];
					for(int j=0; j < childDegree[curBoss]; j++)
						if(child[curBoss][j] == A) {
							child[curBoss][j] = B;
							break;
						}
				}

			} else { // find youngest boss
				
				cin>>E;
	
				if(bossDegree[E] == 0) {
					cout<<"*"<<endl;
					continue;
				} 
				
				for(int i=1; i <= N; i++)
					isVisited[i]= false;

				queue<int> Q;
				int youngest = 10000;
		
				for(int i=0; i < bossDegree[E]; i++) {
					Q.push(boss[E][i]);
					youngest = min(youngest, age[boss[E][i]]);
					isVisited[boss[E][i]] = true;
				}

				while(!Q.empty()) {
					int cur = Q.front(); Q.pop();
					for(int i=0; i < bossDegree[cur]; i++) {
						if(!isVisited[boss[cur][i]]) {
							youngest = min(youngest, age[boss[cur][i]]);
							Q.push(boss[cur][i]);
							isVisited[boss[cur][i]] = true;
						}
					}
				}
				cout<<youngest<<endl;
			}
		}

	}
	return 0;
}