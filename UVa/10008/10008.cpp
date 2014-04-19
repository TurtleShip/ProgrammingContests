#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

char in[10000];
map <char, int> M;
int main() {
    gets(in);
    int N = atoi(in);
    int maxC = 0;
    while(N--) {
        gets(in);
        
        for(int i=0; i < strlen(in); i++) {
            char cur = in[i];
            if('a' <= cur && cur <= 'z')
                cur = char(cur + 'A' - 'a');
            
            if('A' <= cur && cur <= 'Z') {
                if(!M.count(cur)) M[cur] = 1;
                else M[cur]++;
                maxC = max(maxC, M[cur]);
            }
        }
    }
    
    maxC++;
    while(maxC--) {
        map<char,int>::iterator itr;
        for(itr = M.begin(); itr != M.end(); itr++)
            if(itr->second == maxC)
                printf("%c %d\n", itr->first, maxC);
    }
    return 0;
}