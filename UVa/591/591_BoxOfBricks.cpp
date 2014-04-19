#include <cstdio>
#include <algorithm>
using namespace std;
int maxN = 55;

int main() {
    
    int arr[maxN];
    int N;
    int idx = 1;
    while( scanf(" %d", &N) && N != 0) {
        
        int sum = 0;
        for(int i=0; i < N; i++) {
            scanf(" %d", &arr[i]);
            sum += arr[i];
        }
        int avg = sum / N;
        int res = 0;
        for(int i=0; i < N; i++)
            res += abs(arr[i] - avg);
        res /= 2;
        
        printf("Set #%d\n", idx++);
        printf("The minimum number of moves is %d.\n\n", res);
    }
    return 0;
}