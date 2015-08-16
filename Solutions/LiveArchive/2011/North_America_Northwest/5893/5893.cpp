#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
using namespace std;

#define INF 9999999
// maximum absolute speed is less than 16
bool isVisited[64][64][40][40];
int fsx[7]; int ftx[7];
int fsy[7]; int fty[7];
int dx[5] = {1,-1,0,0,0};
int dy[5] = {0,0,1,-1,0};
int W,H,sx,sy,tx,ty,F;
int delta = 20;

const double EPS = 1e-8;

int cmp(double x, double y = 0, double tol = EPS) {
        return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
        double x, y;
        point(double x = 0, double y = 0): x(x), y(y) {}

        point operator +(point q) { return point(x + q.x, y + q.y); }
        point operator -(point q) { return point(x - q.x, y - q.y); }
        point operator *(double t) { return point(x * t, y * t); }
        point operator /(double t) { return point(x / t, y / t); }
        double operator *(point q) { return x * q.x + y * q.y; }
        double operator %(point q) { return x * q.y - y * q.x; }

        int cmp(point q) const {
                if (int t = ::cmp(x, q.x)) return t;
                return ::cmp(y, q.y);
        }
        bool operator ==(point q) const { return cmp(q) == 0; }
        bool operator !=(point q) const { return cmp(q) != 0; }
        bool operator < (point q) const { return cmp(q) <  0; }
        
        friend ostream& operator <<(ostream& o, point p) {
                return o << "(" << p.x << ", " << p.y << ")";
        }
        
        static point pivot;
};

bool seg_intersect(point p, point q, point r, point s) {
        point A = q - p, B = s - r, C = r - p, D = s - q;
        int a = cmp(A % C) + 2 * cmp(A % D);
        int b = cmp(B % C) + 2 * cmp(B % D);
        if (a == 3 || a == -3 || b == 3 || b == -3) return false;
        if (a || b || p == r || p == s || q == r || q == s) return true;
        int t = (p < r) + (p < s) + (q < r) + (q < s);
        return t != 0 && t != 4;
}

bool isValid(int x0, int y0, int x1, int y1) {
	for(int i=0; i < F; i++)
		if(seg_intersect(point(x0,y0),point(x1,y1),point(fsx[i],fsy[i]),point(ftx[i],fty[i]))) return false;
	return true;
}

int main() {

	while(cin>>W>>H) {
		cin>>sx>>sy>>tx>>ty>>F;
		for(int i=0; i < F; i++)
			cin>>fsx[i]>>fsy[i]>>ftx[i]>>fty[i];

		// initialize
		for(int i=0;i < W; i++)
			for(int j=0; j < H; j++)
				for(int k=0; k < 40; k++)
					for(int l=0; l < 40; l++)
						isVisited[i][j][k][l] = false;

		queue<int> Q;
		Q.push(sx); Q.push(sy); Q.push(0); Q.push(0); Q.push(0);
		isVisited[sx][sy][0+delta][0+delta] = true;

		int cx,cy,cvx, cvy, step;
		int nx,ny, nvx, nvy;
		int res = -1;
		while(!Q.empty()) {
			cx = Q.front(); Q.pop();
			cy = Q.front(); Q.pop();
			cvx = Q.front(); Q.pop();
			cvy = Q.front(); Q.pop();
			step = Q.front(); Q.pop();
			if(cx == tx && cy == ty && cvx == 0 && cvy == 0) {
				res = step;
				break;
			}


			for(int i=0; i < 5; i++) {
				nvx = cvx + dx[i];
				nvy = cvy + dy[i];
				nx = cx + nvx;
				ny = cy + nvy;
				if(0 <= nx && nx < W && 0 <= ny && ny < H) {
					// check for walls
					if(!isValid(cx, cy, nx, ny)) continue;
					if(!isVisited[nx][ny][nvx+delta][nvy+delta]) {
						isVisited[nx][ny][nvx+delta][nvy+delta] = true;
						Q.push(nx); Q.push(ny); Q.push(nvx); Q.push(nvy); Q.push(step+1);
					}
				}
			}
		}
		cout<<res<<endl;
	}

	return 0;
}
