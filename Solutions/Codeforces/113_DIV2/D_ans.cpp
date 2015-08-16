#pragma comment(linker, "/stack:64000000")
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <vector>
#include <bitset>
#include <string>
#include <deque>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb push_back
#define pii pair <int, int>
#define vi vector <int>
#define mp make_pair

template <typename X> inline X abs (const X &a) {return a < 0? -a: a;}
template <typename X> inline X sqr (const X &a) {return a * a;}

const int INF = INT_MAX / 2;
const ll INF64 = LLONG_MAX / 2LL;
const ld EPS = 1E-9, PI = 3.1415926535897932384626433832795;

const int N = 2 * 100 * 1000 + 13;

struct obj
{
    int cost, size, num;
    obj(){}
    obj (int cost, int size, int num): cost (cost), size (size), num (num) {}
};

inline bool cmpSize (const obj &a, const obj &b)
{
    return a.size < b.size;
}

inline bool cmpCost(const obj &a, const obj &b)
{
    return a.cost > b.cost;
}

vector <int> g[N];
int mt[N];
bool used[N];

bool khun (int v)
{
    if (used[v])
        return false;
    
    used[v] = true;
    forn (i, sz (g[v]))
    {
        int to = g[v][i];
        if (mt[to] == -1 || khun (mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    int n, m;
    obj a[N], b[N];
    
    ll cost[N];
    
    cin >> n;
    forn (i, n)
    {
        scanf ("%d%d", &a[i].cost, &a[i].size);
        a[i].num = i;
        cost[i] = a[i].cost;
    }
    
    sort (a, a + n, cmpSize);
    
    cin >> m;
    forn (i, m)
    {
        scanf ("%d%d", &b[i].cost, &b[i].size);
        b[i].num = i;
    }   
    
    forn (i, m)
    {
        int idx = int (lower_bound (a, a + n, obj (-1, b[i].size, -1), cmpSize) - a);
        
        while (a[idx].size == b[i].size || a[idx].size == b[i].size + 1)
        {
            if (a[idx].cost <= b[i].cost)
                g[a[idx].num].pb (b[i].num);
            
            idx++;
        }
    }
    
    sort (a, a + n, cmpCost);
    
    memset (mt, -1, sizeof mt);
    
    forn (i, n)
    {
        memset (used, false, sizeof used);
        khun (a[i].num);
    }
    
    ll ans = 0LL;
    vector <pii> res;
    
    forn (i, m)
    {
        if (mt[i] == -1)
            continue;
        
        ans += cost[mt[i]];
        res.pb (mp (i, mt[i]));
    }
    
    cout << ans << endl;
    cout << sz (res) << endl;
    
    forn (i, sz (res))
    printf ("%d %d\n", res[i].first + 1, res[i].second + 1);
    
    return 0;
}