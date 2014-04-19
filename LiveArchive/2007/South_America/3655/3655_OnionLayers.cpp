#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
    
#define all(v) (v).begin(), (v).end()
    
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point{
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y){}
    
    int cmp(point q) const{
        if(int t = ::cmp(x, q.x)){
            return t;
        }
        return ::cmp(y, q.y);
    }
    
    bool operator < (point q) const{
        return cmp(q) < 0;
    }
    
    point operator +(point q){
        return point(x + q.x, y + q.y);
    }
    
    point operator -(point q){
        return point(x - q.x, y - q.y);
    }
    
    point operator *(double t){
        return point(x * t, y * t);
    }
    
    double operator *(point q){
        return x * q.x + y * q.y;
    }
    
    double operator %(point q){
        return x * q.y - y * q.x;
    }
    
    static point pivot;
};

point point::pivot;

inline int ccw(point p, point q, point r){
    return cmp(( p - r) % (q - r));
}
    
bool radial_lt(point p, point q){
    point P = p - point::pivot, Q = q - point::pivot;
    double R = P % Q;
    if(cmp(R)){
        return R > 0;
    }
    return cmp(P * P, Q * Q) < 0;
}
    
typedef vector<point> polygon;
    
polygon convex_hull(vector<point>& T){
    int j = 0, k, n = T.size(); polygon U(n);
    point::pivot = *min_element(all(T));
    sort(all(T), radial_lt);
    for(k = n - 2; k >= 0 && ccw(T[0], T[n - 1], T[k]) == 0; k--);
    reverse((k + 1) + all(T));
    for(int i = 0; i < n; i++){
        while( j > 1 && ccw(U[j - 1], U[j - 2], T[i]) > 0) j--;
        U[j++] = T[i];
    }
    U.erase(j + all(U));
    return U;
}

int N, Z;
vector<point> p, q, r;

int main(){
    while(cin >> N){
        if(N==0) break;
        Z = 0;
        p.clear();
        for(int n=0; n<N; n++){
            int A, B;
            cin >> A >> B;
            p.push_back(point(A,B));
        }
        sort(all(p));
        while(p.size()){
            Z++;
            q = p;
            r = convex_hull(q);
            sort(all(r));
            q.clear();
            set_difference(all(p), all(r), back_inserter(q));
            p = q;
        }
        if(Z%2) cout << "Take this onion to the lab!" << endl;
        else cout << "Do not take this onion to the lab!" << endl;
    }
    return 0;
}
