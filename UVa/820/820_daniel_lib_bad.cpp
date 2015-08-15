#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
#define PRINT(x...) TRACE(printf(x))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define _for(i, a, b) for (__typeof__(a) i = (a); i != (b); ++i)
#define foreach(x...) _for(x)
#define forall(i, v) foreach(i, all(v))
#define FU(i, a, b) for(typeof(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define mset(c, v) memset(c, v, sizeof(c))
#define mod(a, b) ((((a)%(b))+(b))%(b))
#define pb push_back
#define sz(c) int((c).size())
const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const int NULO = -1; const double EPS = 1e-8;

int cmp(double x, double y = 0, double tol = EPS) {
        return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define vi vector<int>
#define vvi vector<vi>
struct graph {

  vi dest;  // use sz(dest) as nar
  vvi adj;  // use sz(adj) as sz(adj)
  vi cap, flow;
  int _ini, _end;   // ini, end of last maxflow
  vi d, curAdj;


  int inv(int a) { return a ^ 0x1; }

  graph(int n = 0) {
    adj.resize(n);
    // imb.resize(n);
  }

  // Adds an arc to the graph. u is capacity, c is cost.
  // u is only needed on flows, and c only on min-cost-flow
  int arc(int i, int j, int u = 0, double c = 0) {
  	// printf("i = %d, j = %d\n", i, j);
    dest.pb(j);
    adj[i].pb(sz(dest)-1);
    dest.pb(i);
    adj[j].pb(sz(dest)-1);

    // For both flows
    cap.pb(u);
    cap.pb(0);
    // Only for min cost flow
    // cost.pb(c);
    // cost.pb(-c);
    // printf("done\n\n");
    return sz(dest)-2;
  }

  int orig(int a) { return dest[inv(a)]; }
  int capres(int a) { return cap[a] - flow[a]; }

  //////////////////////////////////////////////////////////////////////////////
  // Max Flow! - Dinic O(n^2 * m) incremental
  // don't call maxflow with ini == end
  //

  bool MFbfs(int s, int t) {
    d = vi(sz(adj), INF);
    curAdj = vi(sz(adj));
    d[s] = 0;
    queue<int> Q; Q.push(s);
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      forall(i, adj[u]) {
        int v = dest[*i];
        if (capres(*i) > 0 && d[v] == INF) {
          d[v] = d[u] + 1; Q.push(v);
        }
      }
    }
    return d[t] != INF;
  }

  int MFdfs(int u, int t, int f) {
    if (u == t) return f;
    for(int &i = curAdj[u]; i < adj[u].size(); ++i) {
      int ar = adj[u][i], v = dest[ar];
      if (d[v] != d[u]+1 || capres(ar) == 0) continue;
      int tmpF = MFdfs(v, t, min(f, capres(ar)));
      if (tmpF) {
        flow[ar] += tmpF;
        flow[inv(ar)] -= tmpF;
        return tmpF;
      }
    }
    return 0;
  }

  int maxflow(int ini, int end) {
  	cout<<"FLow enter"<<endl;
    if (_ini != ini || _end != end) {
      flow = vi(sz(dest));
      _ini = ini;
      _end = end;
    }
    while (MFbfs(ini, end))
      while (MFdfs(ini, end, INF));
  	cout<<"Done looping"<<endl;
    int F = 0;
    forall(a, adj[ini]) F += flow[*a];
    return F;
  }
};

int main() {
	int N,s,t,C,cid = 1;
	bool isFirst = true;
	while(cin>>N) {
		graph G = graph(N);
		cin>>s>>t>>C;

		// read the input using AddEdge()
		while(C--) {
			int from, to; long cap;
			cin>>from>>to>>cap;
			G.arc(from-1,to-1,cap);
		}
		cout<<"Done adding edge"<<endl;

		long res = G.maxflow(s,t);
		if(isFirst) isFirst = false;
		else cout<<endl;
		cout<<"Network "<<cid++<<endl;
		cout<<"The bandwidth is "<<res<<endl;
	}
	return 0;
}