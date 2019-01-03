#include<cstdio>

int n, m, a[50][50], b[50][50];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%1d",&a[i][j]);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            scanf("%1d",&b[i][j]);

    int ans = 0;
    for(int i=0;i<n-2;++i)
        for(int j=0;j<m-2;++j)
            if(a[i][j] != b[i][j]){
                ans++;
                for(int x=0;x<3;++x)
                    for(int y=0;y<3;++y)
                        a[i+x][j+y] = a[i+x][j+y] ? 0 : 1;
            }

    bool chk = true;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(a[i][j] != b[i][j])
                chk = false;

    if(chk)
        printf("%d",ans);
    else
        printf("-1");

    return 0;
}
