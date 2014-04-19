#include <iostream>
using namespace std;

typedef long long ll;

const int maxN = 1000000;
int isVisited[110];
ll F[maxN+1];
ll cycleLen = 300ll;
ll cycleSum = 0ll;
ll S[310];

// used to detect a cycle
void detectCycle() {
	// try to detect cycle first
	F[0] = 1ll;
	F[1] = 1ll;
	F[2] = 1ll;
	for(int i=0; i <= 100; i++) 
		isVisited[i] = -1;

	for(int i=3; i <= maxN; i++)
		F[i] = (F[i-1] + F[i-2]) % 100;

	isVisited[1] = 1;

	int st = -1;
	int end = -1;
	int len = -1;

	bool isCycle = false;


	for(int i=3; i <= maxN; i++) {
		
		if(isVisited[F[i]] != -1) {

			len = i - isVisited[F[i]];
			if(i + len > maxN) break;
			isCycle = true;
			for(int j=i+1; j < i+len; j++) {
				if(isVisited[F[j]] == -1) {
					isCycle = false;
					break;
				}
				if(F[j] != F[j - len]) {
					isCycle = false;
					break;
				}
			}
			if(isCycle) {
				st = i;
				end = st + len;
				break;
			}
			if(i == 301)
				break;
		} else {
			isVisited[F[i]] = i;
		}
		
		

	}
	cout<<"st : "<<st<<endl;
	cout<<"end : "<<end<<endl;
	cout<<"len : "<<len<<endl;
}


void preprocess() {
	F[1] = F[2] = 1ll;
	S[1] = 1ll;
	S[2] = 2ll;
	
	for(int i=3; i <= 300; i++) {
		F[i] = (F[i-1] + F[i-2]) % 100;
		S[i] = S[i-1] + F[i];
	}

	cycleSum = S[300];
}

ll getSum(ll num) {
	ll res = ( num / cycleLen ) * cycleSum;
	res += S[num % cycleLen];
	return res;
}

int main()
{
	// detectCycle();
	preprocess();
	int C;
	ll N,M;
	cin>>C;

	while(C--) {
		cin>>N>>M;
		ll res = getSum(M) - getSum(N-1);
		cout<<res<<endl;
	}


    return 0;

}