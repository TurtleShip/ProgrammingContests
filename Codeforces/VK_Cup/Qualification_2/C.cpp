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

const int maxCh = 26; //number of lowercase letters
const int maxP = 200000;
//int pos[maxCh][maxP+1];
int len[maxCh];
//vector<int> pos[maxCh];
/*
 pos[i][j] = jth character i is at (first) series , (second) index
 */
vector< pair<int,int> > pos[maxCh];

int main()
{
    memset(len, 0, sizeof(len));
    
    int K, C;
    string S;
    
    cin>>K;
    cin>>S;
    cin>>C;
    
    int N = S.size();
    
    set<int> chs;
    vector<string> ans(K, S);
    
    REP(i,0,maxCh)
    pos[i].resize(110);
    
    REP(i,0,N)
    {
        int cur = S[i] - 'a';
        pos[cur][++len[cur]] = make_pair(0,i);
        chs.insert(cur);
    }
    
    set<int>::iterator itr;
    for(itr = chs.begin(); itr != chs.end(); itr++)
    {
        int cur = *itr;
        pos[cur].resize(K*len[cur]+10);
        
        for(int i=1; i < K; i++)
        {
            for(int j=1; j <= len[cur]; j++)
            {
                pos[cur][j+i*len[cur]] = make_pair(i, pos[cur][j].second);
            }
        }
    }

    REP(x,0,C)
    {
        int p;
        char c;
        cin>>p>>c;
        
        int cur = c - 'a';
        ans[pos[cur][p].first][pos[cur][p].second] = ' ';
        pos[cur].erase( pos[cur].begin() + p);
    }
    
    
    for(int i=0; i < K; i++)
        for(int j=0; j < N; j++)
            if(ans[i][j] != ' ')
                cout<<ans[i][j];
    cout<<endl;
    
    return 0;
}