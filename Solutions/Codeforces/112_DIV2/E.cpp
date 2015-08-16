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

const int maxN = 1000010;

vector<int> arr(maxN);
int chk[4000010];

int main()
{
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
 
    REP(i,0,N)
    {
        cin>>arr[i];
    }
    
    for(int i=0; i < N; i++)
    {
        if(chk[i])
        {
            cout<<chk[i]<<" ";
            continue;
        }
        
        for(int j=(i+1); j < N; j++)
        {
            if( (arr[i] & arr[j]) == 0)
            {
                chk[i] = arr[j];
                chk[j] = arr[i];
                break;
            }
        }
        
        if(chk[i] == 0) chk[i] = -1;
        cout<<chk[i]<<" ";
    }
    cout<<endl;
    return 0;
}