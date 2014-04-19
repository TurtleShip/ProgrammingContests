#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000;
int arr[MAXN+10];
bool isUsed[8];
typedef long long ll;
int getSz(ll a) {
	int ct = 0;
	while(a > 0) {
		ct++;
		a /= 10ll;
	}
	return ct;
}

bool isMatch(ll a, ll b, ll x) {
	stringstream ss1,ss2,ss3;
	string as,bs,xs;
	ss1<<a; ss1>>as;
	ss2<<b; ss2>>bs;
	ss3<<x; ss3>>xs;
	bool isOkay = true;
	for(int i=0; i < xs.size(); i++)
		isUsed[i] = false;

	for(int i=0; i < as.size(); i++) {
		bool isFound = false;
		
		for(int j=0; j < xs.size(); j++) {
			if(!isUsed[j] && as[i] == xs[j]) {
				isUsed[j] = true;
				isFound = true;
				break;
			}
		}
		if(!isFound) {
			isOkay = false;
			break;
		}
	}

	if(isOkay) {
		for(int i=0; i < bs.size(); i++) {
		bool isFound = false;
			for(int j=0; j < xs.size(); j++) {
				if(!isUsed[j] && bs[i] == xs[j]) {
					isUsed[j] = true;
					isFound = true;
					break;
				}
			}
			if(!isFound) {
				isOkay = false;
				break;
			}
		}
	}
	return isOkay;
}

void preprocess() {
	ll minRes = 1234768ll;
	for(int i=10; i <= MAXN; i++) {
		arr[i] = -1;
	}
	for(int i=1; i <= MAXN; i++) {
		
		for(int j=1; j <= MAXN; j++) {
			int cur = i * j;
			if(cur > MAXN) {
				break;
			}

			if(getSz(cur) == (getSz(i) + getSz(j))) {

				if(isMatch(i,j,cur)) {
					if(arr[cur] != -1)
						cout<<"arr["<<cur<<"] = "<<cur<<";"<<endl;
					arr[cur] = cur;
				}
			}


		}
	}
	arr[MAXN] = 1000255;
}


int main() {
	preprocess();
	
	return 0;
}

