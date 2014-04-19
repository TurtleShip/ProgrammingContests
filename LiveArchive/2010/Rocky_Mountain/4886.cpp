#include <iostream>
using namespace std;

#define MAXN 1010
bool arr[MAXN];

int main() {
	int N;
	string in;
	

	while(cin>>N && N != 0) {
		
		for(int i=1; i <= N; i++)
			arr[i] = false;
		cin>>in;
		int low, high;
		int st = 0, end, dash, tmp;
		int K = in.size();

		while(st < K) {
			end = st+1;
			while(end < K && in[end] != ',')
				end++;
			
			dash = st+1;
			while(dash < end && in[dash] != '-')
				dash++;
			
			bool hasDash = dash < end;

			if(hasDash) {
				low = 0, high =0;
				
				for(int i=st; i < dash; i++) {
					low = low * 10 + (in[i] - '0');
				}
				for(int i=dash+1; i < end; i++) {
					high = high * 10 + (in[i] - '0');
				}
				for(int i=low; i <= min(high,N); i++) {
					arr[i] = true;
				}

			} else {
				low = 0;
				for(int i=st; i < end; i++)
					low = low * 10 + (in[i] - '0');
				arr[low] = true;

			}
			st = end+1;
			
			
		}
		int res = 0;
		for(int i=1; i <= N; i++)
			if(arr[i])
				res++;
		cout<<res<<endl;


	}
	return 0;
}