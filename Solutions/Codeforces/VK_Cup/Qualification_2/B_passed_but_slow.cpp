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
    /*
     N markers.
     x : color
     y : diameter
     
     
     M marker caps
     a : color
     b : diameter
     
     
     Cap can close marker only if y = b
     A marker is considered to be beautifully closed if x = a
     */
    
    int N , M;
    cin>>N>>M;
    
    vector<int> colorMark[1001];
    vector<int> colorCap[1001];
    int arr[1001][1001];
    
    memset(arr, 0, sizeof(arr));
    
    int U = 0, V = 0;
    
    REP(i,0,N)
    {
        int col, sz;
        cin>>col>>sz;
        colorMark[sz].push_back(col);
    }
    
    REP(i,0,M)
    {
        int col, sz;
        cin>>col>>sz;
        colorCap[sz].push_back(col);
    }
    
    for(int i=1; i <= 1000; i++)
    {
        if(colorMark[i].size() == 0 || colorCap[i].size() == 0)
            continue;
        
        U += min(colorMark[i].size(), colorCap[i].size());
        
        for(int j=0; j < colorMark[i].size(); j++)
        {
            for(int k=0; k < colorCap[i].size(); k++)
            {
                if(colorMark[i][j] == colorCap[i][k])
                {
                    V++;
                    colorCap[i].erase(colorCap[i].begin() + k);
                    break;
                }
            }
        }
    }
    
    cout<<U<<" "<<V<<endl;
    
    return 0;
}