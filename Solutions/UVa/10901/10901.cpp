#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) (v).begin(), (v).end()

void moveToOtherSize(vector< pair<int,int> >&, int&, 
					vector< pair<int, int> >&, int&, 
					int&, const int&, const int&, vector< pair<int,int> >& res);

int main() {
	int C;
	bool isFirst = true;
	cin>>C;

	while(C--) {
		// empty lines between each test cases
		if(isFirst) isFirst = false;
		else cout<<endl;

		int N, T, M;
		cin>>N>>T>>M;

		vector< pair<int, int> > left, right;
		vector< pair<int, int> > res;
		int curTime = 0, leftIdx = 0, rightIdx = 0;;
		int arrivalTime = -1;
		string side;
		bool isLeft = true;

		// The arrival times for each test case are strictly increasing
		for(int i=0; i < M; i++) {
			cin>>arrivalTime>>side;
			if(side == "left") left.pb( mp(i, arrivalTime) );
			else right.pb( mp(i, arrivalTime) );
		}

		while(leftIdx < left.size() || rightIdx < right.size()) {
			if(isLeft) moveToOtherSize(left, leftIdx, right, rightIdx, curTime, N, T, res);
			else moveToOtherSize(right, rightIdx, left, leftIdx, curTime, N, T, res);
			isLeft = !isLeft;
		}

		// print result
		sort( all(res) );
		for(pair<int,int> cur : res) {
			cout<<cur.second<<endl;
		}
	}
	return 0;
}

void moveToOtherSize(vector< pair<int, int> >& thisSide, int& thisSideIdx,
					 vector< pair<int,int> >& otherSide, int& otherSideIdx,
					 int& curTime, const int& N, const int& T, vector< pair<int,int> >& res) {
	int loaded = 0;
	vector<int> ids;


	// check if we can board any
	while(thisSideIdx < thisSide.size() && thisSide[thisSideIdx].second <= curTime && loaded < N) {
		ids.pb(thisSide[thisSideIdx].first);
		thisSideIdx++;
		loaded++;
	}

	// we need to wait for the first one.
	if(loaded == 0) {
		if(thisSideIdx < thisSide.size()
			&& (otherSideIdx == otherSide.size() 
				|| (thisSide[thisSideIdx].second <= otherSide[otherSideIdx].second))) {
			curTime = thisSide[thisSideIdx].second;
			ids.pb(thisSide[thisSideIdx].first);
			thisSideIdx++;

			// Despite the problem statment, multiple cars can arrive at the same time. Fuck you, the problem setter.
			while(thisSideIdx < thisSide.size() && thisSide[thisSideIdx].second <= curTime && loaded < N) {
				ids.pb(thisSide[thisSideIdx].first);
				thisSideIdx++;
				loaded++;
			}
		} else {
			curTime = max(curTime, otherSide[otherSideIdx].second);
		}
	}

	// move to the other side and unload
	curTime += T;
	for(int id : ids) {
		res.pb( mp(id, curTime) );
	}
}