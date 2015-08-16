#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
    int T;
    while( scanf(" %d", &T) != EOF) {
        int F;
        while(T--) {
            scanf(" %d", &F);
            ll res = 0ll;
            while(F--) {
                ll a,b,c;
                scanf(" %lld %lld %lld", &a, &b, &c);
                res += a*c;
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}