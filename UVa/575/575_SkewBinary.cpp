#include <cstdio>
#include <cstring>
using namespace std;

const int maxT = 31;
char in[10000];
int twos[maxT + 1];

void init() {
    twos[0] = 1;
    for(int i=1; i <= maxT; i++)
        twos[i] = twos[i-1] * 2;
}

int main() {
    init();
    while(scanf(" %s", in)) {
        int len = strlen(in);
        if(len == 1 && in[0] == '0') break;
        int res = 0;
        for(int k=0; k < len; k++) {
            int cur = in[k] - '0';
            res += cur * (twos[len-k] -1);
        }
        printf("%d\n", res);
    }
    
    return 0;
}