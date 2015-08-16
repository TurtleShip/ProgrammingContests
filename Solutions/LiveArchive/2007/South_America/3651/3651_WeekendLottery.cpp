#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 10010;
const int maxC = 15;
const int maxK = 110;

int arr[maxK];

int main() {
    
    int N, C, K;
    
    while(scanf(" %d %d %d", &N, &C, &K) && !(N == 0 && C == 0 && K ==0)) {
        int minVal = 10000;
        for(int i=1; i <= K; i++)
            arr[i] = 0;
        
        while(N--) {
            int cur = 0;
            for(int i=0; i < C; i++) {
                scanf(" %d", &cur);
                arr[cur]++;
            }
        }
        
        for(int i=1; i <= K; i++)
            minVal = min(minVal, arr[i]);
        
        bool isFirst = true;
        for(int i=1; i <= K; i++)
            if(minVal == arr[i]) {
                if(isFirst) {
                    printf("%d", i);
                    isFirst = false;
                } else {
                    printf(" %d", i);
                }
            }
        printf("\n");
    }
    return 0;
}