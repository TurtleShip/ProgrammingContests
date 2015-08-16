#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;
typedef pair<string, string> ps;

#define OFFSET 300
//#define OFFSET 1
//( int, string, string, string  )
typedef pair<int, pair<ps, string> > data_t;

string op, A, B, C;
data_t DP[600][2];
int mode;

void dfs(int a, int b, int c, int carry) {
  data_t &res = DP[a + OFFSET][carry];
  if (res.F == -1) {
    res.F = 0;
      if (a < 0 && b < 0) { //Search reached the end
      if (mode == 0) { //+ , plus
        if (c < 0) { //result is also set
          if (carry == 0) {
            res.F = 1; //valid
            res.S.F.F = res.S.F.S = res.S.S = "";  
          }
        } else if (c == 0 && carry == 1) { //+ and there is a carry
          if (C[c] == '1' || C[c] == '?') {
            res.F = 1; //valid
            res.S.F.F = res.S.F.S = "";
            res.S.S = "1"; // a + b = 1
          }
        }
      } else { // - , minus
        if (carry == 0 && c < 0) { //no carry and search for c is over
          res.F = 1; //valid
          res.S.F.F = res.S.F.S = res.S.S = "";
        }
      }
      return;
    }
    
    int i, j, k;
    fr (i, 10) { //try all value from 0 to 9, inclusive
      if (a < 0 && i != 0) continue; 
      //no positive number starts with 0.  Only 0 itself is allowed to start with 0
      if (a == 0 && i == 0 && SZ(A) != 1) continue; 
      if (a >= 0 && A[a] != '?' && A[a] - '0' != i) continue; //Tried value must match what is already written for A
      fr (j, 10) { //same reasoning as A
        if (b < 0 && j != 0) continue;
        if (b == 0 && j == 0 && SZ(B) != 1) continue;
        if (b >= 0 && B[b] != '?' && B[b] - '0' != j) continue;
        fr (k, 10) { //same reasoning as B
          if (c < 0 && k != 0) continue;
          if (c == 0 && k == 0 && SZ(C) != 1) continue;
          if (c >= 0 && C[c] != '?' && C[c] - '0' != k) continue;

          if (mode == 0) { //+ , plus
            if ((i + j + carry) % 10 != k) continue;
//cout<<"a : "<<a<<" , b : "<<b<<endl;
//cout<<"i : "<<i<<" , j : "<<j<<endl;
            dfs(a - 1, b - 1, c - 1, (i + j + carry) / 10);
          } else { // - , minus
            if ((i - carry + 10 - j) % 10 != k) continue;
            dfs(a - 1, b - 1, c - 1, !((i - carry + 10 - j) / 10));
          }
          data_t &cmp = mode == 0 ? DP[a - 1 + OFFSET][(i + j + carry) / 10] :
                        DP[a - 1 + OFFSET][!((i - carry + 10 - j) / 10)];
          if (cmp.F == 0) continue;

          string AC = cmp.S.F.F, BC = cmp.S.F.S, CC = cmp.S.S;
          if (a >= 0) AC.pb((char)(i + '0'));
          if (b >= 0) BC.pb((char)(j + '0'));
          if (c >= 0) CC.pb((char)(k + '0'));
          if (res.F == 0 || res.S.F.F > AC ||
              (res.S.F.F == AC && res.S.F.S > BC) ||
              (res.S.F.F == AC && res.S.F.S == BC && res.S.S > CC)) {
            res.F = 1;
            res.S.F.F = AC, res.S.F.S = BC, res.S.S = CC;
          }
        }
      }
    }
  }
}

/*
 typedef pair<int, pair<ps, string> > data_t;
 ( int, string a, string b, string c )
 a + b = c
 */
void process(int op) {
  int i, j;
  fr (i, 600) fr (j, 2) DP[i][j] = MP(-1, MP(MP("", ""), ""));
  int a = SZ(A) - 1, b = SZ(B) - 1, c = SZ(C) - 1;
  mode = op;
  dfs(a, b, c, 0);
  data_t &res = DP[a + OFFSET][0];
  cout << res.S.F.F << (op == 0 ? " + " : " - ") << res.S.F.S <<
      " = " << res.S.S << endl;
}

int main() {
  int total_cases, case_num = 0;
  cin >> total_cases;
  string eq;
  while (case_num < total_cases) {
    cin >> A >> op >> B >> eq >> C;
    case_num++;
    cout << "Case #" << case_num << ": ";
    if (op == "+") process(0);
    else process(1);
  }
  return 0;
}
