#include <iostream>
using namespace std;

int main() {
	int T, N, M, res;
	cin>>T;
	while(T--) {
		cin>>N>>M;
		N -= 2;
		M -= 2;
		res = (N%3 == 0) ? (N/3) : (N/3 + 1);
		res *= (M%3 == 0) ? (M/3) : (M/3 + 1);
		cout<<res<<endl;
	}

	return 0;
}