#include <cstdio>
using namespace std;
int main() {
    int T,a,b;
    while( scanf(" %d", &T) != EOF) {
        int idx = 1;
        while(T--) {
            scanf(" %d %d", &a, &b);
            bool isOdd = (a%2 == 1);
            int res = 0;
            for(int i=a; i <= b; i++) {
                if(isOdd) res += i;
                isOdd = !isOdd;
            }
            printf("Case %d: %d\n", idx++, res);
        }
    }
    return 0;
}