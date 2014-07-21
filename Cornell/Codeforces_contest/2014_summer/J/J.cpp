#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define mp(x,y) make_pair(x,y)
#define all(V) (V).begin(), (V).end()
typedef long long LL;

int main() {
	int N;
	LL X, tmp, prevX;
	cin>>N>>X;

	vector< pair<LL,int> > V(N); // remember that 1 <= a <= 10^18
	for(int i=0; i < N; i++) {
		cin>>tmp;
		V[i] = mp(-tmp, i);
	}

	if(N == 1) {
		cout<<1<<endl; // duh
	} else {
		int cutoff = N;
		prevX = X;
		sort(all(V));

		for(int i=1; i < N; i++) {
			X += -(V[i].first - V[i-1].first) * LL(i);
			if(X <= 0) {
				cutoff = i;
				break;
			}
			prevX = X;
		}
		
		vector<int> oneOfThese(cutoff);
		for(int i=0; i < cutoff; i++)
			oneOfThese[i] = V[i].second;
		sort(all(oneOfThese));
		int idx = (prevX-1ll) % LL(cutoff); 
		cout<<oneOfThese[idx]+1<<endl;
	}

	return 0;
}