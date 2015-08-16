#include<iostream>
using namespace std;

int N, A, B;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    cin >> N;
    for(int n=0; n<N; n++){
        cin >> A >> B;
        int g = gcd(A, B);
        cout << n+1 << " " << A*B/g << " " << g << endl;
    }
    return 0;
}
