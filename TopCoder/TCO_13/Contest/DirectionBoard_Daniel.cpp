#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;
 
#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
#define _FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define foreach(x...) _FOR(x)
#define fu(i, a) foreach(i, 0, a)
#define forall(i, v) foreach(i, all(v))
 
#define MSET(c, v) memset(c, v, sizeof(c)
 
#define rep(i, n) FOR(i,0,n)
#define pb push_back
#define sz(c) int((c).size())
 
const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const int NULO = -1; const double EPS = 1e-10;
 
inline int cmp(double x, double y = 0, double tol = EPS) {
        return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
 
const int VT = 15*15*2 + 10; // Max number of vertices
 
struct graph {
 
        //////////////////////////////////////////////////////////////////////////////
        // Shared part. Also known as: You will need this!
        //
 
        vector<int> dest;
        vector<int> adj[VT];
        int nvt, nar;
 
        int inv(int a) { return a ^ 0x1; }
 
 
        // Initializes the graph
        void init(int n) {
                nvt = n;
                nar = 0;
                fu(i, VT) adj[i].clear();
                memset(imb, 0, sizeof(imb)); // Only for min-cost-flow
                dest.clear(); cap.clear(); flow.clear(); cost.clear();
        }
       
        // Adds an arc to the graph. u is capacity, c is cost.
        // u is only needed on flows, and c only on min-cost-flow
        // Returns an identifier to the edge.
        int arc(int i, int j, int u = 0, double c = 0) {
                int ar = nar;
                cost.pb(c);
                cap.pb(u);
                dest.pb(j);
                adj[i].pb(nar++);
 
                cost.pb(-c);
                cap.pb(0);
                dest.pb(i);
                adj[j].pb(nar++);
                return ar;
        }
 
        //////////////////////////////////////////////////////////////////////////////
        // For both flows!!
        //
 
        vector<int> cap, flow;
        int ent[VT];
 
        int orig(int a) { return dest[inv(a)]; }
        int capres(int a) { return cap[a] - flow[a]; }
 
 
        //////////////////////////////////////////////////////////////////////////////
        // Min Cost Flow! - O(m^2 * log n * log U)
        //
        // Don't forget to specify the imb
 
        int imb[VT], mark[VT], delta;
        double pot[VT], dist[VT];
        vector<double> cost;
 
        double rescost(int a) {
                return cost[a] - pot[orig(a)] + pot[dest[a]];
        }
 
        void MCFdijkstra(int ini) {
                int i, j, a;
                double d;
 
                priority_queue<pair<double, int> > heap;
                memset(ent, -1, sizeof(ent));
                memset(mark, 0, sizeof(mark));
 
                fu(i, nvt) dist[i] = INFINITY;
                heap.push(make_pair(dist[ini] = 0.0, ini));
 
                while (!heap.empty()) {
                        i = heap.top().second; heap.pop();
                        if (mark[i]) continue; mark[i] = 1;
                        forall(k, adj[i]) {
                                a = *k; j = dest[a]; d = dist[i] + rescost(a);
                                if (capres(a) >= delta && cmp(d, dist[j]) < 0) {
                                        heap.push(make_pair( -(dist[j] = d), j));
                                        ent[j] = a;
                                }
                        }
                }
        }
 
 
        double mincostflow() {
                int k, l, U = 0;
                double C = 0.;
 
                memset(pot, 0, sizeof(pot));
 
                fu(a, nar) {
                        if (cmp(cost[a]) > 0) C += cost[a];
                        U = max(cap[a], U);
                }
                fu(i, nvt) U = max(imb[i], max(-imb[i], U));
                for (delta = 0x40000000; delta > U; delta /= 2);
 
                imb[nvt] = 0 ; U *= 2 * nvt; C *= 2; adj[nvt].clear();
                fu(i, nvt) {
                        arc(i, nvt, U, C);
                        arc(nvt, i, U, C);
                }
 
                flow.clear();
                fu(i, nar) flow.pb(0);
                nvt++;
 
                while (delta >= 1) {
                        fu(a, nar) {
                                int i = orig(a), j = dest[a];
                                if (delta <= capres(a) && capres(a) < 2 * delta &&
                                    cmp(rescost(a)) < 0) {
                                        flow[inv(a)] -= capres(a);
                                        imb[i] -= capres(a); imb[j] += capres(a);
                                        flow[a] = cap[a];
                                }
                        }
 
                        while (true) {
                                for (k = 0 ; k < nvt && imb[k] < delta; k++);
                                for (l = nvt - 1 ; l >= 0 && imb[l] > -delta; l--);
                                if (k == nvt || l < 0) break;
 
                                MCFdijkstra(k);
                                fu(i, nvt) pot[i] -= dist[i];
                                for (int a = ent[l]; a != -1; a = ent[orig(a)])  {
                                        flow[a] += delta; flow[inv(a)] -= delta;
                                }
                                imb[k] -= delta; imb[l] += delta;
                        }
                        delta /= 2;
                }
 
                C = 0.;
                fu(a, nar) if (flow[a] > 0) C += flow[a] * cost[a];
                return C;
        }
 
 
} G;
 
class DirectionBoard {
        public:
        int getMinimum(vector <string> board) {
                int N = board.size();
                int M = board[0].size();
               
                G.init(2*N*M);
                fu(i, N*M) G.imb[i] = 1;
                fu(i, N*M) G.imb[N*M + i] = -1;
               
                fu(i, N) fu(j, M) {
                        int a = i*M + j;
                        int ii, jj;
                        // top
                        ii = (i+N-1)%N;
                        jj = j;
                        G.arc(a, N*M + ii*M + jj, 1, (board[i][j] == 'U')?0:1);
                        // bottom
                        ii = (i+1)%N;
                        jj = j;
                        G.arc(a, N*M + ii*M + jj, 1, (board[i][j] == 'D')?0:1);
                        // left
                        ii = i;
                        jj = (j+M-1)%M;
                        G.arc(a, N*M + ii*M + jj, 1, (board[i][j] == 'L')?0:1);
                        // right
                        ii = i;
                        jj = (j+1)%M;
                        G.arc(a, N*M + ii*M + jj, 1, (board[i][j] == 'R')?0:1);
                }
                return (int)G.mincostflow();
        }
};