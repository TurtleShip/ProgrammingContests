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

const int maxA = 100010;
double pR[maxA];
double allR[maxA];
int main()
{
    ios_base::sync_with_stdio(false);
    
    cout.precision(10);
    cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin>>T;
    for(int idx=1; idx <= T; idx++)
    {
        int A,B;
        cin>>A>>B;
        
        cin>>pR[0];
        allR[0] = pR[0];
        REP(i,1,A)
        {
            cin>>pR[i];
            allR[i] = allR[i-1] * pR[i];
        }
        
        double dA = double(A);
        double dB = double(B);
        
        double res = allR[A-1] * (dB - dA + 1.0) + (1.0 - allR[A-1]) * (dB - dA + 1.0 + dB + 1.0);
        
        for(int b = 1; b < A; b++)
        {
            double db = double(b);
            res = min(res, allR[A-1-b] * (db + (dB - dA + db) + 1.0) + (1.0 - allR[A-1-b]) * (db + (dB - dA + db) + 1.0 + dB + 1.0));
        }
        
        res = min(res, 1.0 + dB + 1.0);
        
        cout<<"Case #"<<idx<<": "<<res<<endl;
    }
    
    return 0;
}