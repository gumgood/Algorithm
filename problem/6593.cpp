#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int,int> ii;

const int INF = 1e9;

const int dx[] = {-1,1,0,0,0,0};
const int dy[] = {0,0,-1,1,0,0};
const int dz[] = {0,0,0,0,-1,1};

char map[31][31][31];
int l, r, c;

int sx, sy, sz;
int ex, ey, ez;

int bfs(){
    bool v[31][31][31] = {0};
    v[sx][sy][sz] = true;
    queue<pair<ii,ii> > q;
    q.push(make_pair(ii(sx,sy),ii(sz,0)));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int d = q.front().second.second;
        q.pop();

        if(x==ex && y==ey && z==ez)
            return d;

        for(int i=0;i<6;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            int nd = d + 1;

            if(nx<0 || l-1<nx) continue;
            if(ny<0 || r-1<ny) continue;
            if(nz<0 || c-1<nz) continue;
            if(v[nx][ny][nz]) continue;
            if(map[nx][ny][nz]=='#') continue;

            v[nx][ny][nz] = true;
            q.push(make_pair(ii(nx,ny),ii(nz,nd)));
        }
    }
    return -1;
}

int main(){
    while(true){
        scanf("%d%d%d",&l,&r,&c);
        if(l==0 && r==0 && c==0)
            break;
        for(int i=0;i<l;++i){
            for(int j=0;j<r;++j){
                scanf("%s",map[i][j]);
                for(int k=0;k<c;++k){
                    if(map[i][j][k]=='S')
                        sx=i,sy=j,sz=k;
                    if(map[i][j][k]=='E')
                        ex=i,ey=j,ez=k;
                }
            }
        }

        int ans = bfs();
        if(ans<0)
            puts("Trapped!");
        else
            printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
