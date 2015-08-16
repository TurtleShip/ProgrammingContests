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

void process();

int main() {
  int case_num = 0, total_cases;
  cin >> total_cases;
  while (case_num < total_cases) {
    case_num++;
    cout << "Case #" << case_num << ": ";
    process();
  }
  return 0;
}

void process() {
  ll months, days, week;
  cin >> months >> days >> week;
  ll st = 0;
  ll res = 0, plus = 0, cnt = 0;
  
  do {
    st += days;
    plus += st / week + (st % week == 0 ? 0 : 1);
    st %= week;
    cnt++;
  } while (st != 0 && cnt < months);
  
  if (cnt == months) {
    cout << plus << endl;
  } else {
    res = months / cnt * plus;
    months %= cnt;
    st = cnt = 0;
    while (cnt < months) {
      st += days;
      res += st / week + (st % week == 0 ? 0 : 1);
      st %= week;
      cnt++;
    }
    cout << res << endl;
  }
}
