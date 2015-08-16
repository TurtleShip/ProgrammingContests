#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

struct Node {
    int id;
    int hashVal; //unique value representing what combinations of children it has
    int numEdge;
    vector<int> neighbor;
    vector<int> childHash;
    
    Node() {
        numEdge = 0;
    }
    
    void addHash(int val) {
        childHash.push_back(val);
    }
    
    void sortHash() {
        sort(childHash.begin(), childHash.end());
    }
    
    void addNeighbor(int val) {
        neighbor.push_back(val);
    }
    
};

const int maxN = 2e4 + 10;
Node A[maxN];
Node B[maxN];
bool isVisitedA[maxN];
bool isVisitedB[maxN];
int main()
{
    int N;
    int x,y;
    
    while(scanf("%d", &N) != EOF) {
        
        //initialize
        map< vector<int>, int> M;
        vector<int> emp;
        int hashCt = 0;
        M[emp] = hashCt++;
        
        for(int i=0; i < N; i++) {
            A[i] = Node();
            B[i] = Node();
            isVisitedA[i] = false;
            isVisitedB[i] = false;
        }
        printf("N : %d , start input\n", N);
        //get first graph's edges
        for(int i=0; i < N-1; i++) {
            scanf(" %d %d", &x, &y);
            x--; y--;
            A[x].addNeighbor(y);
            A[y].addNeighbor(x);
            A[x].numEdge++;
            A[y].numEdge++;
        }
        
        //get second graph's edges
        for(int i=0; i < N-1; i++) {
            scanf(" %d %d", &x, &y);
            x--; y--;
            B[x].addNeighbor(y);
            B[y].addNeighbor(x);
            B[x].numEdge++;
            B[y].numEdge++;
        }
        printf("Done getting input\n");
        
        queue< vector<int> >Q;
        vector<int> initA;
        vector<int> midA;
        for(int i=0; i < N; i++)
            if(A[i].numEdge == 1) {
                isVisitedA[i] = true;
                initA.push_back(i);
            }
        
        printf("queue begin\n");
        Q.push(initA);
      
        /*
         At each iteration, 
         for each "leaf" node, 
         1) get hashval by 
         a) sort childHash.
         b) curNode.hashVal = M[childHash]
         2) find its parent, and add its hashVal to its parent
         : parentnode.addHash(curNode.hashVal);
         */
        while(!Q.empty()) {
            vector<int> curNodes = Q.front(); Q.pop();
            vector<int> nextNodes;
            
            printf("current Node : ");
            for(int i=0; i < curNodes.size(); i++) 
                printf("%d ",curNodes[i]);
            printf("\n");
            
            for(int i=0; i < curNodes.size(); i++) {
                int cur = curNodes[i];
                A[cur].sortHash();
                
                if(M.count(A[cur].childHash) > 0) {
                    A[cur].hashVal = M[A[cur].childHash];
                } else {
                    A[cur].hashVal = hashCt;
                    M[A[cur].childHash] = hashCt++;
                }
                
                vector<int> adj = A[cur].neighbor;
                for(int j=0; j < adj.size(); j++) {
                    if(isVisitedA[adj[j]]) continue;
                    A[adj[j]].addHash(A[cur].hashVal);
                    A[adj[j]].numEdge--;
                }
            }
            
            printf("Looking at nodes\n ");
            for(int i=0; i < N; i++) {
                if(isVisitedA[i]) continue;
                printf("node %d has %d edges\n", i, A[i].numEdge);
                if(A[i].numEdge == 1) {
                    nextNodes.push_back(i);
                    isVisitedA[i] = true;
                }
                if(A[i].numEdge == 0) midA.push_back(i);
            }
            printf("\n");
            if(nextNodes.size() != 0) Q.push(nextNodes);
        }
        
        printf("midA : ");
        for(int i=0; i < midA.size(); i++) {
            printf("%d ", midA[i]);
        }
        printf("\n");
        
        
        vector<int> initB;
        vector<int> midB;
        for(int i=0; i < N; i++)
            if(B[i].numEdge == 1) {
                isVisitedB[i] = true;
                initB.push_back(i);
            }
        
        printf("queue begin\n");
        Q.push(initB);
        
        /*
         At each iteration, 
         for each "leaf" node, 
         1) get hashval by 
         a) sort childHash.
         b) curNode.hashVal = M[childHash]
         2) find its parent, and add its hashVal to its parent
         : parentnode.addHash(curNode.hashVal);
         */
        while(!Q.empty()) {
            vector<int> curNodes = Q.front(); Q.pop();
            vector<int> nextNodes;
            
            printf("current Node : ");
            for(int i=0; i < curNodes.size(); i++) 
                printf("%d ",curNodes[i]);
            printf("\n");
            
            for(int i=0; i < curNodes.size(); i++) {
                int cur = curNodes[i];
                B[cur].sortHash();
                
                if(M.count(B[cur].childHash) > 0) {
                    B[cur].hashVal = M[B[cur].childHash];
                } else {
                    B[cur].hashVal = hashCt;
                    M[B[cur].childHash] = hashCt++;
                }
                
                vector<int> adj = B[cur].neighbor;
                for(int j=0; j < adj.size(); j++) {
                    if(isVisitedB[adj[j]]) continue;
                    B[adj[j]].addHash(B[cur].hashVal);
                    B[adj[j]].numEdge--;
                }
            }
            
            printf("Looking at nodes\n ");
            for(int i=0; i < N; i++) {
                if(isVisitedB[i]) continue;
                printf("node %d has %d edges\n", i, B[i].numEdge);
                if(B[i].numEdge == 1) {
                    nextNodes.push_back(i);
                    isVisitedB[i] = true;
                }
                if(B[i].numEdge == 0) midB.push_back(i);
            }
            printf("\n");
            if(nextNodes.size() != 0) Q.push(nextNodes);
        }
        
        printf("midB : ");
        for(int i=0; i < midB.size(); i++) {
            printf("%d ", midB[i]);
        }
        printf("\n");
        
        //get hashVal for mids
        for(int i=0; i < midA.size(); i++) {
            A[midA[i]].sortHash();
            if(M.count(A[midA[i]].childHash) > 0) A[midA[i]].hashVal = M[A[midA[i]].childHash];
            else {
                A[midA[i]].hashVal = M[A[midA[i]].childHash] = hashCt++;
            }
        }
        
        for(int i=0; i < midB.size(); i++) {
            B[midB[i]].sortHash();
            if(M.count(B[midB[i]].childHash) > 0) B[midB[i]].hashVal = M[B[midB[i]].childHash];
            else B[midB[i]].hashVal = M[B[midB[i]].childHash] = hashCt++;
        }
        
        
        bool isSame = false;
        for(int i=0; i < midA.size(); i++)
            for(int j=0; j < midB.size(); j++)
                if(A[midA[i]].hashVal == B[midB[i]].hashVal)
                    isSame = true;
        
        if(isSame) printf("It is same.\n");
        else printf("Not same.\n");
              
    }
    

    return 0;
}