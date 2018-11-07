#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int n;
int people[10001];
vector<int> adj[10001];

int dp[10001][2];
bool v[10001];

void dfs(int x){
    v[x] = true;
    dp[x][1] = people[x];

    for(int i=0;i<adj[x].size();++i){
        int next = adj[x][i];
        if(v[next]==false){
            dfs(next);
            dp[x][0] += max(dp[next][0],dp[next][1]);
            dp[x][1] += dp[next][0];
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",people+i);
    for(int i=1;i<n;++i){
        int x, y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    printf("%d",max(dp[1][0],dp[1][1]));

    return 0;
}
