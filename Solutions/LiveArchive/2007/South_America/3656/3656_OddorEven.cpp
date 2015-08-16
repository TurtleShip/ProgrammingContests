#include<iostream>
using namespace std;

int N;
int A, B, T;

int main(){
    while(cin >> N){
        if(N==0) break;
        A = B = 0;
        for(int n=0; n<N; n++){
            cin >> T;
            if(T%2) A++;
        }
        for(int n=0; n<N; n++){
            cin >> T;
            if(T%2) B++;
        }
        cout << max(A, N-B) - min(A, N-B) << endl;
    }
}
