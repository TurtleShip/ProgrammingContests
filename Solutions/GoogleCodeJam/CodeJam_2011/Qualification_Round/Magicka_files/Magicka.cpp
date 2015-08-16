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
    int T;
    cin>>T;
    
    for(int idx = 1; idx <= T; idx++)
    {
        int C;
        cin>>C;
        map< pair<char,char> , char> mix;
        while(C--)
        {
            string str;
            cin>>str;
            mix[ make_pair(max(str[0],str[1]), min(str[0],str[1])) ] = str[2];
        }
        
        vector< pair<char,char> >cancel;
        int D;
        cin>>D;
        while(D--)
        {
            string str;
            cin>>str;
            cancel.push_back( make_pair(max(str[0], str[1]), min(str[0],str[1])) );
        }
        
        int N;
        cin>>N;
        string str;
        cin>>str;
        vector<char> magic;
        for(int i=0; i < N; i++)
        {
            magic.push_back(str[i]);
            int M = magic.size();
            if(M >= 2)
            {
                pair<char,char> last = make_pair(max(magic[M-2], magic[M-1]), min(magic[M-2], magic[M-1]));
                if(mix.count(last) > 0)
                {
                    vector<char>::iterator itr;
                    itr = magic.end();
                    itr--; itr--;
                    magic.erase(itr, magic.end());
                    magic.push_back(mix[last]);
                }
                
                M = magic.size();
                bool canceled = false;
                for(int i=0; !canceled && i < M-1; i++)
                {
                    for(int j=(i+1); j < M; j++)
                    {
                        if(count(cancel.begin(), cancel.end(), make_pair( max(magic[i], magic[j]), min(magic[i], magic[j]) )) > 0)
                        {

                            magic.clear();
                            break;
                        }
                    }
                }
            }
        }
        
        int M = magic.size();
        cout<<"Case #"<<idx<<": [";
        for(int i=0; i < M; i++)
        {
            if(i == M - 1)
            {
                cout<<magic[M-1];
            }
            else
            {
                cout<<magic[i]<<", ";
            }
        }
        cout<<"]"<<endl;
    }
    return 0;
}