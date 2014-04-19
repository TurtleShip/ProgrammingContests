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

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N;
    cin>>N;
    
    
    // We have a cycle after lcm(m,k) turns
    string A;
    string B;
    
    cin>>A>>B;
    
    int a = A.size();
    int b = B.size();
    
    int ab = a * b;
    int cycleA = 0;
    int cycleB = 0;
    int posA = 0;
    int posB = 0;
    for(int i=0; i < ab; i++, posA++, posB++)
    {
        if(posA == a) posA = 0;
        if(posB == b) posB = 0;
        
        if(A[posA] == B[posB])
            continue;
        
        if(A[posA] == 'R')
        {
            if(B[posB] == 'P') cycleA++;
            else cycleB++;
        }
        else if(A[posA] == 'P')
        {
            if(B[posB] == 'S') cycleA++;
            else cycleB++;
        }
        else if(A[posA] == 'S')
        {
            if(B[posB] == 'R') cycleA++;
            else cycleB++;
        }
    }
    
    int numCycle = N / ab;

    int resA = cycleA * numCycle;
    int resB = cycleB * numCycle;
    
    N = N - (numCycle * ab);

    for(int i=0; i < N; i++, posA++, posB++)
    {
        if(posA == a) posA = 0;
        if(posB == b) posB = 0;

        if(A[posA] == B[posB])
            continue;

        if(A[posA] == 'R')
        {
            if(B[posB] == 'P') resA++;
            else resB++;
        }
        else if(A[posA] == 'P')
        {
            if(B[posB] == 'S') resA++;
            else resB++;
        }
        else if(A[posA] == 'S')
        {
            if(B[posB] == 'R') resA++;
            else resB++;
        }
    }
    
    cout<<resA<<" "<<resB<<endl;

    return 0;
}