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
const int maxN = 1e4 + 10;
int arr[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    while(scanf("%d", &N) != EOF) {
        
        int sum = 0;
        for(int i=0; i < N; i++) {
            scanf(" %d", &arr[i]);
            sum += arr[i];
        }
        if(abs(sum) % N != 0) printf("-1\n");
        else {
            int res = 0;
            sum /= N;
            for(int i=0; i < N; i++)
                res += abs(sum - arr[i]);
            res /= 2;
            res++;
            printf("%d\n",res);
        }
    }

    return 0;
}