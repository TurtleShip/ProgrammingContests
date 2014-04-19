#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 55;
int arr[maxN];

int main() {
    int T;
    int N;
    int res;
    scanf(" %d", &T);
    while(T--) {
        scanf(" %d", &N);
        for(int i=1; i <= N; i++)
            scanf(" %d", &arr[i]);
        res = 0;
        for(int i=1; i <= N; i++) {
            if(arr[i] == i) continue;
            int pos = -1;
            for(int j=i+1; j <= N; j++)
                if(arr[j] == i) {
                    pos = j;
                    break;
                }
            for(int j=pos; j > i; j--, res++) 
                swap(arr[j], arr[j-1]);
        }
        printf("Optimal train swapping takes %d swaps.\n", res);
    }
    return 0;
}