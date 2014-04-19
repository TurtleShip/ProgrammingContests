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
const int maxN = 100000;

struct Cube
{
    int idx;
    ll height;
    Cube(int i = -1, ll h = -1)
    {
        idx = i;
        height = h;
    }
};

map< ll, vector<Cube> > cubes;
map< ll, int> idxs;
ll maxSize[maxN+10][maxN+10];
ll H[maxN+10];

bool sortCube(Cube a, Cube b)
{
    return a.height > b.height;
}

int main()
{
    int N;
    cin>>N;
    
    for(int i=0; i < N; i++)
    {
        ll c,s;
        cin>>c>>s;
        cubes[c].push_back(Cube(i+1, s));
    }
    
    map< ll, vector<Cube> >::iterator itr;
    int cnt = 0;
    for(itr = cubes.begin(); itr != cubes.end(); itr++, cnt++)
    {
        sort((*itr).second.begin(), (*itr).second.end(), sortCube);
        idxs[cnt] = (*itr).first;
        H[cnt] = (*itr).second.size();
        maxSize[cnt][1] = (*itr).second[0].height;
        for(int i=2; i <= (*itr).second.size(); i++)
            maxSize[cnt][i] = maxSize[cnt][i-1] + (*itr).second[i-1].height;
    }
    
    
    int bestA = 0;
    int bestB = 0;
    ll ans = -1;
    for(int i=0; i < cnt; i++)
    {
        for(int j= 0; j < cnt; j++)
        {
			if(i == j) continue;
            ll minH = min(H[i], H[j]);
            ll cur = 0;
            if(H[i] == H[j])
            {
                cur = maxSize[i][minH] + maxSize[j][minH];
            }
            
            if(H[i] < H[j])
            {
                cur = maxSize[i][minH] + maxSize[j][minH+1];
            }
            
            if(H[i] > H[j])
            {
                cur = maxSize[i][minH+1] + maxSize[j][minH];
            }
            
            if(ans < cur)
            {
                ans = cur;
                bestA = i;
                bestB = j;
            }
        }
    }
    
    cout<<ans<<endl;
    
    ll minH = min(H[bestA], H[bestB]);
    ll maxH = min( minH + 1, max(H[bestA], H[bestB]));
    
    cout<<(minH + maxH)<<endl;
    
  //  cout<<"bestA : "<<bestA<<" , bestB : "<<bestB<<endl;
//cout<<"idxs[bestA] : "<<idxs[bestA]<<" , idxs[bestB] : "<<idxs[bestB]<<endl;
//cout<<"minH : "<<minH<<" , maxH : "<<maxH<<endl;
    if(H[bestA] > H[bestB])
    {
        swap(bestA, bestB);
    }
    
    for(int i=0; i < minH; i++)
    {
        cout<<cubes[idxs[bestB]][i].idx;
        cout<<" "<<cubes[idxs[bestA]][i].idx<<" ";
    }
   // cout<<"\nminprintDone"<<endl;
    if(minH < maxH)
        cout<<cubes[idxs[bestB]][minH].idx<<endl;
    else 
        cout<<endl;


    
    
    return 0;
}