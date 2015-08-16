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

bool compCard(pair<int,int> a, pair<int,int> b)
{
    if(a.second > b.second)
        return true;
    else if(a.second == b.second)
    {
        return a.first > b.first;
    }
    return false;
    
}
int main()
{
    int N;
    cin>>N;
    
    vector< pair<int,int> >cards;
    
    for(int i=0; i < N; i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        cards.push_back( make_pair(a,b) );
    }
    
    sort(cards.begin(), cards.end(), compCard);
    int ans = 0;
    
    int idx = 0;
    int count = 1;
    
    while(count > 0 && idx < N)
    {
        count--;
        count += cards[idx].second;
        ans += cards[idx].first;
        idx++;
    }
    
    cout<<ans<<endl;
    return 0;
}