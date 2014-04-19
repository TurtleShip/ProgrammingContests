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

map< char, char > mem;
void fillMem();
int main()
{
    ios_base::sync_with_stdio(false);
    fillMem();
    int T;
    cin>>T;
    cin.ignore(250,'\n');
    
    for(int idx = 1; idx <= T; idx++)
    {
        string S;
        getline(cin,S);
        cout<<"Case #"<<idx<<": ";
        for(int i=0; i < S.size(); i++)
            cout<<mem[S[i]];
        cout<<endl;
    }
    
    return 0;
}

void fillMem()
{
    mem[' '] = ' ';
    mem['a'] = 'y';
    mem['b'] = 'h';
    mem['c'] = 'e';
    mem['d'] = 's';
    mem['e'] = 'o';
    mem['f'] = 'c';
    mem['g'] = 'v';
    mem['h'] = 'x';
    mem['i'] = 'd';
    mem['j'] = 'u';
    mem['k'] = 'i';
    mem['l'] = 'g';
    mem['m'] = 'l';
    mem['n'] = 'b';
    mem['o'] = 'k';
    mem['p'] = 'r';
    mem['q'] = 'z';
    mem['r'] = 't';
    mem['s'] = 'n';
    mem['t'] = 'w';
    mem['u'] = 'j';
    mem['v'] = 'p';
    mem['w'] = 'f';
    mem['x'] = 'm';
    mem['y'] = 'a';
    mem['z'] = 'q';
}