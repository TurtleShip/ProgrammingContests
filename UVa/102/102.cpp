#include <cstdio>
#include <limits>
using namespace std;

int B[3][3];
char C[3] = {'B', 'G', 'C'};
int P[6][3] = {
    {0,2,1},
    {0,1,2},
    {2,0,1},
    {2,1,0},
    {1,0,2},
    {1,2,0}
};

int main() {
    
    while( scanf("%d %d %d %d %d %d %d %d %d", &B[0][0], &B[0][1], &B[0][2], &B[1][0], &B[1][1], &B[1][2], &B[2][0], &B[2][1], &B[2][2]) != EOF) {
        
        int res = numeric_limits<int>::max();
        int resColor[3];
        //there are only 3*2 = 6 possibilities
        for(int i=0; i < 6; i++) {
            int cur = 0;
            for(int j=0; j < 3; j++)
                for(int k=0; k < 3; k++) {
                    if(P[i][j] == k) continue;
                    cur += B[j][k];
                }
            
            if(cur < res) {
                res = cur;
                for(int j=0; j < 3; j++)
                    resColor[j] = P[i][j];
            }
        }
        
        for(int i=0; i < 3; i++)
            printf("%c", C[resColor[i]]);
        printf(" %d\n", res);
    }
    
    return 0;
}