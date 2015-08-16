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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class CuttingGlass {
public:
    int pieces(int W, int H, int startx, int starty, vector <string> program);
};

//D,U,R,L

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string dirs="DURL";

int opp[]={1,0,3,2};

const int MAX=2001;

bool cut[MAX][MAX][4];
bool hit[MAX][MAX];

int verts=0, edges=0;
bool touched=false;

int width, height;

void hitv(int y, int x, bool ignore=false) {
    if(!ignore&&(y==0||x==0||y==height||x==width)) {
        touched=true;
    }
    if(!hit[y][x]) {
        hit[y][x]=1;
        verts++;
    }
}

set<vector<int> > eee;

void hite(int y1, int x1, int y2, int x2) {
    vector<int> tmp1;
    tmp1.push_back(x1);
    tmp1.push_back(y1);
    tmp1.push_back(x2);
    tmp1.push_back(y2);
    
    vector<int> tmp2;
    tmp2.push_back(x2);
    tmp2.push_back(y2);
    tmp2.push_back(x1);
    tmp2.push_back(y1);
    
    if(find(eee.begin(),eee.end(),tmp1)==eee.end()&&find(eee.begin(),eee.end(),tmp2)==eee.end()) {
        eee.insert(tmp1);
    }
}

int trans(int d) {
    return opp[d];
}

void process(int &x, int &y, char c) {
    int dir=dirs.find(c);
    int nx=x+dx[dir];
    int ny=y+dy[dir];
    hitv(ny,nx);
    hite(y,x,ny,nx);
    x=nx;
    y=ny;
}

void precompute() {
    //top/bottom, go left
    for(int i=0;i<=width;i++) {
        hitv(0,i,1);
        hitv(height,i,1);
        if(i<width) {
            hite(0,i,0,i+1);
            hite(height,i,height,i+1);
        }
    }
    //left/right, go down
    for(int i=0;i<=height;i++) {
        hitv(i,0,1);
        hitv(i,width,1);
        if(i<height) {
            hite(i,0,i+1,0);
            hite(i,width,i+1,width);
        }
    }
}

int compute() {
    return 2-verts+eee.size();
}

int CuttingGlass::pieces(int W, int H, int startx, int starty, vector <string> program) {
    width=W;
    height=H;
    precompute();
    compute();
    int x=startx, y=starty;
    hitv(y,x);
    string data=accumulate(program.begin(),program.end(),string());
    for(int i=0;i<data.size();i++)
        process(x, y, data[i]);
    int ret=compute();
    if(touched) ret--;
    return ret;
    
}