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

struct Node
{
    string data;
    vector<Node*> children;
    Node* parent;
    int id;
    
    Node(){}
    Node(string d, Node* p = NULL, int i= -1)
    {
        data = d;
        parent = p;
        id = i;
    }
    
    void addChild(Node* child)
    {
        children.push_back(child);
    }
    
    Node* getParent()
    {
        return parent;
    }
};

const int maxNode = 500000;
const int maxQ = 210;
Node nodes[maxNode];
bool chk[maxNode];
bool vis[maxNode][maxQ];
string query[maxQ];
int N;

void dfs(Node cur, int idx)
{
    if(vis[cur.id][idx]) return;
    vis[cur.id][idx] = true;
    
    bool isMatch = (cur.data == query[idx]);
    if(isMatch && (idx == N-1))
        chk[cur.id] = true;

    for(int i=0; i < cur.children.size(); i++)
    {
        //move to the next element in query
        if(isMatch && idx < N-1)
            dfs( *(cur.children[i]), idx+1);
        
        //pass the matching to the child
        if(0 < idx) dfs( *(cur.children[i]), idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
   
    Node root("!");
    int idx = 0;
    
    string doc;
    getline(cin,doc);
    
    for(int i=0; i < doc.size(); i++)
        if(doc[i] == '<' || doc[i] == '>')
            doc[i] = ' ';

    stringstream ss(doc);
    string cur;
    Node* pt = &root;
    
    while(ss>>cur)
    {
        int sz = cur.size();
        if(cur[0] == '/')
        {
            pt = (*pt).getParent();
        }
        else if(cur[sz-1] == '/')
        {
            nodes[idx] = Node(cur.substr(0,sz-1), pt,idx);
            (*pt).addChild(&nodes[idx]);
            idx++;
        }
        else
        {
            nodes[idx] = Node(cur, pt,idx);
            (*pt).addChild(&nodes[idx]);
            pt = &nodes[idx];
            idx++;
        }
    }
    
    int M;
    string tmp;
    getline(cin, tmp);
    stringstream ssTemp(tmp);
    ssTemp>>M;

    for(int i=0; i < M; i++)
    {
        string q;
        N = 0;
        memset(chk, false, sizeof(chk));
        memset(vis, false, sizeof(vis));
        getline(cin, q);
        stringstream ssq(q);
        string curq;
        while(ssq>>curq)
        {
            query[N++] = curq;
        }
        
        ll res = 0;
        for(int j=0; j < idx; j++)
            if(query[0] == nodes[j].data)
                dfs(nodes[j], 0);
        
        for(int j=0; j < idx; j++)
            if(chk[j]) res++;
        
        cout<<res<<endl;

    }
    
    return 0;
}
