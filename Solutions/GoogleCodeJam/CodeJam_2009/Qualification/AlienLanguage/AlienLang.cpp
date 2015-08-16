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
    int L,D,N;
    cin>>L; cin>>D; cin>>N;
    
    vector<string> words;
    
    for(int i=0; i < D; i++)
    {
        string str;
        cin>>str;
        words.push_back(str);
    }
    
    for(int i=1; i <= N; i++)
    {
        vector< vector<char> >candi(L, vector<char>());
        string str;
        cin>>str;
        bool meetParen = false;
        int idx = 0;
        for(int j=0; j < str.size(); j++)
        {
            if(str[j] == '(')
            {
                meetParen = true;
            }
            else if(str[j] == ')')
            {
                meetParen = false;
                idx++;
            }
            else
            {
                candi[idx].push_back(str[j]);
                if(!meetParen)
                {
                    idx++;
                }
            }
        }
        int cur = 0;
        for(int i=0; i < D; i++)
        {
            bool hasWord = true;
            for(int j=0; j < L; j++)
            {
                if(count(candi[j].begin(), candi[j].end(), words[i][j]) == 0)
                {
                    hasWord = false;
                    break;
                }
            }
            if(hasWord) cur++;
        }
        
        cout<<"Case #"<<i<<": "<<cur<<endl;
        
    }
    return 0;
}