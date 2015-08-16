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

#define REP(i,a,b) for(int i=a; i < b; i++)
#define REPE(i, a, b) for(int i=a; i <=b; i++)

typedef long long ll;

int U,N,A,B;
int resA, resB;
int finalA, finalB;
int Apos, Bpos;
string ans;
int yut[20];
void process();
void simulate();

int main()
{
    int T;
    cin>>T;
    for(int idx=1; idx <= T; idx++)
    {
       // cout<<"Case #"<<idx<<" input"<<endl;
        process();
        cout<<"Case #"<<idx<<": "<<ans<<endl;
    }
    
    
    return 0;
}

void process()
{
    cin>>U>>N>>A>>B;
    
    /*
     U : U는 한 팀에서 사용가능한 말의 수
     N : N는 던져진 윷의 목록 갯수
     A : A는 판 위에 놓여 있는 A팀 말의 갯수
     B : B는 판 위에 놓여 있는 B팀 말의 갯수
     Two possibilities
     1. A starts first
     2. B starts first
     */
    
    //cout<<U<<" "<<N<<" "<<A<<" "<<B<<endl;
    

    REP(i,0,N)
    {
        string cur;
        cin>>cur;
        if(cur == "Do") yut[i] = 1;
        if(cur == "Gae") yut[i] = 2;
        if(cur == "Gul") yut[i] = 3;
        if(cur == "Yut") yut[i] = 4;
        if(cur == "Mo") yut[i] = 5;
       // cout<<cur<<endl;
    }
    
    //small => one unit.
    resA = 0;
    resB = 0;
    Apos = 0;
    Bpos = 0;
    
    finalA = 0;
    finalB = 0;
    
    if(A != 0)
    {
        cin>>finalA;
        //cout<<finalA;
    }//else //cout<<endl;
    
        
    if(B != 0) 
    {
        cin>>finalB;
       // cout<<finalB;
    }
    //else
       // cout<<endl;
    

    simulate();

}


void simulate()
{   
    bool isA = true;
    bool win = false;
    bool valid = true;
    REP(i,0,N)
    {
	
//cout<<"i : "<<i<<" , "<<"move : "<<yut[i]<<endl;
//if(isA) cout<<"A move"<<endl;
//else cout<<"B move "<<endl;

        if(win)
        {
            valid = false;
            break;
        }
        if(isA)
        {
            resA = 1;
            int prev = Apos;

            Apos += yut[i];
            if(prev == 5)
                Apos += 14;

			if(prev == 10)
            {
                if(yut[i] <= 2) Apos += 14;
                if(yut[i] == 3) Apos = 22;
                if(yut[i] >= 4) Apos += 13;
            }
            
            if(prev == 22)
                Apos += 4;
            
            
            if(20 <= prev && prev <= 24 && prev != 22 && 24 < Apos)
                Apos -= 10;
            
            if( 15 <= prev && prev <= 19 )
            {
                if(Apos == 20) Apos = 29;
                else if(Apos > 20)
                {
                    win = true;
                }
            }
            
            if( (prev == 25 && yut[i] == 2) || (prev == 26 && yut[i] == 1))
                Apos = 22;
            
            if( (prev==25 || prev==26) && Apos >= 28)
                Apos--;
            
            
            if((prev == 22 || 25 <= prev) && Apos > 29)
                win = true;
            
            bool gotB = false;
            //catch
            if(Apos == Bpos)
            {
                Bpos = 0;
                gotB = true;
                resB = 0;
            }
            if(win)
                resA = 0;
            
            if( !(yut[i] == 4 || yut[i] == 5 || gotB) )
                isA = false;
        }
        else
        {
            resB = 1;
            int prev = Bpos;
            
            Bpos += yut[i];
            if(prev == 5)
                Bpos += 14;
            
            if(prev == 10)
            {
                if(yut[i] <= 2) Bpos += 14;
                if(yut[i] == 3) Bpos = 22;
                if(yut[i] >= 4) Bpos += 13;
            }
            
            if(prev == 22)
                Bpos += 4;
            
            if(20 <= prev && prev <= 24 && prev != 22 && 24 < Bpos)
                Bpos -= 10;
            
            if(15 <= prev && prev <= 19 )
            {
                if(Bpos == 20) Bpos = 29;
                else if(Bpos > 20)
                {
                    win = true;
                }
            }
            
            if( (prev == 25 && yut[i] == 2) || (prev == 26 && yut[i] == 1))
                Bpos = 22;
            
            if( (prev==25 || prev==26) && Bpos >= 28)
                Bpos--;
            
            if((prev == 22 || 25 <= prev) && Bpos > 29)
                win = true;
            
            bool gotA = false;
            //catch
            if(Apos == Bpos)
            {
                Apos = 0;
                gotA = true;
                resA = 0;
            }
            
            if(win)
                resB = 0;
            
            if( !(yut[i] == 4 || yut[i] == 5 || gotA) )
                isA = true;
            
        }


//cout<<"Apos : "<<Apos<<endl;
//cout<<"Bpos : "<<Bpos<<endl;
//cout<<endl;

    }
    
    if(Apos >= 29) Apos = 0;
    if(Bpos >= 29) Bpos = 0;

//cout<<"A : "<<A<<" , B : "<<B<<" , finalA : "<<finalA<<" , finalB : "<<finalB<<endl;
//cout<<"resA : "<<resA<<" , resB : "<<resB<<" , Apos : "<<Apos<<" , Bpos : "<<Bpos<<endl;

    if(valid)
    {
        if( (resA == A && resB == B && (resA == 0 || Apos == finalA) && (resB == 0 || Bpos == finalB)) || (resA == B && resB == A && (resA == 0 || Apos == finalB) && (resB == 0 || Bpos == finalA)) )
            ans = "YES";
        else ans = "NO";
    }
    else
        ans = "NO";
}