#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    int N; // the number of words of the short story
    int L; // the maximum number of lines per page
    int C; // the maximum number of characters per line
    
    while(scanf(" %d %d %d", &N, &L, &C) != EOF) {
        
        int res = 1;
        int numWord = 0; //number of word in the current line
        int numLine = 1; //number of lines in the current page
        for(int i=0; i < N; i++) {
            char curWord[C];
            scanf(" %s", curWord);
            int len = strlen(curWord);
            numWord += len;
            if(numWord != C) numWord++; //we insert empty space if this is not the last word in the current line
            if(numWord > C) {
                numLine++; //move to a new line
                numWord = (len+1); //write the current word in the new line
                if(numLine > L) {
                    res++;
                    numLine = 1;
                }
            }
        }
        printf("%d\n", res);
    }

    return 0;
}