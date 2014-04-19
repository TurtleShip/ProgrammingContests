#include <cstdio>
#include <cstring>
using namespace std;

const int maxS = 4;
const int maxP = 5;
char in[10000]; //get input
char name[maxS + 1][1000]; //names
int num[maxS + 1][100]; //nums
int numLen[maxS + 1];
int ind[maxS+1][maxP+1]; // ind[s][p] = Ending index of product p of seller s
int val[maxS+1][maxP+1]; // val[s][p] = value of product p of seller s

int T; //number of test cases
int P; //number of products
int S; //number of sellers

bool foundRes = false;

void dfs(int s, int p) {
    if(foundRes) return;
    if(s == S) {
        //check totals
        for(int ss = 0; ss<S; ss++)
            for(int pp = 0; pp<=P; pp++)
                val[S][pp] += val[ss][pp];
        
        int idx = numLen[S] - 1;
        
        for(int pp = P; p >= 0;p--) {
            int cur = val[S][pp];
            while(cur != 0) {
                if(cur%10 != num[S][idx]) return;
                cur /= 10;
                idx--;
            }
        }
        
        foundRes = true;
        
        for(int i=1; i <= N; i++)
            printf("P%d ", i);
        printf("Totals\n");
        for(int ss=0; ss <= S; ss++) {
            printf("%s",name[ss]);
            for(int pp=0; pp <= P; pp++)
                printf(" %d" , val[ss][pp]);
            printf("\n");
        }
        return;
    }
    
    if(p == P) {
        int sum = 0;
        for(int pp = 0; pp <= P; pp++) {
            val[s][pp] = 0;
            int i = (pp == 0) ? 0 : ind[s][pp-1];
            for(; i < ind[s][pp]; i++) {
                val[s][pp] *= 10;
                val[s][pp] += num[s][i];
            }
            sum += val[s][pp];
        }
        if(sum != val[s][P]) return;
        dfs(s+1, 0);
        return;
    }
    
    int start = (p == 0) ? 1 : (ind[s][p-1] + 1);
    for(ind[s][p] = start; ind[s][p] < numLen[s]; ind[s][p]++) {
        if(p==0 && ind[s][p] >= 2 && num[s][0] == 0) continue;
        if(p > 0 && (ind[s][p] - ind[s][p-1]>1) && num[s][ind[s][p-1]] == 0) continue;
        dfs(s,p+1);
    }
    
}

int main() {
    
    scanf(" %d", &T);
    
    while(T--) {
        foundRes = false;
        scanf(" %s", in);
        P = (strlen(in) - 6) / 2;
        S = 0;
        
        
        //receive input
        while(true) {
            scanf(" %s", in);
            int i=0;
            for(i=0; i < strlen(in); i++) {
                if('0' <= in[i] && in[i] <= '9') break;
                name[S][i] = in[i];
            }
            name[S][i] = '\0';
            for(; i < strlen(in); i++) {
                num[S][i] = (in[i] - '0');
            }
            
            numLen[S] = strlen(in) - strlen(name[S]);
            if(strlen(name[S]) == 2 && name[S][0] == 'T' && name[S][1] == 'P') break;
            S++;
        }
    }
    
    
    return 0;
}