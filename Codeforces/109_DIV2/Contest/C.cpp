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



int main()
{
    string sen;
    cin>>sen;
    
    int K;
    cin>>K;
    
    vector<string> forb;
    for(int i=0; i < K; i++)
    {
        string yo;
        cin>>yo;
        forb.push_back(yo);
    }
    
    int ans = 0;
    int N = sen.size();
    for(int i=0; i < K; i++)
    {
        string cur = forb[i];

        for(int j=0; j < N; j++)
        {
            if(sen[j] == cur[0] || sen[j] == cur[1])
            {
                int start = j;
                int len = 0;
                int idx = (sen[j] == cur[0]) ? 0 : 1;
                
                while(start < N && (sen[start] == cur[idx%2]))
                {
                    start++;
                    len++;
                    idx++;
                }

                ans += len / 2;
                j = start;
            }
            
        }
    }

    cout<<ans<<endl;
    
    return 0;
}