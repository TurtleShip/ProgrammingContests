#include <cstdio>
#include <cstring>
using namespace std;

bool isLetter(char ch) {
    return ( ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') );
}

int main() {
    char in[10000];
    while(gets(in) != NULL) {
        int res = 0;
        bool inWord = false;
        for(int i=0; i < strlen(in); i++) {
            if(isLetter(in[i])) {
                if(!inWord) inWord = true;
            } else {
                if(inWord) {
                    inWord = !inWord;
                    res++;
                }
            }
        }
        if(inWord) res++;
        printf("%d\n",res);
    }
    return 0;
}