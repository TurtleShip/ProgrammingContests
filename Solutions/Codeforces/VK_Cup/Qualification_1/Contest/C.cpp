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
    int N;
    cin>>N;
    cin.ignore(50,'\n');
    deque<string> Q;
    for(int idx=0; idx < N; idx++)
    {
        string cmd;
        getline(cin,cmd);
        
        
        if(cmd[0] == 'p')
        {
            cout<<"/";
            for(int i=0; i < Q.size(); i++)
                cout<<Q[i]<<"/";
            cout<<endl;
        }
        else
        {

            string cd = cmd.substr(3);
            bool reset = (cd[0] == '/');
            replace(cd.begin(), cd.end(), '/', ' ');

            stringstream ss;
            ss<<cd;
            string cur;
            if(reset) Q.clear();
            while(ss>>cur)
            {

                if(cur == "..")
                    Q.pop_back();
                else
                    Q.push_back(cur);
            }
        }
    }
    
    return 0;
}