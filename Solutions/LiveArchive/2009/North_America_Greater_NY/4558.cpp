#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define all(v) (v).begin(), (v).end()

const double EPS = 1e-8;
int cmp(double x, double y=0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}

	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(double t) {return point(x*t, y*t); }
	point operator /(double t) {return point(x/t, y/t); }
	double operator *(point q) { return x*q.x + y*q.y; }
	double operator %(point q) { return x*q.y -y*q.x; }

	int cmp(point q) const {
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}

	bool operator < (point q) const { return cmp(q) < 0; }

	static point pivot;

};

point point::pivot;

typedef vector<point> polygon;

inline int ccw(point p, point q, point r) {
	return cmp((p-r) % (q-r) );
}
bool radial_lt(point p, point q) {
	point P = p - point::pivot, Q = q - point::pivot;
	double R = P % Q;
	if(cmp(R)) return R > 0;
	return cmp(P*P, Q*Q) < 0;
}

polygon convex_hull(vector<point>& T) {
	int j=0, k, n= T.size(); polygon U(n);

	point::pivot = *min_element(all(T));
	sort(all(T), radial_lt);
	// for(k =n-2; k >=0 && ccw(T[0], T[n-1], T[k]) == 0; k--);
	// 	reverse((k+1) + all(T));

	for(int i=0; i < n; i++) {
		while(j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
		U[j++] = T[i];
	}
	U.erase(j + all(U));
	return U;
}

int main() {
	int P, id, N,x,y;
	cin>>P;
	while(P--) {
		cin>>id>>N;
		vector<point> V;
		while(N--) {
			cin>>x>>y;
			V.push_back(point(x,y));
		}
		polygon res = convex_hull(V);
		cout<<id<<" "<<res.size()<<endl;


		double maxY = res[0].y;
		double minX = res[0].x;
		int idx = 0;
		for(int i=1; i < res.size(); i++) {
			if(res[i].y > maxY || (res[i].y == maxY && res[i].x < minX)) {
				idx = i;
				maxY = res[i].y;
				minX = res[i].x;
			}
		}

		for(int i=idx; i >= 0; i--) {
			cout<<res[i].x<<" "<<res[i].y<<endl;
		}
		for(int i=res.size()-1; i > idx; i--)
			cout<<res[i].x<<" "<<res[i].y<<endl;
	}

	return 0;
}