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


/*
 Maximum case
 str1 + str2 = str3;
 Length of str1, str2 = 82
 Length of str3 = 83
 */
ll toNum(string str)
{
    stringstream ss;
    ss<<str;
    ll num;
    ss>>num;
    return num;
}

int main()
{
    int T;
    cin>>T;

    ll pow10[13];
    pow10[0] = 1;
    for(int i=1; i < 13; i++)
        pow10[i] = pow10[i-1] * 10ll;
    
    for(int idx=1; idx <= T; idx++)
    {
        vector<string> opd(2,""); //operands
        string ops, igno, res;
        cin>>opd[0];
        cin>>ops;
        cin>>opd[1];
        cin>>igno;
        cin>>res;
        //cout<<"INIT #"<<idx<<": "<<opd[0]<<" "<<ops<<" "<<opd[1]<<" = "<<res<<endl;
        vector< vector<int> > quesPos;
        for(int i=0; i < 2; i++)
        {
            vector<int> cur;
            for(int j=0; j < opd[i].size(); j++)
            {
                if(opd[i][j] == '?')
                    cur.push_back(j);
            }
            quesPos.push_back(cur);
        }
        
        ll fiBegin = 0ll;
        ll seBegin = 0ll;
        int F = quesPos[0].size();
        int S = quesPos[1].size();
        ll ct = 1;
        
        if(opd[0].size() > 1 && quesPos[0].size() > 0)
        {
            if(quesPos[0][0] == 0)
                fiBegin = pow10[F - 1];
        }

        if(opd[1].size() > 1 && quesPos[1].size() > 0)
        {
            if(quesPos[1][0] == 0)
                seBegin = pow10[S - 1];
        }


        bool found = false;
        for(ll i = fiBegin; !found && i < pow10[F]; i+=1ll)
        {
            ll curI = i;
            for(int a = F-1; a >= 0; a--)
            {
                opd[0][quesPos[0][a]] = char( (curI%10) + '0');
                curI /= 10ll;
            }
 
            
            for(ll j = seBegin; !found && j < pow10[S]; j+=1ll)
            {
                ll curJ = j;
                for(int a = S-1; a>=0; a--)
                {
                    opd[1][quesPos[1][a]] = char( (curJ%10) + '0');
                    curJ /= 10ll;
                }
cout<<(ct++)<<endl;
                
                ll curF = toNum(opd[0]);
                ll curS = toNum(opd[1]);
                ll curRes = 0;
                if(ops == "+")
                {
                    curRes = curF + curS;
                }
                else
                {
                    curRes = curF - curS;
                }
                
                string resStr;
                stringstream ss5;
                ss5<<curRes;
                ss5>>resStr;
     
                
                if(resStr.size() == res.size() && curRes >= 0)
                {
                    bool valid = true;
                    for(int q = 0; q < res.size(); q++)
                    {
                        if(res[q] != '?' && res[q] != resStr[q])
                        {
                            valid = false;
                            break;
                        }
                    }
                    if(valid)
                    {
                        res = resStr;
                        found = true;
                        break;
                    }
                }
                
            }
        }
        cout<<"Case #"<<idx<<": "<<opd[0]<<" "<<ops<<" "<<opd[1]<<" = "<<res<<endl;
    }
    
    
    return 0;
}