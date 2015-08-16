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

const int maxN = 10001;
const int maxCH = 26;
int N; //number of words
int M; //number of lists

/*
 letNum[i][j]
 = number of letter (j + 'a') in word i.
 It is encoded using binary code.
 For example,  if word i = "abca"
 letNum[i]['a'-'a'] = 2^3 + 2^0 = 8 + 1 = 9
 
 This way, two words with the same number of a character at different positions
 can be differentiated.
 For example, 
 word A = 'aba'
 word B = 'baa'
 letNum[A][a] = 2^2 + 2^0 = 4 + 1 = 5
 letNum[B][a] = 2^1 + 2^0 = 2 + 1 = 3
 */
int letNum[maxN][26];
string S[maxN];
int id[maxN];
int bestPt;
int bestID;
int curCH;
string L; //list of characters that Sean will use

bool compLen(int,int);
bool compLet(int, int);
void process();
void dfs(int, int, int, int);

int main()
{
    int T;
    cin>>T;
    for(int idx=1; idx <= T; idx++)
    {
        cout<<"Case #"<<idx<<": ";
        process();
        cout<<endl;
    }
    return 0;
}

bool compLen(int a, int b)
{
    return S[a].size() < S[b].size();
}

bool compLet(int a, int b)
{
    return letNum[a][L[curCH]-'a'] < letNum[b][L[curCH]-'a'];
}

void process()
{
    cin>>N>>M;
    for(int i=1; i <= N; i++)
    {
        cin>>S[i];
        id[i] = i;
    }
   
    memset(letNum, 0, sizeof(letNum));

    for(int i=1; i <= N; i++)
        for(int j=0; j < maxCH; j++)
            for(int k=0; k < S[i].size(); k++)
                if(S[i][k] == char('a' + j))
                    letNum[i][j] += (1<<k);

    for(int i=0; i < M; i++)
    {
        L.resize(maxCH, ' ');
        cin>>L;
        
        bestPt = 0;
        bestID = 1;
        
        dfs(1, N, -1, 0);
        cout<<S[bestID]<<" ";
    }
}

void dfs(int s, int t, int ch, int pt)
{
   // cout<<"dfs("<<s<<" , "<<t<<" , "<<ch<<" , "<<pt<<")"<<endl;
    if(s == t)
    {
        if( pt > bestPt || (pt == bestPt && id[s] < bestID) )
        {
            bestPt = pt;
            bestID = id[s];
           // cout<<"curBest : "<<S[id[bestID]]<<endl;
        }
        return;
    }
    
    //first time. divide words by their sizes
    if(ch == -1)
    {
        sort(id + s, id + t + 1, compLen);
        for(int i=s, j=s; i <= t; i++)
        {
            if(i == t || ( S[id[i]].size() != S[id[i+1]].size() ))
            {
                dfs(j, i, ch+1, pt);
                j = i+1;
            }
        }
    }
    else
    {
        curCH = ch;
        sort(id + s, id + t + 1, compLet);
        if(letNum[id[t]][L[ch] - 'a'] == 0)
            dfs(s,t,ch+1,pt);
        else
        {
            for(int i=s, j=s; i <= t; i++)
            {
                if( i==t || (letNum[id[i]][L[ch]-'a'] != letNum[id[i+1]][L[ch]-'a']) )
                {
                    //cout<<S[id[i]]<<" has "<<letNum[id[i]][L[ch]-'a']<<" "<<L[ch]<<endl;
                    dfs(j, i, ch+1, pt + ( (letNum[id[i]][L[ch]-'a'] == 0) ? 1 : 0));
                    j = i+1;
                }
            }
        }
    }
}