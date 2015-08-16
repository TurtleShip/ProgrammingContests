#include <iostream>
#include <string>
using namespace std;
const int MAXN = 300010;
int arr[MAXN*2];

int diff(int s, int t) {
	if(t == 0 && s != 0) return 8 - s;
	if(t >= s) return t - s;
	return 8 - s + t;

}

int main() {
	string str;
	string norm;
	while(cin>>str) {
		int N = str.size();
		for(int i=0; i < N-1; i++)
			arr[i] = diff(str[i] - '0', str[i+1] - '0');
		arr[N-1] = diff(str[N-1] - '0', str[0] - '0');
		
		for(int i=0; i < N; i++)
			arr[N+i] = arr[i];


		int best = 0;
		for(int offset = 1; offset < N; offset++) {
			for(int i=0; i < N; i++) {
				if(arr[i+best] == arr[i+offset]) continue;
				if(arr[i+offset] < arr[i+best]) best = offset;
				break;
			}
		}

		for(int i=0; i < N; i++)
			cout<<arr[i+best];
		cout<<endl;

		

	}

	return 0;
}