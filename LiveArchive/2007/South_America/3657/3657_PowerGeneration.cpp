#include<iostream>
#include<vector>
#include<cmath>

#define INF 2000
using namespace std;

int N, C, A;
int x[10005];
int y[10005];
int p[10005];
vector<int> child[10005];

long double dist(int a, int b){
    return sqrt(pow((long double)(x[a]-x[b]),2) + pow((long double)(y[a]-y[b]),2));
}

int dfs(int node){
    int val = p[node];
    for(int c=0; c<child[node].size(); c++){
        int ret = dfs(child[node][c]);
        if(ret>=C) A++;
        else val+=ret;
    }
    return val;
}

int main(){
    while(cin >> N >> C){
        if(N==0 && C==0) break;
        for(int n=0; n<N; n++){
            cin >> x[n] >> y[n] >> p[n];
            child[n].clear();
            if(n>0){
                long double low_dist = INF;
                int low_ind = -1;
                for(int q=0; q<n; q++)
                    if(dist(q, n) < low_dist){
                        low_dist = dist(q, n);
                        low_ind = q;
                    }
                child[low_ind].push_back(n);
            }
        }
        A = 0;
        if(dfs(0)>=C) A++;;
        cout << A << endl;
    }
    return 0;
}
