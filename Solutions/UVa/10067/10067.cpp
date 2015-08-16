#include <iostream>
#include <queue>
using namespace std;

/*
There are 10,000 nodes.
For each node, there are 3*3*3*3 = 3^4 = 81 different configuration to try.
*/
#define MAXV 10000
#define MAXDEGREE 90

bool isVisited[MAXV];
bool isForbidden[MAXV];
int config[8] = {1,-1,10,-10,100,-100,1000,-1000};
int pathLen[MAXV];

int getNum() {
	int res = 0;
	int tmp;
	for(int i=0; i < 4; i++) {
		cin>>tmp;
		res *= 10;
		res += tmp;
	}
	return res;
}
int getNext(int num, int idx) {
	int change = -1;
	switch(idx) {
		case 0:
		change = num % 10;
		change = (change + 1) % 10;
		num = (num / 10) * 10 + change;
		break;
		
		case 1:
		change  = num % 10;
		change = (10 + change - 1) % 10;
		num = (num / 10) * 10 + change;
		break;
		
		case 2:
		change = (num / 10) % 10;
		change = ((change + 1) % 10) * 10;
		num = (num / 100) * 100 + change + num % 10;
		break;
		
		case 3:
		change = (num / 10) % 10;
		change = ((10 + change - 1) % 10) * 10;
		num = (num / 100) * 100 + change + num % 10;
		break;
		
		case 4:
		change = (num / 100) % 10;
		change = ((change + 1) % 10) * 100;
		num = (num / 1000) * 1000 + change + num % 100;
		break;
		
		case 5:
		change = (num / 100) % 10;
		change = ((10 +change - 1) % 10) * 100;
		num = (num / 1000) * 1000 + change + num % 100;
		break;

		case 6:
		change = num / 1000;
		change = ((change + 1) % 10) * 1000;
		num = change + num % 1000;
		break;

		case 7:
		change = num / 1000;
		change = ((10 + change -1) % 10) * 1000;
		num = change + num % 1000;
		break;
	}
	
	return num;
}

int main() {
	int T;
	int st;
	int target;
	int F, tmp;

	cin>>T;

	while(T--) {
		// initialize
		for(int i=0; i < MAXV; i++) {
			isVisited[i] = false;
			isForbidden[i] = false;
			pathLen[i] = -1;
		}

		st = getNum();
		target = getNum();

		cin>>F;

		while(F--) {
			tmp = getNum();
			isForbidden[tmp] = true;
		}


		queue<int> Q;
		if(!isForbidden[st]) {
			Q.push(st);
			pathLen[st] = 0;
			isVisited[st] = 0;
		}

		while(!Q.empty()) {
			int cur = Q.front(); Q.pop();
			if(cur == target) break;

			for(int i = 0; i < 8; i++) {
				int next = getNext(cur, i);
				if(!isForbidden[next] && !isVisited[next] ) {
					isVisited[next] = true;
					pathLen[next] = pathLen[cur] + 1;
					Q.push(next);
				}
			}
		}

		cout<<pathLen[target]<<endl;
	}
	return 0;
}