#include <iostream>
#include <queue>
using namespace std;

#define MAXN 1010
int holes[MAXN];
int N, C, small, big;
int cost[MAXN]; // cost[i] = cost to cover patches[0..i-1]

int main() {

	while(cin>>N>>C>>small>>big) {
		if(small > big)
			swap(small, big);

		for(int i=0; i < N; i++)
			cin>>holes[i];

		for(int i=0; i <= N; i++)
			cost[i] = -1;


		queue<int> Q;
		Q.push(0);
		cost[0] = 0;
		while(!Q.empty()) {
			int curNode = Q.front(); Q.pop();

			int bigNode = curNode;
			int bigCover = holes[curNode] + big;
			while(bigNode < N && bigCover >= holes[bigNode])
				bigNode++;

			if(cost[bigNode] == -1 || (cost[curNode] + big) < cost[bigNode]) {
				cost[bigNode] = cost[curNode] + big;
				if(bigNode != N)
					Q.push(bigNode);
			}

			int smallNode = curNode;
			int smallCover = holes[curNode] + small;
			while(smallNode < N && smallCover >= holes[smallNode])
				smallNode++;

			if( cost[smallNode] == -1 || (cost[curNode] + small) < cost[smallNode] ) {
				cost[smallNode] = cost[curNode] + small;

				if(smallNode != N)
					Q.push(smallNode);
			}
		}

		cout<<cost[N]<<endl;
	}

	return 0;
}