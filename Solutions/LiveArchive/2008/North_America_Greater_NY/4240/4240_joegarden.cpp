#define _USE_MATH_DEFINES

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int N;
double x, y;
pair<double, double> A, B, C;
pair<double, double> z1, s;
pair<double, double> f1, f2;

double dist(pair<double, double> a, pair<double, double> b){
    return sqrt(pow(a.first-b.first ,2)+pow(a.second-b.second ,2));
}

pair<double, double> midp(pair<double, double> a, pair<double, double> b){
    return make_pair((a.first+b.first)/2, (a.second+b.second)/2);
}

pair<double, double> sum(pair<double, double> a, pair<double, double> b){
    return make_pair(a.first + b.first,
                     a.second + b.second);
}

pair<double, double> sum(pair<double, double> a, pair<double, double> b, pair<double, double> c){
    return make_pair(a.first + b.first + c.first,
                     a.second + b.second + c.second);
}

pair<double, double> scl(pair<double, double> a, double b){
    return make_pair(a.first * b, a.second * b);
}

pair<double, double> cpow(pair<double, double> a, double e){
    double mag = pow(a.first, 2) + pow(a.second, 2);
    mag = pow(mag, e);
    double ang = atan2(a.second, a.first);
    ang *= e;
    while(ang > M_PI) ang -= M_PI;
    while(ang < -1*M_PI) ang += M_PI;
    
    return make_pair(sqrt(mag) * cos(ang), sqrt(mag) * sin(ang));
}

pair<double, double> prod(pair<double, double> a, pair<double, double> b){
    return make_pair(a.first*b.first - a.second*b.second, a.first*b.second+a.second*b.first);
}

pair<double, double> ftrm(pair<double, double> a, pair<double, double> b, pair<double, double> c){
    return scl(sum(prod(a, b), prod(a, c), prod(b, c)), -3);
}

bool swap(pair<double, double> a, pair<double, double> b){
    if(a.first > b.first) return true;
    if(abs(a.first - b.first) < 1e-6 && a.second > b.second) return true;
    return false;
}

int main(){
    cout << fixed << setprecision(2);
    cin >> N;
    
    for(int n=0; n<N; n++){
        cin >> x >> y;
        A = make_pair(x, y);
        cin >> x >> y;
        B = make_pair(x, y);
        cin >> x >> y;
        C = make_pair(x, y);
        
        s = sum(A, B, C);
        f1 = scl(sum(s, cpow(sum(cpow(s, 2), ftrm(A, B, C)), 0.5)), 1.0/3.0);
        f2 = scl(sum(s, scl(cpow(sum(cpow(s, 2), ftrm(A, B, C)), 0.5), -1)), 1.0/3.0);

        z1 = midp(A, B);        
        if(swap(f1, f2)) cout << n+1 << " " << f2.first << " " << f2.second
                                     << " " << f1.first << " " << f1.second << " "
                                     << dist(z1, f1)+dist(z1, f2) << endl;
        else cout << n+1 << " " << f1.first << " " << f1.second
                         << " " << f2.first << " " << f2.second << " "
                         << dist(z1, f1)+dist(z1, f2) << endl;
    }
    return 0;
}
