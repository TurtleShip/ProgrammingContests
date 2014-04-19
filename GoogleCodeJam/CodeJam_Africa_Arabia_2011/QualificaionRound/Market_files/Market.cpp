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
    int N;
    cin>>N;
    for(int idx=1; idx <= N; idx++)
    {
        int M;
        cin>>M;
        
        // pair<int,int> = <price, month>
        vector< pair<int,int> > price;
        
        for(int i=1; i <=12; i++)
        {
            int cur;
            cin>>cur;
            price.push_back( make_pair(cur, i) );
        }
        sort(price.begin(), price.end());
        
        int buy = -1;
        int sell = -1;
        int profit = 0;
        bool valid = false;
        for(int i=0; i < 12; i++)
        {
            for(int j= 11; j > i; j--)
            {
                if(price[i].second < price[j].second && price[i].second <= M)
                {
                    int curPro = (price[j].first - price[i].first) * (M/price[i].first);
                    if(profit < curPro)
                    {
                        buy = price[i].second;
                        sell = price[j].second;
                        profit = curPro;
                        valid = true;
                    }
                }
            }
        }
        if(valid)
        {
            cout<<"Case #"<<idx<<": "<<buy<<" "<<sell<<" "<<profit<<endl;
            
        }
        else cout<<"Case #"<<idx<<": "<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}