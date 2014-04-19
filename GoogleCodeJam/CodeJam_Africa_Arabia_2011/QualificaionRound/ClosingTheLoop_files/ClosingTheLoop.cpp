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
using namespace std;

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;

bool descendingSort(int a , int b)
{
    return (a>b);
}

int main()
{
    int N;
    cin>>N;
    
    for(int idx=1; idx <= N; idx++)
    {
        int S;
        cin>>S;
        
        vector<int> red;
        vector<int> blue;
        for(int i=0; i < S; i++)
        {
            string str;
            cin>>str;
            int N = str.size();
            stringstream ss;
            int num;
            ss<<str.substr(0, (N-1));
            ss>>num;
            
            if(str[N-1] == 'R')
            {
                red.push_back(num);
            }
            else
            {
                blue.push_back(num);
            }
        }
        
        sort(red.begin(), red.end(), descendingSort);
        sort(blue.begin(), blue.end(), descendingSort);
        
        int M = min(red.size(), blue.size());
        int ans = 0;
        for(int i=0; i < M; i++)
        {
            ans += red[i] - 1;
            ans += blue[i] -1 ;
        }
        
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    
    return 0;
}