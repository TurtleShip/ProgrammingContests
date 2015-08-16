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
    
    int N, X;
    cin>>N>>X;
    
    deque<int> arr(N);
    REP(i,0,N)
    cin>>arr[i];
    
    int ans = 0;
    
    if(count(arr.begin(), arr.end(), X) == 0)
    {
        ans++;
        arr.push_front(X);
    }
    
    sort(arr.begin(), arr.end());

    int mid = ((arr.size() + 1) / 2) - 1;
    
    while(arr[mid] != X)
    {
        if(arr[mid] < X) arr.push_back(0);
        else arr.push_front(0);
        mid = ((arr.size() + 1) / 2) - 1;
        ans++;
    }
    
    cout<<ans<<endl;

    return 0;
}
