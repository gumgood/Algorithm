#include<cstdio>
#include<algorithm>
using namespace std;

int n, m;
char in[51][51];

int cnt(int x, int y){
    int ret1 = 0,ret2 = 0;
    for(int i=x;i<x+8;++i){
        for(int j=y;j<y+8;++j){
            if((i+j)%2){
                if(in[i][j] == 'B')
                    ret1++;
                else
                    ret2++;
            }else if((i+j)%2==0){
                if(in[i][j] == 'W')
                    ret1++;
                else
                    ret2++;
            }
        }
    }
    return min(ret1,ret2);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%s",in[i]);
    int ans = 1e9;
    for(int i=0;i<=n-8;++i)
        for(int j=0;j<=m-8;++j)
            ans = min(ans,cnt(i,j));
    printf("%d",ans);
    return 0;
}

