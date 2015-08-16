#include <vector>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;

class PastingPaintingDivOne {
public:
    vector<long long> countColors(vector <string>, int);
};


vector<long long> PastingPaintingDivOne::countColors(vector <string> board, int iT) {
    int R = board.size();
    int C = board[0].size();
    ll T = (ll)iT;
    vector<ll>res(3, 0ll);
    map<char,int> M;
    M['R'] = 0;
    M['G'] = 1;
    M['B'] = 2;
    
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(board[r][c] != '.') {
                int prev = -1;
//                printf("r = %d, c = %d\n", r, c);
                for(int k = 1; k <= min(r,c); k++) {
//                    printf("k = %d , board[r-k][c-k] = %c \n", k, board[r-k][c-k]);
                    if(board[r-k][c-k] != '.') {
                        prev = k;
                        break;
                    }
                }
                int curRes = 0;
                if(prev == -1) {
                    curRes += T;
                } else {
                    if(prev > (T-1)) curRes +=T;
                    else curRes = prev;
                }
//                printf("color = %c , curRes = %d, prev = %d\n", board[r][c], curRes, prev);
                res[M[board[r][c]]] += curRes;
            }
        }
    }
    
    return res;
}