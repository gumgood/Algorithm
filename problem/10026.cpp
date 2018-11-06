#include<cstdio>
#include<cstring>

const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

int n;
char map[101][101];
bool v[101][101];

void dfs(int x,int y){
    v[x][y] = true;
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=n) continue;
        if(ny<0 || ny>=n) continue;
        if(v[nx][ny]) continue;
        if(map[nx][ny] != map[x][y]) continue;
        dfs(nx,ny);
    }
}


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%s",map[i]);
    
    int ans = 0;
    memset(v,0,sizeof(v));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(v[i][j]==false)
                ans++, dfs(i,j);

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(map[i][j] == 'G')
                map[i][j] = 'R';

    int ans2 = 0;
    memset(v,0,sizeof(v));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(v[i][j]==false)
                ans2++, dfs(i,j);

    printf("%d %d",ans,ans2);

    return 0;
}
