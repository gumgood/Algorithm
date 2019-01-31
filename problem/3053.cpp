#include<cstdio>

bool chk[42];

int main(){
    for(int i=0;i<10;++i){
        int t;
        scanf("%d",&t);
        chk[t%42] = true;
    }
    
    int ans = 0;
    for(int i=0;i<42;++i)
        ans += chk[i];
    printf("%d",ans);
    return 0;
}
