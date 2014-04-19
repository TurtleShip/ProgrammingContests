#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    char str[1000];
    while( scanf(" %s" , str) != EOF ){
        for(int i=0; i < strlen(str); i++)
            printf("%c", char(str[i] - 7));
        printf("\n");
    }
    return 0;
}