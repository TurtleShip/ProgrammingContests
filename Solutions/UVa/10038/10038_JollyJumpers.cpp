#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 3e3 + 10;
bool hasNum[maxN];
int arr[maxN];

int main() {
    
    int N;
    while(scanf(" %d", &N) != EOF) {
        for(int i=0; i < N; i++)
            scanf(" %d", &arr[i]);
        for(int i=1; i <= N-1; i++)
            hasNum[i] = false;
        for(int i=0; i < N-1; i++)
            hasNum[abs(arr[i] - arr[i+1])] = true;
        bool isJolly = true;
        for(int i=1; i <= N-1 && isJolly; i++)
            if(!hasNum[i]) isJolly = false;
        
        if(isJolly) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}