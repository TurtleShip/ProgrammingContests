#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN 25
#define MAXM 1010
#define MAXU 15

string name[MAXN];
int pt[MAXN];
int first_team[15];
int second_team[15];
int high[MAXN];
int low[MAXN];
int sorted[MAXN]; // sorted[i] = (i)th ranker
int N;
int M;
int U; // number of unplayed games
map<string, int> E; //name map

bool sort_score(int i, int j) {
	return pt[i] >= pt[j];
}

void update_rank() {
	for(int i=0; i < N; i++) {
			sorted[i] = i;
	}
	sort(sorted, sorted+N, sort_score);
	
	int idx = 0, same, ranker, cur_score;
	
	while(idx < N) {

		int same = idx+1;
		cur_score = pt[sorted[idx]];

		while(same < N && pt[sorted[same]] == cur_score) {
			same++;
		}
		
		for(int i = idx; i < same; i++) {
			ranker = sorted[i];
			high[ranker] = min(high[ranker], idx+1);
			low[ranker] = max(low[ranker], idx+1);
		}
		idx = same;

	}
	
}
void solve(int idx) {
	if(idx == U) {
		// we reached the end of simulation
		update_rank();
		return;
	}
	
	int team_0 = first_team[idx];
	int team_1 = second_team[idx];

	// draw
	pt[team_0]++; pt[team_1]++;
	solve(idx+1);
	pt[team_0]--; pt[team_1]--;

	// first team wins
	pt[team_0] += 3;
	solve(idx+1);
	pt[team_0] -= 3;

	// second_team wins
	pt[team_1] += 3;
	solve(idx+1);
	pt[team_1] -= 3;
}

string getPrefix(int n) {
	if(n == 1) return "st";
	if(n == 2) return "nd";
	if(n == 3) return "rd";
	return "th";
}


int main() {
	bool isFrist = true;
	while(cin>>N>>M && (N+M) != 0) {
		if(isFrist) isFrist = false;
		else cout<<endl;
		
		E.clear();
		U = 0;

		for(int i=0; i < N; i++) {
			cin>>name[i];
			pt[i] = 0;
			E[name[i]] = i;
			high[i] = N+1;
			low[i] = -1;
		}
		string nm_0, nm_1, tmp;
		int sc_0, sc_1, idx_0, idx_1;

		for(int i=0; i < M; i++) {
			cin>>nm_0>>tmp>>nm_1>>sc_0>>sc_1;

			// find the index of the team
			idx_0 = E[nm_0];
			idx_1 = E[nm_1.substr(0, nm_1.size() -1)];
			
			if(sc_0 == -1 && sc_1 == -1) {
				first_team[U] = idx_0;
				second_team[U] = idx_1;
				U++;
			} else {
				if(sc_0 == sc_1) {
					pt[idx_0] += 1;
					pt[idx_1] += 1;
				} else if(sc_0 > sc_1) {
					pt[idx_0] += 3;
				} else {
					pt[idx_1] += 3;
				}
			}
		}

		solve(0);
		string prefix;
		for(int i=0; i < N; i++) {
			cout<<"Team "<<name[i]<<" can finish as high as "<<high[i]<<getPrefix(high[i])<<" place and as low as "<<low[i]<<getPrefix(low[i])<<" place."<<endl;

		}
	}


}