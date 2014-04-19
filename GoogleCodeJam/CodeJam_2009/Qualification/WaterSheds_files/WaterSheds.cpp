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

vector< vector<int> >field;
vector< vector<char> >drain;
char curChar;
int R;
int C;

struct Cell
{
    int row;
    int col;
    int altitude;
    string direction;
    
    Cell(int r, int c, int a, string d)
    {
        row = r;
        col = c;
        altitude = a;
        direction = d;
    }
};

bool compDirection(string a, string b)
{
    if(a == "North")
        return true;
    if(a == "West")
    {
        if(b == "North") return false;
        else return true;
    }
    if(a == "East")
    {
        if(b == "North" || b == "West") return false;
        else return true;
    }
    return false;
}

bool compCell(Cell a, Cell b)
{
    if( a.altitude < b.altitude )
        return true;
    
    if(a.altitude == b.altitude )
        return compDirection(a.direction , b.direction);
    
    return false;
}

int dr[4] = {-1,0,0,1};
int dc[4] = {0,-1,1,0};
string direc[4] = {"North", "West", "East", "South"};
char rec(int r, int c)
{
    vector<Cell> cells;
    if(drain[r][c] != '#')
        return drain[r][c];
    
    for(int i=0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(0 <= nr && nr < R && 0 <= nc && nc < C && field[nr][nc] < field[r][c])
            cells.push_back( Cell(nr, nc, field[nr][nc], direc[i]) );
    }
    
    if(cells.size() == 0)
    {
        drain[r][c] = curChar;
        curChar++;
        return drain[r][c];
    }
    else
    {
        sort(cells.begin(), cells.end(), compCell);
        drain[r][c] = rec(cells[0].row, cells[0].col);
        return drain[r][c];
    }
}

int main()
{
    int T;
    cin>>T;
    
    for(int idx=1; idx <= T; idx++)
    {
        cin>>R;
        cin>>C;
        field.clear();
        drain.clear();
        curChar = 'a';

        //Initialize
        for(int i=0; i<R; i++)
        {
            vector<int> curRow(C,0);
            for(int j=0; j<C; j++)
            {
                cin>>curRow[j];
            }
            field.push_back(curRow);
            drain.push_back( vector<char>(C,'#'));
        }
                
        for(int i=0; i < R; i++)
            for(int j=0; j<C; j++)
                rec(i,j);
        
        cout<<"Case #"<<idx<<":"<<endl;
        
        for(int i=0; i < R; i++)
        {
            for(int j=0; j < C-1; j++)
            {
                cout<<drain[i][j]<<" ";
            }
            cout<<drain[i][C-1];
            cout<<endl;
        }
    }
    
    return 0;
}