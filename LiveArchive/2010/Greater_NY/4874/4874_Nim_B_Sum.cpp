#include <cstdio>
using namespace std;

const int maxB = 2000000;
const int maxX = maxB;
const int maxY = maxB;

int getNimB(int B, int X, int Y) {
    int cur;
    int res = 0;
    int curB = 1;
    
    while( X != 0 || Y != 0 ) {
        cur = (X%B + Y%B) % B;
        res += cur * curB;
        curB *= B;
        X /= B;
        Y /= B;
    }
    return res;
}

int main() {
    int P, idx, B, X, Y;
    
    scanf(" %d", &P);
    
    while(P--) {
        scanf(" %d %d %d %d", &idx, &B, &X, &Y);
        printf("%d %d\n", idx, getNimB(B,X,Y));
        
    }
    return 0;
}