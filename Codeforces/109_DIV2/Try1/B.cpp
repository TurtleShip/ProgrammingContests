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

bool sortCard(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first) return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    int N;
    cin>>N;
    
    vector< pair<int,int> >cards;
    
    for(int i=0; i < N; i++)
    {
        int pt;
        int addCard;
        cin>>pt>>addCard;
        cards.push_back( make_pair(addCard , pt));
    }
    sort(cards.begin(), cards.end(), sortCard);
    
    int left = 1;
    int idx = 0;
    int points = 0;
    
    while(idx < N && left != 0)
    {
        left--;
        left += cards[idx].first;
        points += cards[idx].second;
        idx++;
    }
    
    cout<<points<<endl;
    return 0;
}