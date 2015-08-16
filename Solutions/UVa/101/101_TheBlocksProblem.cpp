#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;
const int maxN = 30;
vector<int> stk[maxN];
int id[maxN];

/* move elements above x back to its original position */
void clearStack(int x) {
    int stkId = id[x];
    bool foundX = false;
    vector<int> prevX;
    for(int i=0; i < stk[stkId].size(); i++) {
        if(!foundX) prevX.push_back( stk[stkId][i] );
        else {
            stk[ stk[stkId][i] ].push_back( stk[stkId][i] );
            id[ stk[stkId][i] ] = stk[stkId][i];
        }
        if(stk[stkId][i] == x) foundX = true;
    }
    stk[ stkId ] = prevX;
}

void moveAtoB(int a, int b) {
    stk[ id[a] ].erase(stk[ id[a] ].begin() + stk[ id[a] ].size() - 1);
    stk[ id[b] ].push_back(a);
    id[a] = id[b];
}

void pileAtoB(int a, int b) {
    vector<int> belowA;
    vector<int> stackA;
    bool foundA = false;
    for(int i=0; i < stk[id[a]].size(); i++) {
        if(stk[id[a]][i] == a) foundA = true;
        if(!foundA) belowA.push_back(stk[id[a]][i]);
        else stackA.push_back( stk[id[a]][i] );
    }
    stk[id[a]] = belowA;
    
    for(int i=0; i < stackA.size(); i++) {
        stk[id[b]].push_back(stackA[i]);
        id[ stackA[i] ] = id[b];
    }
}

void moveOnto(int a, int b) {
    clearStack(a);
    clearStack(b);
    moveAtoB(a,b);
}

void moveOver(int a, int b) {
    clearStack(a);
    moveAtoB(a,b);
}

void pileOnto(int a, int b) {
    clearStack(b);
    pileAtoB(a,b);
}

void pileOver(int a, int b) {
    pileAtoB(a,b);
}

int main() {
    string str;
    getline(cin, str);
    int N = atoi(str.c_str());
    
    //initialize
    for(int i=0; i < N; i++) {
        stk[i].push_back(i);
        id[i] = i;
    }
    
    while(true) {
        string line;
        getline(cin, line);
        if(line == "quit") break;
        stringstream ss;
        ss<<line;
        string s1,s2;
        int a,b;
        ss>>s1>>a>>s2>>b;
        if(id[a] == id[b]) continue;
        
        if(s1 == "move") {
            if(s2 == "onto") moveOnto(a,b);
            else moveOver(a,b);
        } else { //s1 == "pile"
            if(s2 == "onto") pileOnto(a,b);
            else pileOver(a,b);
        }
    }
    
    for(int i=0; i < N; i++) {
        cout<<i<<":";
        for(int j=0; j < stk[i].size(); j++)
            cout<<" "<<stk[i][j];
        cout<<endl;
    }
    
    return 0;
}