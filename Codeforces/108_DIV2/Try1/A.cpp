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

int toInt(char ch)
{
    return (ch - '0');
}

int main()
{
    int N, M;
    cin>>N>>M;
    
    int best[M];
    vector<int> who[101];
    
    memset(best, 0, sizeof(best));
    
    for(int n=0; n < N; n++)
    {
        string str;
        cin>>str;
        for(int m=0; m < M; m++)
        {
            int grade = toInt(str[m]);
            if(best[m] < grade)
            {
                best[m] = grade;
                //vector<int> cur;
                //cur.push_back(n);
                who[m] = vector<int>(1,n);
            }
            else if(best[m] == grade)
                who[m].push_back(n);
        }
    }
    
    set<int> success;
    for(int i=0; i < M; i++)
        for(int j=0; j < who[i].size(); j++)
            success.insert(who[i][j]);

    cout<<success.size()<<endl;
    return 0;
}