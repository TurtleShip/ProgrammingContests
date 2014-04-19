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
    Node* parent;
    int id;
    Node(string d = "", Node* p = NULL, int i=-1)
    {
        data = d;
        parent = p;
        id = i;
    }
};

const int maxDoc = 1e6 + 10;
const int maxNode = 3 * 1e5;
const int maxQuery = 210;
Node nodes[maxNode];
int solved[maxNode];
string query[maxQuery];
int main()
{
    ios_base::sync_with_stdio(false);
    
    string doc;
    getline(cin, doc);
    int idx = 1;
    nodes[0] = Node("ROOT",NULL,0); //dummy root
    Node* pt = &(nodes[0]);
    int N = 1;//number of nodes
    
    //process nodes
    while(idx < doc.size())
    {
        if(doc[idx] == '/')
        {
            int j = idx+1;
            while(doc[j] != '>')
                j++;
            idx = j + 2;
            pt = (*pt).parent;
        }
        else
        {
            int j = idx;
            while(doc[j] != '/' && doc[j] != '>')
                j++;
            nodes[N] = Node(doc.substr(idx, j - idx), pt, N);
            if(doc[j] != '/') pt = &(nodes[N]);
            else j++;
                
            N++;
            idx = j + 2;
        }
    }
    
    int M;
    cin>>M;
    cin.ignore();

    while(M--)
    {
        //process query
        string line;
        getline(cin, line);
        
        int idx = 0;
        int Q = 0; //number of queries

        while(idx < line.size())
        {
            int j = idx;
            while(j < line.size() && line[j] != ' ')
                j++;
            query[Q++] = line.substr(idx, j - idx);
            idx = j+1;
        }
        
        int res = 0;
        int solved[N];
        solved[0] = 0;
        //get answer
        for(int i=1; i < N; i++)
        {
            int pos = solved[ (nodes[i].parent)->id ];
            bool isMatch = (nodes[i].data == query[pos]);
            if(isMatch)
            {
                if(pos == Q-1) res++;
                else pos++;
            }
            solved[i] = pos;
        }
        cout<<res<<endl;
    }

    return 0;
}