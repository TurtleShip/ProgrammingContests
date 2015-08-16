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
typedef pair<int,int> PII;

typedef long long ll;

int main()
{
    int N,D;
    cin>>N>>D;
    
    map<string, vector< pair<string,int> > >logs;
    set< pair<string, string> >ans;
    
    REP(i,0,N)
    {
        string from,to;
        int time;
        cin>>from>>to>>time;
        
        if( ans.count( make_pair(from,to) ) || ans.count( make_pair(to,from) ))
            continue;
        
        bool isFriend = false;
        
        for(int j=0; j < logs[to].size(); j++)
            if(logs[to][j].first == from && 0 < (time - logs[to][j].second) && (time - logs[to][j].second) <= D)
            {
                isFriend = true;
                break;
            }
        
        if(isFriend)
        {
            ans.insert( make_pair(from,to) );
        }
        else
        {
            logs[from].push_back( make_pair(to,time) );
        }
    }
    
	cout<<ans.size()<<endl;
    set< pair<string,string> >::iterator itr;
    for(itr = ans.begin(); itr != ans.end(); itr++)
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    
    return 0;
}