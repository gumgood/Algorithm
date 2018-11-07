#include<cstdio>

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

bool v[1002][1002];

int main(){
    int c,r,k;
    scanf("%d%d%d",&c,&r,&k);
    
    if(k > c*r) printf("0");
    else{
        for(int i=0;i<r+2;++i)
            v[i][0] = v[i][c+1] = true;
        for(int i=0;i<c+2;++i)
            v[0][i] = v[r+1][i] = true;
        
        int x=0,y=1,w=0;;
        while(k--){
            int nx = x + dx[w];
            int ny = y + dy[w];
            if(v[nx][ny]){
                w = (w+1)%4;
                k++;
            }else{
                v[nx][ny] = true;
                x = nx, y = ny;
            }
        }
        printf("%d %d",y,x);
    }
    
    return 0;
}
