#include<cstdio>

bool adj[101][101];
bool v[101];

int n,m,s,e;

int dfs(int here){
    v[here] = true;
    if(here == e)
        return 0;

    for(int i=1;i<=n;++i){
        if(adj[here][i] && !v[i]){
            int t = dfs(i);
            if(t != -1)
                return t+1;
        }
    }
    return -1;
}

int main(){
    scanf("%d%d%d%d",&n,&s,&e,&m);
    for(int i=0;i<m;++i){
        int x, y;
        scanf("%d%d",&x,&y);
        adj[x][y] = true;
        adj[y][x] = true;
    }
    printf("%d",dfs(s));
    return 0;
}
