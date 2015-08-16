#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) (v).begin(), (v).end()
#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

// Given vector V, return all cycles in V.  Complexity : O(N) where N = V.size()
vector< vector<int> > findCycles(const vector<int>& V) {
	int N = V.size();
	vector< vector<int> > cycles;
	vector<bool> visited(N, false);

	for(int i=0; i < N; i++) {
		if(visited[V[i]]) continue;
		
		vector<int> curCycle;
		int cur = V[i];

		while(!visited[cur]) {
			visited[cur] = true;
			curCycle.pb(cur);
			cur = V[cur];
		}
		cycles.pb(curCycle);
	}

	return cycles;
}

// Given cycles, return the lexiographically smallest swap that will join two cycles
pair<int,int> joinCycle(vector< vector<int> >& cycles) {
	int N = cycles.size();
	vector<int> candidates(N);
	for(int i=0; i < N; i++) {
		candidates[i] = *min_element(all(cycles[i]));
	}
	sort(all(candidates));
	return mp(candidates[0], candidates[1]);
}

// Given cylces, return the lexiographically smallest swap that will separate 
// one cycle into two cycles
pair<int,int> separateCycle(vector< vector<int> >& cycles) {
	int N = cycles.size();
	vector< pair<int,int> >candidates;
	for(int i=0; i < N; i++) {
		if(cycles[i].size() == 1) continue;
		sort(all(cycles[i]));
		candidates.pb(mp(cycles[i][0], cycles[i][1]));
	}
	sort(all(candidates));
	return candidates[0];
}

int main() {
	int N, M;
	cin>>N;
	vector<int> V(N);
	for(int i=0; i < N; i++) {
		cin>>V[i];
		// decrease elements by 1 to make them consistent for 0-based index.
		V[i]--;
	}

	cin>>M;

	/*
		If vector V of size N is an identity, then it should have N cycles.
		Let C = number of cycles that V has.
		Then the number of swaps that we need to turn V into an indentity matrix
		is numSwaps = N - C

		Key facts are
		1) If you swap two elements within the same cycle, then C, the total number of
		cycles in V, increases by 1.
			For example, let's looks at V = 4 2 1 3 5 6
			Then we have 3 cycles (4 -> 3 -> 1 -> 2) , (5), (6)
			If we swap any elements within (4,3,1,2), then we end up having one more cycle.
			4,3,1,2 ==(swap 4 and 3)==> 3,4,1,2 => (3->1) (4->2)
			4,3,1,2 ==(swap 4 and 1)==> 1,3,4,2 => (1) (3->2->4)
			4,3,1,2 ==(swap 4 and 2)==> 2,3,1,4 => (2->3->1) (4)
			4,3,1,2 ==(swap 3 and 1)==> 4,1,3,2 => (4->2->1) (3)
			4,3,1,2 ==(swap 3 and 2)==> 4,2,1,3 => (4->3->1) (2)
			4,3,1,2 ==(swap 1 and 2)==> 4,3,2,1 => (4->1) (2->3)
		
		2) If you swap two elements from different cycles, then C, the total number of
		cycles in V, decreases by 1.

		So in order to create a permutation Q such that f(Q) = M, we need 
		numSwaps = M = N - C
		In other words, we want to have C = N - M cylcles.

		So we keep increasing/decreasing the number of cycles in V using the fact 1) and 2)
		until V has C number of cycles. While we change the number of cycles, we look at all
		possible options, and make a swap then involves the smallest elements.
	*/

	int C = N - M;

	vector< vector<int> >cycles = findCycles(V);
	vector< pair<int,int> > res;

	while(cycles.size() != C) {
		pair<int,int> curSwap = (cycles.size() < C) ? separateCycle(cycles) : joinCycle(cycles);
		res.pb(mp(curSwap.first,curSwap.second));
		// Note that x1,x2,x3,, in swap swquence,  x = index  not an element ;-)
		swap(V[curSwap.first], V[curSwap.second]);
		cycles = findCycles(V);
	}	


	// output elements after increasing by 1.
	cout<<res.size()<<endl;
	for(auto p : res)
		cout<<(p.first+1)<<" "<<(p.second+1)<<" ";
	cout<<endl;

	return 0;
}
