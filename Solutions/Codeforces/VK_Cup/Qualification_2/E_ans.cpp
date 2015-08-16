#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a, x) memset(a, x, sizeof(a))
#define LLD long long int
#define N 100005
using namespace std;

struct box{
	int x, y, r;
	bool operator < (box const &T) const{
		if (x == T.x) return y > T.y;
		return x < T.x;
	}
};

struct group{
	int n, st;
	bool operator < (group const &T) const{return n < T.n;}
};

box a[N];
group b[N];
int n, m, rex, rey, sx, sy, mf[N];
LLD ret, S, mx[N];


int main(){
	scanf("%d", &n);
	FOR(i,0,n) scanf("%d%d", &a[i].x, &a[i].y), a[i].r = i + 1;
	sort(a, a + n);
	
	m = 0;
	FOR(i,0,n){
		if (i && a[i].x == a[i-1].x) continue;
		b[m].st = i;
		for (int j=i; j<n && a[j].x == a[i].x; j++) b[m].n++;
		m++;
	}
	    for(int i=0; i < m; i++)
	    {
	        cout<<i<<": ("<<b[i].st<<" , "<<b[i].n<<")"<<endl;
	    }
	sort(b, b + m);
	

    
	ret = 0;
	FOR(i,0,m){
		S = 0;
		FOR(j,0,b[i].n){
			S += a[j+b[i].st].y;
			FOE(k,j,j+2)
			if (S + mx[k] > ret && mx[k]){
				ret = S + mx[k];
				rex = i, rey = mf[k];
				sx = j + 1, sy = k;
			}
		}
		
		if (S > mx[b[i].n]) mx[b[i].n] = S, mf[b[i].n] = i;
	}
	cout<<ret<<endl;
	//printf("%I64d\n", ret);
	printf("%d\n", sx + sy);
	FOR(i,0,sx){
		printf("%d ", a[b[rex].st+i].r);
		if (i < sy) printf("%d ", a[b[rey].st+i].r);
	}
	puts("");
	return 0;
}