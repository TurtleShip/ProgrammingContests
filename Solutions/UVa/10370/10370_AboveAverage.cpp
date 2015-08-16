#include <cstdio>
using namespace std;
const int maxN = 1010;
int arr[maxN];

int main() {
    int C;
    scanf(" %d", &C);
    while(C--) {
        int N;
        int sum = 0;
        scanf(" %d", &N);
        for(int i=0; i < N; i++) {
            scanf(" %d", &arr[i]);
            sum += arr[i];
        }
        int good = 0;
        double avg = double(sum) / double(N);
        for(int i=0; i < N; i++) 
            if(arr[i] > avg) good++;
        double res = (double(good) / double(N)) * 100.0;
        printf("%.3lf%%", res);
        printf("\n");
        
    }
    return 0;
}