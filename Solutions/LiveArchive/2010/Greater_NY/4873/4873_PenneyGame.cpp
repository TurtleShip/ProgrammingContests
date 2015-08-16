#include <cstdio>
#include <cstring>
using namespace std;

#define TRACE(x) 

int res[1000];
int arr[40];
int main() {
    int P;
    scanf(" %d", &P);
    
    while(P--) {
        memset(res, 0, sizeof(res));
        int idx;
        char ch;
        scanf(" %d", &idx);
        
        for(int i=0; i < 40; i++) {
            scanf(" %c", &ch);
            arr[i] = (ch == 'H') ? 0 : 1;
        }
        
        for(int i=0; i < 38; i++) 
                      res[ arr[i]*100 + arr[i+1]*10 + arr[i+2] ]++;
        
        printf("%d %d %d %d %d %d %d %d %d\n", idx, res[111], res[110], res[101], res[100], res[11], res[10], res[1], res[0]);
    }
    return 0;
}