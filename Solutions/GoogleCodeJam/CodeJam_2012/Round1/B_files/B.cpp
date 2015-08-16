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

const int maxN = 1010;
int arr[maxN][2];
bool fin[maxN][2];

int main()
{
    ios_base::sync_with_stdio(false);
    
    int T;
    cin>>T;
    
    for(int idx=1; idx <= T; idx++)
    {
        memset(fin, false, sizeof(fin));
        int N;
        cin>>N;
        
        for(int i=0; i < N; i++)
        {
            cin>>arr[i][0]>>arr[i][1];
        }
        
        int res = 0;
        int lvl2 = 0;
        int stars = 0;
        bool isValid = true;
        while(lvl2 < N && isValid)
        {
            bool solved = false;
            //try finishing level two
            for(int i=0; !solved && i < N; i++)
                if(!fin[i][1] && stars >= arr[i][1])
                {
                    fin[i][1] = true;
                    lvl2++;
                    solved = true;
                    if(fin[i][0]) stars++;
                    else
                    {
                        fin[i][0] = true;
                        stars += 2;
                    }
                    
                }
            
            //try finishing level one
            int l2 = -1;
            int who = -1;
            
            for(int i=0; !solved && i < N; i++)
                if(!fin[i][0] && stars >= arr[i][0] && arr[i][1] > l2)
                {
                    who = i;
                    l2 = arr[i][1];
                }
            
            if(!solved && who != -1)
            {
                fin[who][0] = true;
                solved = true;
                stars++;
            }
            
            res++;
            if(!solved) isValid = false;
        }
        
        cout<<"Case #"<<idx<<": ";
        if(isValid) cout<<res<<endl;
        else cout<<"Too Bad"<<endl;
    }

    return 0;
}