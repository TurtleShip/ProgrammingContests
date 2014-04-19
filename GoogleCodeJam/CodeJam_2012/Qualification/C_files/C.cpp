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

int howMany(int);

int A,B,D;
int main()
{
    ios_base::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    for(int idx = 1; idx <= T; idx++)
    {
        cin>>A>>B;
        int res = 0;
        stringstream ss;
        string str;
        ss<<A;
        str = ss.str();
        D = str.size();
        for(int num = A; num <= B; num++)
            res += howMany(num);
        cout<<"Case #"<<idx<<": "<<res<<endl;
    }
    
    return 0;
}

int howMany(int num)
{
    set<int> res;
    int dig[D];
    int tmp = num;
    for(int i=0; i < D; i++)
    {
        dig[D-1-i] = tmp%10;
        tmp /= 10;
    }
    
    for(int p=1; p < D; p++)
    {
        if(dig[0] > dig[p]) continue;
        int cur = dig[p];
        for(int i = p+1; i < D; i++)
        {
            cur *= 10;
            cur += dig[i];
        }
        for(int i=0; i < p; i++)
        {
            cur *= 10;
            cur += dig[i];
        }
        if(num < cur && cur <= B)
            res.insert(cur);
    }
    return res.size();
}