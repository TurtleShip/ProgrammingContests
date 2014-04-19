#include <iostream>
#include <queue>
using namespace std;

const int maxN = 110;
int in[110]; // in[i] = number of incoming edges to i
int out[110]; // out[i] = number of outgoing edges from i
int dst[maxN][maxN]; // dst[i][j] = (j)th destination node from node i

int main() {
	int N,M;
	int a,b;
	while(cin>>N>>M) {
		if(N ==0 && M == 0)
			break;
		
		// initialize
		for(int i=1; i <= N; i++)
			in[i] = out[i] = 0;

		for(int m=0; m < M; m++) {
			cin>>a>>b;

			dst[a][out[a]] = b;
			out[a]++;
			in[b]++;
		}

		bool isFirst= true;
		queue<int> Q;
		for(int i=1; i <= N; i++)
			if(!in[i])
				Q.push(i);

		while(!Q.empty()) {
			int cur = Q.front(); Q.pop();
			if(isFirst) isFirst = false;
			else cout<<" ";

			cout<<cur;
			for(int i=0; i < out[cur]; i++)
				if(!--in[dst[cur][i]])
					Q.push(dst[cur][i]);
		}
		cout<<endl;



	}

	return 0;
}