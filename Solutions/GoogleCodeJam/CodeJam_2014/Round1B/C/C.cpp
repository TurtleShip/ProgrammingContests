#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

#define pb(x) push_back(x)
#define all(v) (v).begin(), (v).end()

bool canGo(const vector< vector<bool> >&, const vector<bool>&, stack<int>, const int&, const int&, const int&);
bool canFillAll(const vector< vector<bool> >&, const vector<bool>&, stack<int>, const int&, const int&);

int main() {
	int T, N, M;
	cin>>T;

	for(int cid=1; cid <= T; cid++) {
		cin>>N>>M;

		vector< vector<bool> >isCon(N, vector<bool>(N, false));
		vector<string> zipcode(N);

		for(int i=0; i < N; i++) {
			cin>>zipcode[i];
		}

		for(int i=0; i < M; i++) {
			int from, to;
			cin>>from>>to;
			from--; to--;
			isCon[from][to] = isCon[to][from] = true;
		}

		vector< pair<string, int> > rootCandidates(N);
		for(int i=0; i < N; i++) {
			rootCandidates[i] = make_pair(zipcode[i], i);
		}

		sort( all(rootCandidates) );
		int root = rootCandidates[0].second;

		vector<int> res;
		vector<bool> isVisited(N, false);
		stack<int> returnPath;
		set<int> seenCities;

		res.pb(root);
		isVisited[root] = true;
		
		int curCity = root;
		while(res.size() != N) {
			
			// add nearby cities
			for(int i=0; i < N; i++) {
				if(isCon[curCity][i] && !isVisited[i]) {
					seenCities.insert(i);
				}
			}
			
			int nextCity = -1;
			for(int i=0; nextCity == -1 && i < N; i++) {
				// next city must not have been visited before and 
				// should've been seen from one of visited we visited already
				int possibleCity = rootCandidates[i].second;

				if(isVisited[possibleCity] || seenCities.count(possibleCity) == 0) continue;
				if(canGo(isCon, isVisited, returnPath, curCity, possibleCity, N)) nextCity = possibleCity;
				
			}

			// move to the next city
			while(!isCon[curCity][nextCity]) {
				int prevCity = returnPath.top(); returnPath.pop();
				isCon[curCity][prevCity] = isCon[prevCity][curCity] = false;
				curCity = prevCity;
			}

			returnPath.push(curCity);
			res.pb(nextCity);
			isVisited[nextCity] = true;
			curCity = nextCity;
		}

		// print result
		cout<<"Case #"<<cid<<": ";
		for(int i=0; i < N; i++) {
			cout<<zipcode[res[i]];
		}
		cout<<endl;
	}

	return 0;
}

bool canGo(const vector< vector<bool> >& isCon, const vector<bool>& isUnreachable,
		   stack<int> returnPath, const int& curCity, const int& nextCity, const int& N) {
	int parentCity = curCity;
	
	while(!isCon[parentCity][nextCity] && !returnPath.empty()) {
		parentCity = returnPath.top(); returnPath.pop();
	}

	return isCon[parentCity][nextCity] 
			&& canFillAll(isCon, isUnreachable, returnPath, parentCity, N);
}

// we should be able to flood-fill all vertices if next city results in a valid path.
bool canFillAll(const vector< vector<bool > >& isCon, const vector<bool>& isUnreachable,
		stack<int> returnPath, const int& parentCity, const int& N) {

	queue<int> Q;
	Q.push(parentCity);
	while(!returnPath.empty()) {
		Q.push(returnPath.top()); returnPath.pop();
	}
	vector<bool> isVisited(N, false);

	while(!Q.empty()) {
		int curCity = Q.front(); Q.pop();

		for(int i=0; i < N; i++) {
			if(isUnreachable[i] || isVisited[i] || !isCon[curCity][i]) continue;
			isVisited[i] = true;
			Q.push(i);
		}
	}

	bool isAllFilled = true;
	for(int i=0; isAllFilled && i < N; i++) {
		isAllFilled &= isUnreachable[i] || isVisited[i];
	}

	return isAllFilled;
}