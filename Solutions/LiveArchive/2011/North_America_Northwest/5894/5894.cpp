#include <iostream>
using namespace std;

int arr[30];
int arr_next[30];

int main() {
	string fiz = "*fizzle*";
	string bun = "*bunny*";

	int N,M;
	while(cin>>N) {
		while(N--) {
			cin>>M;
			for(int i=M-1; i >= 0; i--)
				cin>>arr[i];

			
			int numElm = M;
			int  cycle = 0;
			bool isConverged = false;
			while(numElm > 0) {
				bool isGood = true;

				for(int i=0; i < numElm; i++)
					if(isGood) isGood = arr[i] == 0;

				if(isGood) {
					isConverged = true;
					break;
				}

				for(int i=0; i < numElm-1; i++)
					arr_next[i] = arr[i] - arr[i+1];
				for(int i=0; i < numElm-1; i++)
					arr[i] = arr_next[i];

				numElm--;
				cycle++;
			}

			if(isConverged) {
				for(int i=0; i < cycle; i++)
					cout<<"z";
				cout<<"ap!"<<endl;
			} else {
				if(arr[0] > 0) cout<<fiz<<endl;
				else cout<<bun<<endl;
			}
		}
	}

	return 0;
}