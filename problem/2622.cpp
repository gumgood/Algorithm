#include<cstdio>

int solve(int n){
    int ret = 0;
    for(int c=1;c<=n;++c)
        if(n<=3*c && 2*c<n)
            ret += c - (n-c-1)/2;
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",solve(n));
    return 0;
}
