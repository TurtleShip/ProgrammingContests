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
    string S;
    int K;
    cin>>S>>K;
    int N = S.size();
    int ans = 0;
    for(int i=0; i < K; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j < N; j++)
        {
            if(S[j] == str[0] || S[j] == str[1])
            {
                int pair[2] = {0,0};
                int len = 0;
                
                while((j+len) < N && (S[j+len] == str[0] || S[j+len] == str[1]))
                {
                    if(S[j+len] == str[0]) pair[0]++;
                    else pair[1]++;
                    len++;
                }
                
                ans += min(pair[0], pair[1]);
                j += len;
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}