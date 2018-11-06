#include<cstdio>

int map[31][31];
 
int main(){
    for(int i=1;i<31;++i){
        map[i][1] = 1;
        for(int j=2;j<i;++j)
            map[i][j] = map[i-1][j] + map[i-1][j-1];
        map[i][i] = 1;
    }

    int r, c, w;
    scanf("%d%d%d",&r,&c,&w);
    
    int ans = 0;
    for(int i=0;i<w;++i)
        for(int j=0;j<=i;++j)
            ans += map[r+i][c+j];
    printf("%d",ans);

    return 0;
}
