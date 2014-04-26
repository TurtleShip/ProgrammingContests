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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define pb(x) push_back(x)

typedef long long LL;
int INF = 500;

int main() {
    int N; // number of devices
    int L; // number of electric flows
    int T; // number of test cases

    cin>>T;
    string notPossible = "NOT POSSIBLE";
    string cur;
    for(int cid=1; cid <= T; cid++) {
    	cin>>N>>L;
    	vector<string> initConfig(N, "");
    	vector<string> needed(N, "");
    	for(int i=0; i < N; i++)
    		cin>>initConfig[i];

    	for(int i=0; i < N; i++)
    		cin>>needed[i];
    	
    	sort(needed.begin(), needed.end());

        bool found = false;
        int best = INF;

        for(int i=0; i < N; i++) {
            vector<bool> shouldFlip(L);
            int curRes = 0;
        
            for(int j=0; j < L; j++) {
                shouldFlip[j] = initConfig[0][j] != needed[i][j];
                if(shouldFlip[j]) curRes++;
            }
        
            vector<string> curConfig(initConfig.begin(), initConfig.end());
            
            for(int j=0; j < N; j++) {
                for(int k=0; k < L; k++) {
                    if(shouldFlip[k]) {
                        curConfig[j][k] = (curConfig[j][k] == '0') ? '1' : '0';
                    }
                }
            }
                
            sort(curConfig.begin(), curConfig.end());


            if(curConfig == needed) {
                found = true;
                best = min(best, curRes);
            }
        }

        cout<<"Case #"<<cid<<": ";
        if(found) cout<<best<<endl;
        else cout<<"NOT POSSIBLE"<<endl;
    }

    return 0;
}
