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

int main()
{
    int K,N;
    string S;
    
    cin>>K>>S>>N;
    
    //dic[i] = number of apperances of character 'i' in S
    map<char, int> dic;
    //loc[ i,j ] = returns the index of (j)th occurence of character 'i'
    map< pair<char,int> , int> loc; 

    vector<string> ans(K, S);
    
    for(int i=0; i < S.size(); i++)
    {
        dic[S[i]]++;
        loc[ make_pair(S[i], dic[S[i]] - 1) ] = i;
		cout<<"loc[ ("<<S[i]<<" , "<<dic[S[i]]-1<<") ] = "<<i<<endl;
    }
    
    
    REP(x,0,N)
    {
        int idx;
        char ch;
        cin>>idx>>ch;
        
        int who = (idx - 1) / dic[ch];
        int nId = (idx - 1) % dic[ch];
        
cout<<"who : "<<who<<" , nId : "<<nId<<endl;

        ans[who][loc[make_pair(ch,nId)]] = ' ';
        
    }

REP(i,0,K)
    cout<<ans[i]<<endl;

    
	REP(i,0,K)
	REP(j,0,ans[i].size())
	if(ans[i][j] != ' ')
	cout<<ans[i][j];
	cout<<endl;    
    
    return 0;
}