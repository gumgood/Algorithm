#include<cstdio>

const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};

int n, m, ans;
int map[100][100];
int v[100][100]; // 0 = not visited, 1 = visited, 2 = melt

void dfs(int x,int y){
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!(0<=nx && nx<n)) continue;
        if(!(0<=ny && ny<m)) continue;
        if(v[nx][ny]) continue;
        if(map[nx][ny]) v[nx][ny] = 2;
        if(map[nx][ny]==0){
            v[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}

bool allmelt(){
    bool ret = true;
    ans = 0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            if( map[i][j] && (v[i][j]!=2))
                ret =  false;
            if( v[i][j]==2 )
                map[i][j] = 0, ans++;
            v[i][j] = 0;
        }
    return ret;
}

void solve(){
    int cnt = 0;
    while(!allmelt()){
        v[0][0] = 1;
        dfs(0,0);
        cnt++;
    }
    printf("%d\n%d",cnt,ans);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%d",&map[i][j]);
    solve();
    return 0;
}
