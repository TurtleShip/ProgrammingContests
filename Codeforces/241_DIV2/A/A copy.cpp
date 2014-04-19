#include <iostream>
#include <vector>
using namespace std;

int GREATER_THAN = 0; // >
int LESS_THAN = 1; // <
int GREATER_THAN_OR_EQUAL_TO = 2; // >=
int LESS_THAN_OR_EQUAL_TO = 3; //  <=

vector< pair<int, int> > V;

bool shouldBeSmaller;

bool isGood(int Y) {
	bool pass = true;

	for(int i=0; pass && i < V.size(); i++) {
		int eq = V[i].first;
		int X = V[i].second;
		if(eq == GREATER_THAN) {
			// printf("%d > %d\n", Y, X);
			pass = Y > X;
			if(!pass) shouldBeSmaller = false;
		}
		else if(eq == LESS_THAN) {
			// printf("%d < %d\n", Y, X);
			pass = Y < X;
			if(!pass) shouldBeSmaller = true;
		}
		else if(eq == GREATER_THAN_OR_EQUAL_TO) {
			// printf("%d >= %d\n", Y, X);
			pass = Y >= X;
			if(!pass) shouldBeSmaller = false;
		}
		else {
			// printf("%d <= %d\n", Y, X);
			pass = Y <= X;
			if(!pass) shouldBeSmaller = true;
		}
	}

	return pass;
}

int main() {
	int N, num, actualEq;
	cin>>N;
	string eq, ans;
	
	for(int i=0; i < N; i++) {
		cin>>eq>>num>>ans;


		if(eq == ">") {
			if(ans == "Y") actualEq = GREATER_THAN;
			else actualEq = LESS_THAN_OR_EQUAL_TO;
		} else if( eq == "<") {
			if(ans == "Y") actualEq = LESS_THAN;
			else actualEq = GREATER_THAN_OR_EQUAL_TO;
		} else if( eq == ">=" ) {
			if(ans == "Y") actualEq = GREATER_THAN_OR_EQUAL_TO;
			else actualEq = LESS_THAN;
		} else { // eq == "<="
			if(ans == "Y") actualEq = LESS_THAN_OR_EQUAL_TO;
			else actualEq = GREATER_THAN;
		}

		V.push_back( make_pair(actualEq, num) );
	}

	int low = -2000000000;
	int high = 2000000000;
	int prev = low;
	int mid;
	while(low < high) {
		mid = (low + high) / 2;
		if(prev == mid) break;
		prev = mid;
		if(isGood(mid)) break;
		if(shouldBeSmaller) high = mid;
		else low = mid;
	}
	if(!isGood(mid)) cout<<"Impossible"<<endl;
	else cout<<mid<<endl;

	return 0;
}