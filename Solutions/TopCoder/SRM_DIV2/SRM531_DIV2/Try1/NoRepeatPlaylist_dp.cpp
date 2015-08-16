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
int INF = numeric_limits<int>::max();
int nINF = numeric_limits<int>::min();
typedef long long ll;
 
class NoRepeatPlaylist {
public:
	int numPlaylists(int, int, int);
};

int mod = 1000000007;

int NoRepeatPlaylist::numPlaylists(int N, int M, int P) {
    /*
     1 <= i <= P   , 1 <= j <= N
     dp[i][j]
     = number of ways to make a playlist whose length == i using
     j different songs
     
     = add a new song + add an already added song
     
     = (number of ways to make a playlist whose length == (i-1) using
     (j-1) different songs) * (number of avilable new songs)
     
     + (number of ways to make a playlist whose length == (i-1) using
     j different songs) * (number of already added songs whose 
     previously appearance is at least M songs away from position j)
     
     =dp[i-1][j-1] * (N - (j - 1)) 
     + dp[i-1][j] * max(j-M, 0)
     
     Ans
     = dp[P][N]
     = number of ways to make a playlist whose length == P
     using N different songs
     
     It is hard to understand max(j-M,0) at first sight.
     j is the number of different songs used at position[1...i-1].
     We want to add one of songs from postion[1..i-1] to position i.
     
     If M == 0, we can use any one of j songs.
     Let's see what happens when M == 1.
     This means we cannot use songs from position (i-1).
     Any one of j songs can be at that position.
     So we can use only (j - 1) songs.
     Expand this logic to M == M, and we can use (j-M).
     
     Notice that if M >= j, we cannot add any existing song to position i
     because we have not used enough different songs.
     
     Base
     dp[0][0] = number of ways to make an empty playlist using 0 song.
     = 1
     */

    ll dp[P+1][N+1];
    
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1ll;
    
    for(int i = 1; i <= P; i++)
        for(int j = 1; j <= N; j++)
            dp[i][j] = ( (dp[i-1][j-1] * (N - (j-1))) % mod + (dp[i-1][j] * max(j-M,0)) % mod ) % mod;
    
    return dp[P][N];
    
}
