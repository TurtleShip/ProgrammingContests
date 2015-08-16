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

typedef long long ll;

set<int> order[110]; //order[i] contains list of tasks that  come before i
bool isDone[110];

int main()
{
    int n,m;
    int before, after;

    while(cin>>n>>m) {
        
        if(n == 0 && m == 0) {
            break;
        }

        for(int i=1; i <= n; i++) {
            order[i] = set<int>();
            isDone[i] = false;
        }

        while(m--) {
            cin>>before>>after;
            order[after].insert(before);
        }
        // brute force...  100 is small enough.
        // for(int i=1;  i <= n; i++) {
        //     cout<<"order["<<i<<"] : "<<order[i].size()<<endl;
        // }

        int ct = 0;
        while(ct < n) {
            vector<int> curDone;

            for(int i=1; i <= n; i++) {
                // all pre-req has been met
                if(order[i].size() == 0 && !isDone[i]) {
                    if(ct != 0) cout<<" ";
                    cout<<i;
                    ct++;
                    isDone[i] = true;
                    curDone.push_back(i);
                }
            }

            // erase done tasks from pre-req
            for(int i=1; i <= n; i++) {
                if(order[i].size() != 0) {
                    for(int j=0; j < curDone.size(); j++) {
                        order[i].erase(curDone[j]);
                    }

                }
            }
        }
        cout<<endl;

    }



    return 0;

}
