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

const int maxN = 25;
int start[maxN];
int end[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    while(scanf(" %d", &N) != EOF) {
        int res = 0;
        for(int i=0; i < N; i++)
            scanf(" %d", &start[i]);
        for(int i=0; i < N; i++)
            scanf(" %d", &end[i]);
        
        for(int i=0; i < N; i++) {
            int endPos = -1;
            for(int j=0; j < N; j++)
                if(start[i] == end[j]) {
                    endPos = j;
                    break;
                }
            /* 
             Overtake = start at position < i,
             end up at position > endPos
             */
            for(int j= i-1; j >= 0; j--) {
                for(int k=endPos + 1; k < N; k++) {
                    if(start[j] == end[k]) {
                        res++;
                        break;
                    }
                }
            }
        }
        printf("%d\n", res);
    }

    return 0;
}