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
    int N;
    int C;
    int I; //number of items in the store
    
    cin>>N;
    int count = 1;
    while(count<=N)
    {
        cin>>C;
        cin>>I;
        vector<int> items(I,0);
        for(int i=0; i < I; i++)
            cin>>items[i];
        
        int a,b;
        for(int i=0; i < I-1; i++)
            for(int j=(i+1); j < I; j++)
            {
                if(i==j) continue;
                if( (items[i]+items[j]) == C)
                {
                    a = (i+1); b =(j+1); break;
                }
            }
        
        cout<<"Case #"<<count<<": "<<a<<" "<<b<<endl;
        
        count++;
    }
    return 0;
}