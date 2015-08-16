#include <cstdio>
using namespace std;
typedef long long ll;

bool isPalin(ll val) {
    int ori = val;
    int rev = 0;
    while(val != 0) {
        rev *= 10;
        rev += (val % 10);
        val /= 10;
    }
    return ori == rev;
}

int main() {
    int N;
    
    scanf(" %d", &N);
    while(N--) {
        ll val;
        int res = 0;
        scanf(" %lld", &val);
        
        while(!isPalin(val)) {
            ll ori = val;
            ll rev = 0;
            while(val != 0) {
                rev *= 10;
                rev += (val % 10);
                val /= 10;
            }
            val = ori + rev;
            res++;
        }
        printf("%d %lld\n", res, val);
    }
    
    return 0;
}