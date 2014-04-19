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
    //cin.ignore(50,'\n');
    ll pow10[13];
    pow10[0] = 1;
    for(int i=1; i < 13; i++)
        pow10[i] = pow10[i-1] * 10ll;
    
    for(int idx=1; idx <= T; idx++)
    {
        vector<string> opd(3,""); //operands
        string ops, igno;
        cin>>opd[0];
        cin>>ops;
        cin>>opd[1];
        cin>>igno;
        cin>>opd[2];
        
        vector< vector<int> > quesPos;
        for(int i=0; i < 3; i++)
        {
            vector<int> cur;
            for(int j=0; j < opd[i].size(); j++)
            {
                if(opd[i][j] == '?')
                    cur.push_back(j);
            }
            quesPos.push_back(cur);
        }
        
        int M = quesPos.size();
        
        ll brute = 0ll;
        if(

        for(brute = 0ll; brute < pow10[M]; brute+=1ll)
        {
            ll cur = brute;
            for(int i=M-1; i >= 0; i--)
            {
                opd[quesPos[i].first][quesPos[i].second] = char((cur % 10) + '0');
                cur /= 10;
            }
          //  cout<<"cur : "<<opd[0]<<" "<<ops<<" "<<opd[1]<<" = "<<opd[2]<<endl;
            //check validity
            bool valid = true;
            for(int i=0; i < 3; i++)
            {
                if(opd[i][0] == '0' && opd[i].size() > 1)
                {
                    valid = false;
                    break;
                }
            }
            
            if(valid)
            {
                ll fi, se, la;
                fi = toNum(opd[0]);
                se = toNum(opd[1]);
                la = toNum(opd[2]);
                
                if(ops == "+")
                {
                    if( (fi + se) == la)
                    {
                        break;
                    }
                    
                }
                else
                {
                    if((fi - se) == la)
                    {
                        break;
                    }                    
                }
            }
        }
        
        cout<<"Case #"<<idx<<": "<<opd[0]<<" "<<ops<<" "<<opd[1]<<" = "<<opd[2]<<endl;

    }
    
    
    return 0;
}