#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, N;
	cin>>T;
	while(T--) {
		cin>>N;
		N = (((((N*567) / 9) + 7492 ) * 235) / 47) - 498;
		cout<<abs((N%100) / 10)<<endl;
	}
	return 0;
}