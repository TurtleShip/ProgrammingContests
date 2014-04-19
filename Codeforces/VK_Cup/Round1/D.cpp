#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
#define N 50005  
LL dp[N][505];  
vector<int> v[N];  
LL ans = 0;  
int n,k;  
//dfs( curVertex, prevVertex)
void dfs(int u,int fa){  
	cout<<"dfs("<<u<<" , "<<fa<<")"<<endl;
    int i;  
    dp[u][0] = 1;  
    for(i=0;i<v[u].size();i++){  
        if(v[u][i]!=fa){  
            dfs(v[u][i],u);  
            int j;  
            for(j=1;j<=k;j++){
                ans += dp[u][j-1]*dp[v[u][i]][k-j];  
            }  
            for(j=1;j<=k;j++){  
                dp[u][j] += dp[v[u][i]][j-1];  
            }  
        }  
    }  
}  
int main(){
    cin>>n>>k;  
    int i;  
    for(i=1;i<n;i++){  
        int x,y;  
        cin>>x>>y;  
        v[x].push_back(y);  
        v[y].push_back(x);  
    }  
    dfs(1,1);  
    cout<<ans<<endl;  
    return 0;  
}  