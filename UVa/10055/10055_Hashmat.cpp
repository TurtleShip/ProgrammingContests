#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    long long a,b;
    while(scanf(" %lld %lld", &a, &b) != EOF) {
        printf("%lld\n", abs(b-a));
    }
    return 0;
}