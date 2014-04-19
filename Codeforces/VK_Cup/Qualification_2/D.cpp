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


string S;

//return true is S[i]..S[j] are palindrome
bool isPalin(int i, int j)
{
    while(i < j)
    {
        if(S[i] != S[j]) return false;
        i++;
        j--;
    }
    return true;
}

ll L[2000]; //number of palindromes from S[0..j] that have S[j] in it
ll R[2000]; //number of palindromes from S[j..N-1]

//test with 2000 character long string
int main()
{
    cin>>S;
    int N = S.size();

    if(N == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    
    for(int cen=0; cen < N; cen++)
    {
        int dL = cen;
        int dR = cen;
        //S[cen] is center
        while(0 <= dL && dR < N && S[dL] == S[dR])
        {
            L[dR]++;
            R[dL]++;
            dL--;
            dR++;
        }
        
        //s[cen] , s[cen+1] is a center
        if(cen == N-1) continue;
        dL = cen;
        dR = cen+1;
        while(0 <= dL && dR < N && S[dL] == S[dR])
        {
            L[dR]++;
            R[dL]++;
            dL--;
            dR++;
        }
    }
    
    for(int r = N-2; r >= 0; r--)
        R[r] += R[r+1];

    ll ans = 0;
    for(int mid = 0; mid < N-1; mid++)
        ans += L[mid] * R[mid+1];
        

    cout<<ans<<endl;
    
    return 0;
}