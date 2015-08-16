#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 110;

int arr[maxN][maxN];
/* sum[i][j] = sum of numbers from arr[0][0] to arr[i][j] */
int sum[maxN][maxN];

int main() {
    int N;
    while( scanf(" %d", &N) != EOF) {
        //add padding
        for(int i=0; i <= N; i++)
            arr[0][i] = arr[i][0] = 0;
        
        for(int i=1; i <= N; i++)
            for(int j=1; j <= N; j++)
                scanf(" %d", &arr[i][j]);
        
        //complete sum
        for(int r=1; r <= N; r++)
            for(int c=1; c<= N; c++)
                sum[r][c] = arr[r][c] + sum[r][c-1] + sum[r-1][c] - sum[r-1][c-1];
        
        int res = -10000;
        for(int r1 = 1; r1 <= N; r1++)
            for(int  c1 = 1; c1 <= N; c1++)
                for(int r2 = r1; r2 <= N; r2++)
                    for(int c2 = c1; c2 <= N; c2++)
                        res = max(res, sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1]);
        printf("%d\n",res);
        
    }
    return 0;
}