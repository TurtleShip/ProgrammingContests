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

struct Formula
{
    /*
     state
     -1 : not handled
      0 : invalid case
      1 : valid case
     */
    int state;
    string A;
    string B;
    string C;
    
    Formula(int s = -1, string _A = "", string _B = "", string _C = "")
    {
        state = s;
        A = _A;
        B = _B;
        C = _C;
    }
    
    bool operator<(const Formula& other) const
    {
        if(this->A != other.A) return (this->A > other.A);
        if(this->B != other.B) return (this->B > other.B);
        return (this->C > other.C);
    }
};

//string opd1;
string A;
string ops;
string B;
//string opd2;
string eq;
//string opd3;
string C;

string output;
Formula dp[600][2];
int OFFSET = 300;
void process();
void dfs(int, int, int, int);

int main()
{
    int T;
    cin>>T;
    
    for(int idx=1; idx <= T; idx++)
    {
        cin>>A>>ops>>B>>eq>>C;
        process();
        cout<<"Case #"<<idx<<": "<<output<<endl;
    }
    
    return 0;
}

void process()
{
    //Initialize array
    REP(i,0,600)
        REP(j,0,2)
            dp[i][j] = Formula();

    dfs(A.size() - 1, B.size() - 1, C.size() - 1, 0);
    Formula ans = dp[A.size()-1+OFFSET][0];
    output = ans.A + " " + ops + " " + ans.B + " = " + ans.C;
}

void dfs(int aPos, int bPos, int cPos, int carry)
{
    Formula& cur = dp[aPos + OFFSET][carry];
    if(cur.state == -1)
    {
        cur.state = 0;
        if(aPos < 0 && bPos < 0)
        {
            if(ops == "+")
            {
                if(cPos < 0 && carry == 0) cur.state = 1;
                if(cPos == 0 && carry == 1 && (C[cPos] == '1' || C[cPos] == '?'))
                {
                    cur.state = 1;
                    cur.C = "1";
                }
            }
            else //ops == "-"
            {
                if(carry == 0 && cPos < 0) cur.state = 1;
            }
            return;
        }
        
        REP(i,0,10)
        {
            if(aPos < 0 && i != 0) continue;
            if(aPos == 0 && i == 0 && A.size() > 1) continue;
            if(aPos >= 0 && A[aPos] != '?' && (A[aPos] - '0' != i)) continue;
            
            REP(j,0,10)
            {
                if(bPos < 0 && j != 0) continue;
                if(bPos == 0 && j == 0 && B.size() > 1) continue;
                if(bPos >= 0 && B[bPos] != '?' && (B[bPos] - '0' != j)) continue;
                
                REP(k,0,10)
                {
                    if(cPos < 0 && k != 0) continue;
                    if(cPos == 0 && k == 0 && C.size() > 1) continue;
                    if(cPos >= 0 && C[cPos] != '?' && (C[cPos] - '0' != k)) continue;
                    
                    if(ops == "+")
                    {
                        //check the validity of the current values
                        if( (i + j + carry) % 10 != k) continue;
                        dfs(aPos-1,bPos-1,cPos-1, (i+j+carry)/10);
                    }
                    else //ops == "-"
                    {
                        if( (i - j - carry + 10) % 10 != k) continue;
                        dfs(aPos-1,bPos-1,cPos-1, !((i-j-carry+10)/10));
                    }
                    
                    Formula& next = (ops == "+") ? dp[aPos-1+OFFSET][(i+j+carry)/10] : dp[aPos-1+OFFSET][!((i-j-carry+10)/10)];
                    if(next.state == 0) continue;
                    
                    string newA = next.A;
                    string newB = next.B;
                    string newC = next.C;
                    
                    if(aPos >= 0) (newA).push_back(char(i+'0'));
                    if(bPos >= 0) (newB).push_back(char(j+'0'));
                    if(cPos >= 0) (newC).push_back(char(k+'0'));
                    
                    if(cur.state == 0 || newA < cur.A || (newA == cur.A && newB < cur.B)
                       || (newA == cur.A && newB == cur.B && newC < cur.C))
                    {
                        cur.state = 1;
                        cur.A = newA;
                        cur.B = newB;
                        cur.C = newC;
                    }
                    
                }
            }
        }

    }
}