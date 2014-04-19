#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	int N,M,P, shot, height;
	string name;
	cin>>T;
	for(int cid=1; cid <= T; cid++) {
		cin>>N>>M>>P;
		// < shot perc., height, name >
		vector< pair<int, pair<int, string> > >V(N); // all players
		vector< pair<int, pair<int, string> > >A; // first team
		vector< pair<int, pair<int, string> > >B; // second team

		for(int i=0; i < N; i++) {
			cin>>name>>shot>>height;
			V[i] = make_pair( shot, make_pair( height, name) );
		}
		sort(V.rbegin(), V.rend()); // sort in descending order
		for(int i=0; i < N; i++) {
			if(i%2 == 0) A.push_back(V[i]);
			else B.push_back(V[i]);
		}

		// M is small enough to simulate the game

		// < total time played, draft number, name >
		vector< pair<int, pair<int, string> > > A_play(P);	
		vector< pair<int, pair<int, string> > > B_play(P);
		vector< pair<int, pair<int, string> > > A_ben(A.size() - P);
		vector< pair<int, pair<int, string> > > B_ben(B.size() - P);

		for(int i=0; i < P; i++) {
			A_play[i] = make_pair( 0, make_pair(i, A[i].second.second));
			B_play[i] = make_pair( 0, make_pair(i, B[i].second.second));
		}
		for(int i=0; i < A_ben.size(); i++)
			A_ben[i] = make_pair( 0, make_pair(i+P, A[i+P].second.second));
		for(int i=0; i < B_ben.size(); i++)
			B_ben[i] = make_pair( 0, make_pair(i+P, B[i+P].second.second));

		int m = 1;
		while(M--) {
			for(int i=0; i < P; i++) {
				A_play[i].first++;
				B_play[i].first++;
			}
			if(A_ben.size() > 0) {
				sort(A_play.begin(), A_play.end());
				sort(A_ben.begin(), A_ben.end());
				swap(A_play[A_play.size()-1], A_ben[0]);
			}
			if(B_ben.size() > 0) {
				sort(B_play.begin(), B_play.end());
				sort(B_ben.begin(), B_ben.end());
				swap(B_play[A_play.size()-1], B_ben[0]);
			}
		}

		vector<string> res(2*P);
		for(int i=0; i < P; i++) {
			res[2*i] = A_play[i].second.second;
			res[2*i+1] = B_play[i].second.second;
		}
		sort(res.begin(), res.end());

		cout<<"Case #"<<cid<<":";
		for(int i=0; i < res.size(); i++)
			cout<<" "<<res[i];
		cout<<endl;
	}

	return 0;
}