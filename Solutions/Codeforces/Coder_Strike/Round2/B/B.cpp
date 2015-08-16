#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll; 

bool canHear[20010][20];

int chatCalled[20];
int ignored[20][20010];
int res[20010];
int main() {

	int N,M,K;
	cin>>N>>M>>K;

	int cur;

	for(int eid = 1; eid <= N; eid++) {
		for(int cid = 1; cid <= M; cid++) {
			cin>>cur;
			canHear[eid][cid] = cur == 1;
			ignored[cid][eid] = 0;
		}
		res[eid] = 0;
	}
	for(int cid=1; cid <= M; cid++)
		chatCalled[cid] = 0;


	int sender, chat;
	for(int k=0; k < K; k++) {
		cin>>sender>>chat;
		chatCalled[chat]++;
		ignored[chat][sender]++;
	}

	for(int cid=1; cid <= M; cid++) {
		int numChats = chatCalled[cid];
		if(numChats == 0) continue;
		for(int eid=1; eid <= N; eid++) {
			if(canHear[eid][cid]) {
				res[eid] += numChats - ignored[cid][eid];
				// printf("cid = %d, eid = %d, numChats = %d, ignored = %d\n", cid, eid, numChats, ignored[cid][eid]);
			}
		}
	}

	for(int i=1; i < N; i++)
		cout<<res[i]<<" ";
	cout<<res[N]<<endl;
}



