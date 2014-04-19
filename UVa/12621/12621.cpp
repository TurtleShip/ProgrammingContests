#include <iostream>
using namespace std;

bool isGood[1010];


int main() {
	int T;
	cin>>T;
	int N, P;

	while(T--) {
		cin>>N>>P;
		int sum = 0;
		int cur;
		N /= 10;
		for(int i=1; i <= 1000; i++)
			isGood[i] = false;
		isGood[0] = true; // can always choose nothing

		for(int i=0; i < P; i++) {
			cin>>cur;
			cur /= 10;
			sum += cur;
			// cout<<"cur : "<<cur<<endl;
			for(int j=1000; j >= 0; j--) {
				if(isGood[j]) {
					isGood[j+cur] = true;
					// cout<<"checked : "<<(j+cur)<<endl;

				}
			}
		}

		// no solution if the sum is smaller than n
		if(sum < N) {
			cout<<"NO SOLUTION"<<endl;
		} else if (sum == N) {
			cout<<sum*10<<endl;
		} else {
			int res = 0;
			// now we choose minimally
			for(int j=N; j <= sum; j++)
				if(isGood[j]) {
					res = j * 10;
					break;
				}

			
			if(res) cout<<res<<endl;
			else cout<<"NO SOLUTION"<<endl;
		}

	}

	return 0;
}