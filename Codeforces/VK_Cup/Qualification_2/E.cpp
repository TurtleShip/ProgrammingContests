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
    /*
     x = color
     y = height
     */
	int x, y, r;
	bool operator < (box const &T) const{
		if (x == T.x) return y > T.y;
		return x < T.x;
	}
};

//group = boxes with same color
struct group{
    /*
     n = number of boxes
     st = start position of boxes
     */
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
    int j;
	for(int i=0; i < n; i=j)
    {
		b[m].st = i;

		for (j=i; j<n && a[j].x == a[i].x; j++) b[m].n++;
		m++;

	}
	    
	sort(b, b + m);

    memset(mx, 0, sizeof(mx));
    memset(mf, 0, sizeof(mf));
    
	ret = 0;
	FOR(i,0,m){
		S = 0; //total heights of current color boxes
		FOR(j,0,b[i].n){
			S += a[j+b[i].st].y; //add the current box
            
            //Try heights less than or equal to the current height (= j+1)
			for(int k=j; k <= j+1; k++)
            {
                if (S + mx[k] > ret && mx[k] != 0)
                {
                    ret = S + mx[k];
                    rex = i, rey = mf[k];
                    sx = j + 1, sy = k;
                }
            }
		}
        
        //mx[i] = maximum height using i boxes
        //mf[i] = starting position of mx[i]
		if (S > mx[b[i].n]) mx[b[i].n] = S, mf[b[i].n] = i;
	}
	
	cout<<ret<<endl;
    cout<<(sx+sy)<<endl;
    
	FOR(i,0,sx){
		printf("%d ", a[b[rex].st+i].r);
		if (i < sy) printf("%d ", a[b[rey].st+i].r);
	}
	puts("");
	return 0;
}