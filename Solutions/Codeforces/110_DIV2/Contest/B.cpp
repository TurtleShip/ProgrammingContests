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

bool descendingSort(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    cin>>N;
    double PI = 3.141592653589793;
    
    int cir[N];
	memset(cir, 0, sizeof(cir));
    REP(i,0,N)
        cin>>cir[i];
    
    sort(cir, cir+N, descendingSort);
    double ans = 0.0;
    bool isRed = true;
    
    for(int i=0; i < N; i++)
    {
        if(isRed)
        {
            ans += double(cir[i] * cir[i]) * PI;
            isRed = false;
        }
        else
        {
            ans -= double(cir[i] * cir[i]) * PI;
            isRed = true;
        }
    }

    cout<<fixed<<showpoint<<setprecision(6)<<ans<<endl;
	return 0;
}