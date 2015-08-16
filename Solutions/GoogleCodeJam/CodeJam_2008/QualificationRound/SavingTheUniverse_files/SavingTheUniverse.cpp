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
        int S;
        cin>>S;
        vector<string> engine(S,"");
        cin.ignore(50,'\n');
        for(int i=0; i < S; i++)
            getline(cin,engine[i]);
        
        int Q;
        cin>>Q;
        vector<string> query(Q, "");        
        cin.ignore(50,'\n');
        for(int i=0; i < Q; i++)
            getline(cin,query[i]);
        
        int count = 0;
        set<string> search;
        for(int i=0; i < Q; i++)
        {
            search.insert(query[i]);
            if(search.size() == S)
            {
                count++;
                search.clear();
                search.insert(query[i]);
            }
        }
        
        cout<<"Case #"<<idx<<": "<<count<<endl;
    }
    
    return 0;
}