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
const int maxN = 1010; //100

struct Item
{
    int idx;
    double price;
    int type;
};

Item items[maxN];

int len[maxN];

bool sortItem(Item a, Item b)
{
    if(a.type != b.type) return a.type < b.type;
    return a.price > b.price;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N,K;
    cin>>N>>K;
    
    int S = 0; //number of stools
    int P = 0; //number of pencils
    
    REP(i,0,N)
    {
        cin>>items[i].price>>items[i].type;
        items[i].idx = i+1;
    }

    /*
     Sort by price.
     Stools gets price down, so it is optimal to place stools
     in as many carts as possible.
     Fill carts by highest-priced stools first.
     
     If S < K,
     place pencils in carts without a stool.
     
     IF S >= K,
     Pick the one with the smallest-priced stool, stash whole thing there
     */
    
    sort(items, items + N, sortItem);
    
    double ans = 0.0;
    for(int i=0; i <(K-1); i++)
    {
        if(items[i].type == 1)
        {
            ans += double(items[i].price) * 0.5;

        }
        else
        {
            ans += double(items[i].price);
        }
    }
    
    double minV = items[K-1].price;
    
    
    for(int i=K-1; i < N; i++)
    {
        ans += double(items[i].price);
        minV = min(minV, items[i].price);
    }
    
    if(items[K-1].type == 1)
    {
        ans -= minV;
        ans += minV * 0.5;
    }
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    cout<<setprecision(1)<<ans<<endl;
    
    for(int i=0; i < (K-1); i++)
    {
        cout<<"1 "<<items[i].idx<<endl;
    }
    
    cout<<(N - (K-1) )<<" ";
    for(int i = K-1; i < N; i++)
    {
        cout<<items[i].idx<<" ";
    }
    cout<<endl;
    
    return 0;
}