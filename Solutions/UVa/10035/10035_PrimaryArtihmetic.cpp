#include <cstdio>
using namespace std;
typedef long long ll;
/* counts number of carry operations needed
   to add 'a' to 'b' */
int countCarry(ll a, ll b) {
    int res = 0;
    bool hasCarry = false;
    while(hasCarry || (a != 0 && b != 0)) {
        int curA = a % 10; a /= 10;
        int curB = b % 10; b /= 10;
        if(hasCarry) curA++;
        if( (curA + curB) >= 10) {
            res++;
            hasCarry = true;
        } else hasCarry = false;
    }
    return res;
}

int main() {
    ll a, b;
    while(scanf(" %lld %lld", &a, &b) && !(a == 0 && b == 0)) {
        int res = countCarry(a,b);
        if(res == 0) printf("No carry operation.\n");
        else if(res == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n",res);
    }
    return 0;
}