#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;

const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

int r, c;
char map[251][251];
bool v[251][251];

ii dfs(int x,int y){
    ii ret(0,0);
    
    if(map[x][y]=='o')
        ret.first++;
    else if(map[x][y]=='v')
        ret.second++;

    v[x][y] = true;
    
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>r) continue;
        if(ny<0 || ny>c) continue;
        if(v[nx][ny]) continue;
        if(map[nx][ny]=='#') continue;
        
        ii t = dfs(nx,ny);
        ret.first += t.first;
        ret.second += t.second;
    }
    return ret;
}

void solve(){
    ii ret(0,0);
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(v[i][j]==false){
                ii t = dfs(i,j);
                if(t.first > t.second) ret.first += t.first;
                else ret.second += t.second;
            }
        }
    }
    printf("%d %d",ret.first,ret.second);
}

int main(){
    
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)
        scanf("%s",map[i]);
    
    solve();

    return 0;
}
