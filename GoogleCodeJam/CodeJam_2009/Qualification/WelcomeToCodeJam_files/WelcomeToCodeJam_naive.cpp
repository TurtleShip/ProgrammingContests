.#include <vector>
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
int mod = 10000;
string sen;
string target = "welcome to code jam";
int N;
int targetLen = 19;

int getCombo(int idx, int place)
{
    if(place == targetLen)
        return 1;
    
    if(idx == N)
        return 0;
  
    int ans = 0;
 
    ans += getCombo(idx+1, place) % mod;
    
    if(sen[idx] == target[place])
        ans += getCombo(idx+1, place+1) % mod;
        
    return ans % mod;
}


int main()
{
    int T;
    cin>>T;
    cin.ignore(250, '\n');

    for(int idx=1; idx <= T; idx++)
    {
        sen = "";
        getline(cin, sen);
        N = sen.size();

        ll ans = getCombo(0,0);
        string str;
        stringstream ss;
        ss<<ans;
        ss>>str;
        int S = str.size();
        if(S < 4)
        {
            if(S == 0) str = "0000";
            if(S == 1) str = "000" + str;
            if(S == 2) str = "00" + str;
            if(S == 3) str = "0" + str;
        }
        cout<<"Case #"<<idx<<": "<<str<<endl;
    }
    return 0;
}