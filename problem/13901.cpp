#include<cstdio>

int map[1001][1001];

const int dx[] = {0,-1,1,0,0};
const int dy[] = {0,0,0,-1,1};

int main(){
    int r, c, k;
    scanf("%d%d%d",&r,&c,&k);

    for(int i=0;i<k;++i){
        int br, bc;
        scanf("%d%d",&br,&bc);
        map[br][bc] = -1;
    }

    int sr, sc;
    scanf("%d%d",&sr,&sc);

    int way[4];
    for(int i=0;i<4;++i)
        scanf("%d",way+i);

    int x = sr, y = sc, w = 0;
    while(true){
        map[x][y] = 1; //
        int i;
        for(i=0;i<4;++i){
            int nw = (w + i)%4;
            int nx = x + dx[way[nw]];
            int ny = y + dy[way[nw]];
            if(nx<0 || r-1<nx) continue;
            if(ny<0 || c-1<ny) continue;
            if(map[nx][ny] != 0) continue;
            x = nx, y = ny, w = nw;
            break;
        }
        if(i==4) break;
    }

    printf("%d %d\n",x,y);

    return 0;
}
