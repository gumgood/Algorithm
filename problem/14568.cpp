#include<cstdio>

int main(){
    int n;
    scanf("%d",&n);

    int ans = 0;
    for(int a=2;a<=n;a+=2)
        for(int b=1;a+b+b+2<=n;++b)
            ans++;
    printf("%d",ans);

    return 0;
}
