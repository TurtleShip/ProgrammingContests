#include <cstdio>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;


class KleofasTail {
public:
    ll countGoodSequences(ll,ll,ll);
    
};

// uses too much memory
ll KleofasTail::countGoodSequences(ll K, ll A, ll B) {
    
    ll res = 0ll;
    
    //trivial case
    if(B < K) return res;
    
    //corner case
    if(K == 0) {
        K++;
        res++;
    }
    
    queue<ll> Q;
    set<ll> S;
    Q.push(K);
    S.insert(K);
    if( A <= K && K <= B)
        res++;
    
    /*while(!Q.empty()) {
        ll cur = Q.front(); Q.pop();
        ll nextK = 2ll * cur;
        if(S.count(nextK) == 0 && nextK <= B) {
            Q.push(nextK);
            if(A <= nextK) res++;
        }
        
        if(cur % 2ll == 0) {
            nextK = cur + 1ll;
            if(S.count(nextK) == 0 && nextK <= B) {
                Q.push(nextK);
                if(A <= nextK) res++;
            }
        }
    }*/
    while(!Q.empty()) {
        ll cur = Q.front(); Q.pop();
//        printf("cur = %lld\n",cur);
        ll nextK = 2ll * cur;
        if( nextK <= B ) {
            Q.push(nextK);
            if( A <= nextK ) res++;
        }
        
        if( cur % 2ll == 0 ) {
            nextK = cur + 1ll;
            if(nextK <= B) {
                Q.push(nextK);
                if(A <= nextK) res++;
            }
        }
    }
    
    return res;
}