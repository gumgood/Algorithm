#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> iiii;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int r, c;
char map[50][51];

int solve(){
    queue<iiii> q;
    int v[50][50] = {0};
    int bx, by, sx, sy;
    for(int i=0;i<r;++i)
        for(int j=0;j<c;++j){
            if(map[i][j]=='D')
                bx = i, by = j;
            else if(map[i][j]=='S')
                sx = i, sy = j;
            else if(map[i][j]=='*')
                q.push(iiii(ii(i,j),ii(0,2))), v[i][j] = 2;
        }
    q.push(iiii(ii(sx,sy),ii(0,1)));
    v[sx][sy] = 1;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second.first;
        int w = q.front().second.second;
        q.pop();
        if(w==1 && x==bx && y==by)
            return t;
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=r) continue;
            if(ny<0 || ny>=c) continue;
            if(map[nx][ny]=='X') continue;
            if(map[nx][ny]=='D' && w==2) continue;
            if(v[nx][ny] >= w) continue;
            v[nx][ny] = w;
            q.push(iiii(ii(nx,ny),ii(t+1,w)));
        }
    }
    return -1;
}

int main(){
    scanf("%d%d\n",&r,&c);
    for(int i=0;i<r;++i)
        scanf("%s",map[i]);

    int ans = solve();
    if(ans<0) puts("KAKTUS");
    else printf("%d",ans);

    return 0;
}
