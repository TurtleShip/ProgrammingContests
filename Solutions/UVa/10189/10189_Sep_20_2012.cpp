#include <cstdio>
using namespace std;
const int maxN = 150;
int arr[maxN][maxN];
int move[8][2] = {
    {-1,-1}, {-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1}, {1, 0}, {1, 1} 
};
int main() {
    int R,C;
    char ch;
    int idx = 1;
    while( scanf(" %d %d", &R, &C) && !(R == 0 && C == 0) ) {
        if(idx != 1) printf("\n");
   
        for(int i=0; i < R; i++)
            for(int j=0; j < C; j++) {
                scanf(" %c", &ch);
                arr[i][j] = (ch == '*') ? -100 : 0;
            }
        
        for(int r=0; r < R; r++)
            for(int c=0; c < C; c++)
                if(arr[r][c] < 0) {
                    for(int i=0; i < 8; i++) {
                        int dr = r + move[i][0];
                        int dc = c + move[i][1];
                        if(0 <= dr && dr < R && 0 <= dc && dc < C) {
                            arr[dr][dc]++;
                        }
                    }
                }
        
        printf("Field #%d:\n", idx++);
        for(int i=0; i < R; i++) {
            for(int j=0; j < C; j++)
                if(arr[i][j] < 0) printf("*");
                else printf("%d", arr[i][j]);
            printf("\n");
        }
    }
    
    return 0;
}