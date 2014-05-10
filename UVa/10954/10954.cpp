#include <iostream>
#include <queue>
using namespace std;

#define all(v) (v).begin(), (v).end()
// #define pb(x) push_back(x)

int main() {
	int N;
	while(cin>>N && N != 0) {
		int num;
		priority_queue< int, vector<int>, greater<int> >Q;
		for(int i=0; i < N; i++) {
			cin>>num;
			Q.push(num);
		}

		int res = 0;
		while(Q.size() > 1) {
			int x = Q.top(); Q.pop();
			int y = Q.top(); Q.pop();
			res += x + y;
			Q.push(x+y);
		}
		cout<<res<<endl;
		
	}
	return 0;
}