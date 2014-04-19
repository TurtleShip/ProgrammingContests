#include <cstdio>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;


class KleofasTail {
public:
    ll countGoodSequences(ll,ll,ll);
    
};

/*
 Outputs number of X where 0 <= X <= N
 and K is in Tail(X)
 */
ll solve(ll K, ll N) {
    ll res = 0ll;
    
    // trivial case. It should hold that K <= N
    if( K > N) return 0ll;
    
    ll left = K;
    ll delta = 2ll;
    ll right = min(N, K+delta-1ll);
    
    // corner case
    if( K == 0) {
        if(N == 0) return 1ll;
        if(N == 1) return 2ll;
        res+= 2ll;
        left = 2;
//        delta *= 2ll;
        right = min(N, left + delta - 1ll);
    }
    
    // we need to make K even
    if(K % 2 == 1) {
        res++;
        left = K * 2;
        right = min(N, left + delta - 1ll);
    }
    
    while(left <= N) {
        res += right - left + 1ll;
        left *= 2ll;
        delta *= 2ll;
        right = min(N, left + delta - 1ll);
    }
    
    return res;
}

ll KleofasTail::countGoodSequences(ll K, ll A, ll B) {
    
    ll res = 0ll;
    
    //trivial case
    if(B < K) return res;
//    printf("solve(K,B) == %lld , solve(K,A) == %lld\n", solve(K,B), solve(K,A-1));
    
    res = solve(K , B) - solve(K , A-1);
    return res;
}