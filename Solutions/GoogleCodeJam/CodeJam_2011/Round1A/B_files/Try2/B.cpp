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

int letNum[maxN][maxCH];
string S[maxN];
int id[maxN];
int N; //number of words in the dictionary and the number of lists to consider
int M; //number of words in the dictionary and the number of lists to consider
string L; //list of characters that Sean uses
int bestID;
int bestPt;
int C;

void process();
bool compLen(int, int);
bool compLet(int, int);
void dfs(int, int, int, int);

int main()
{
    int T;
    cin>>T;
    
    for(int idx=1; idx <=T; idx++)
    {
        cout<<"Case #"<<idx<<": ";
        process();
        cout<<endl;
    }
    
    return 0;
}

void process()
{
    cin>>N>>M;
    
    for(int i=1; i<=N; i++)
    {
        cin>>S[i];
        //id[i] = i;
    }
    
    memset(letNum, 0, sizeof(letNum));
    for(int i=1; i<=N; i++)
        for(int j=0; j < maxCH; j++)
            for(int k=0; k < S[i].size(); k++)
                if(S[i][k] == char('a' + j))
                    letNum[i][j] += (1<<k);

    for(int m=1; m<=M; m++)
    {
        cin>>L;
        
        for(int i=1; i <= N; i++)
            id[i] = i;
        bestPt = 0;
        bestID = 1;
        dfs(1, N, -1, 0);
        cout<<S[bestID]<<" ";
    }
}

bool compLen(int a, int b)
{
    return S[a].size() < S[b].size();
}

bool compLet(int a, int b)
{
    return letNum[a][C] < letNum[b][C];
}

void dfs(int s, int t, int idx, int pt)
{
	
    if(s == t) //only single element is left
    {
        if(pt > bestPt || (pt == bestPt && id[s] < bestID))
        {
            bestID = id[s];
            bestPt = pt;
        }
        return;
    }
    
    if(idx == -1)
    {
        sort(id+s, id+t+1, compLen);
        for(int b=s,a=s; b <= t; b++)
        {
            if(b == t || S[id[b]].size() != S[id[b+1]].size())
            {
                dfs(a, b, idx+1, pt);
                a = b+1;
            }
        }
    }
    else
    {
        C = L[idx] - 'a';
        int curC = C;
        sort(id+s, id+t+1, compLet);
        if(letNum[id[t]][C] == 0)
            dfs(s, t, idx+1, pt);
        else
        {
            for(int b=s,a=s; b <= t; b++)
            {
                if(b == t || letNum[id[b]][curC] != letNum[id[b+1]][curC])
                {
                   dfs(a, b, idx+1, pt + (letNum[id[b]][curC] == 0));
                    a = b + 1;
                }
            }
        }
        
    }
}
