#include<iostream>
using namespace std;

int N, A;
long long ans[1005];

int main(){
    ans[0] = 1;
    ans[1] = 1;
    for(int c=2; c<=1000; c++){
        if(c%2){
            for(int m=1; m<=c; m+=2)
                ans[c] += ans[(c-m)/2];
        }
        else{
            for(int m=0; m<=c; m+=2)
                ans[c] += ans[(c-m)/2];
        }
    }
    
    
    cin >> N;
    for(int n=0; n<N; n++){
        cin >> A;
        cout << n+1 << " " << ans[A] << endl;
    }
    return 0;
}
