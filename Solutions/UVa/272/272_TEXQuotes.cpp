#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char in[10000];
    bool isOpen = false;
    while( gets(in) != NULL) {
        for(int i=0; i < strlen(in); i++) {
            if(in[i] == '\"') {
                if(isOpen) printf("''");
                else printf("``");
                isOpen = !isOpen;
            } else if(in[i] == '\0') printf(" ");
            else printf("%c", in[i]);
        }
        printf("\n");
    }
    return 0;
}