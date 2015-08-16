#include <vector>
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
    ll nINF = numeric_limits<ll>::min();
    ll N,K;
    cin>>N>>K;
    
    vector<ll> arr(N+1,0);
    arr[0] = nINF;
    
    REP(i,0,N)
        cin>>arr[i+1];
    
    sort(arr.begin(), arr.end());
    
    ll F = K / N;
    ll S = K % N;
    
    if(S == 0)
    {
        S = N;
    }
    else
        F++;
    
    cout<<endl;
    for(int i=1; i <= N*N; i++)
    {
        ll F = i / N;
        ll S = i % N;
        
        if(S == 0)
        {
            S = N;
        }
        else
            F++;
        
        cout<<arr[F]<<" "<<arr[S]<<endl;
    }
    
    cout<<"end \n\n"<<endl;
    cout<<arr[F]<<" "<<arr[S]<<endl;
    
    
    return 0;
}