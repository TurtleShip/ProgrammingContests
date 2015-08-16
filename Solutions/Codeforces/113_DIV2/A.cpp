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

bool sortScore( pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N,K;
    cin>>N>>K;
    
    vector< pair<int,int> > score(N);
    
    REP(i,0,N)
    {
        int p,t;
        cin>>p>>t;
        score.push_back( make_pair(p,t) );
    }

    sort( score.begin(), score.end(), sortScore );
    
    pair<int,int> sc = score[K-1];
    int same = 0;
    for(int i=0; i < N; i++)
        if(score[i] == sc)
            same++;
    
    cout<<same<<endl;
    
    return 0;
}