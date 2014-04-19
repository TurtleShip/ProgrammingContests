#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define N 100005
#define M 200005
using namespace std;

struct edge{
	int x, y, w, r;
	bool operator < (edge const &T) const{return w < T.w;}
};

edge a[M];
int n, m, x, y, t, lbl, ed;
int l[N], p[N], pr[N], fr[N], v[N], w[N];
int com[M], type[M], qd[M], qn[M], ql[M];

int find(int x){
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void bd(int x, int y, int lbl){
	qd[++ed] = y, qn[ed] = l[x], ql[ed] = lbl, l[x] = ed;
}

void dfs(int x, int y){
	v[x] = w[x] = ++t;
	for (int i=l[x]; i; i=qn[i]){
		if (!v[qd[i]]){
			dfs(qd[i], x);
			w[x] = min(w[x], w[qd[i]]);
			pr[qd[i]] = x;
			fr[qd[i]] = 1;
		}
		else if (pr[qd[i]] == x) fr[qd[i]]++;
		else if (qd[i] != y) w[x] = min(w[x], v[qd[i]]);
	}
    
	// classify
	for (int i=l[x]; i; i=qn[i]){
		if (pr[qd[i]] != x) continue;
		if (fr[qd[i]] == 1 && w[qd[i]] > v[x]) type[ql[i]] = 1;
	}
}

//code of GAGGUY

int main(){
	scanf("%d%d", &n, &m);
	FOR(i,0,m) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].w), a[i].r = i;
	FOE(i,1,n) p[i] = i;
	sort(a, a + m); //sort edges in ascending order
	
	for (int i=0, j; i<m; i=j){
		j = i;
		ed = 0;//index
        //go through all edges with the same weight
		while (j < m && a[j].w == a[i].w){
			x = find(a[j].x); //A tree where a[j].x belongs 
			y = find(a[j].y); //A tree where a[j].y belongs
			lbl = a[j].r; //original index of the current edge
            /*
             Nodes connected by the current edge belong to the same tree.
             i.e. create a cycle
             */
			if (x == y){ 
				type[lbl] = 0; //none
				com[j] = -1; 
			}
			else{
				bd(x, y, lbl);
				bd(y, x, lbl);
				type[lbl] = 2; //any or at least one 
				com[j] = x;
			}
			j++;
		}
		
		for (int k=i; k<j; k++){
			if (com[k] != -1 && !v[com[k]]) t = 0, dfs(com[k], -1);
		}
        
		for (int k=i; k<j; k++){
			x = find(a[k].x);
			y = find(a[k].y);
			l[x] = l[y] = v[x] = v[y] = 0;
			p[x] = y;
		}
	}
	
	FOR(i,0,m){
		if (!type[i]) puts("none");
		else if (type[i] == 1) puts("any");
		else puts("at least one");
	}
	return 0;
}