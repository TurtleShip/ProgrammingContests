#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;
typedef vector<p2> vp2;

#define INF 2147483648LL

int N, P, M;
int X[200], V[200];
ll Ans[11000];
ll Best[11000];
vector<vp2> Edges;

void dijkstra(int start, ll v) {
  int i;
  fr (i, N) Best[i] = INF;
  Best[start] = 0;
  set<pair<ll, int> > Set;
  Set.insert(MP(Best[start], start));

  while (SZ(Set)) {
    int x = Set.begin()->S;
    Set.erase(Set.begin());

    fr (i, SZ(Edges[x])) {
      ll cost = Edges[x][i].S + Best[x];
      if (cost >= INF) continue;
      if (Best[Edges[x][i].F] > cost) {
        if (Best[Edges[x][i].F] < INF) {
          Set.erase(MP(Best[Edges[x][i].F], Edges[x][i].F));
        }
        Best[Edges[x][i].F] = cost;
        Set.insert(MP(Best[Edges[x][i].F], Edges[x][i].F));
      }
    }
  }

  fr (i, N) Ans[i] = max(Ans[i], min(v * Best[i], INF));
}

int main() {
  int total_cases, case_num = 0;
  scanf("%d", &total_cases);

  int i, j, d, l, x, bef;
  while (case_num < total_cases) {
    scanf("%d%d%d", &N, &P, &M);
    case_num++;
    fr (i, P) {
      scanf("%d%d", &X[i], &V[i]);
      X[i]--;
    }

    Edges = vector<vp2>(N, vp2());
    fr (i, M) {
      scanf("%d%d", &d, &l);
      bef = -1;
      fr (j, l) {
        scanf("%d", &x);
        x--;
        if (bef != -1) {
          Edges[bef].pb(MP(x, d));
          Edges[x].pb(MP(bef, d));
        }
        bef = x;
      }
    }
    memset(Ans, 0, sizeof(Ans));
    fr (i, P) dijkstra(X[i], V[i]);
    ll ans = INF;
    fr (i, N) ans = min(Ans[i], ans);

    if (ans == INF) ans = -1;
    cout << "Case #" << case_num << ": " << ans << endl;
  }
  return 0;
}
