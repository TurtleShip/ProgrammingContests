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
    string S;
    string U;
    cin>>S>>U;
    
    int best = 2001;
    
    int lenS = S.size();
    int lenU = U.size();
    
    for(int i=0; i < lenS; i++)
    {
        int cur = lenU;
        for(int j=0; j < lenU && (i+j) < lenS; j++)
        {
            if(S[i+j] == U[j]) cur--;
        }
        best = min(best ,cur);
    }
    
    cout<<best<<endl;
    return 0;
}