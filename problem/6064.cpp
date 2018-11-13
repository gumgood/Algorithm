#include<cstdio>

int solve(int m,int n,int x,int y){
    if(x==m) x = 0;
    if(y==n) y = 0;
    for(int i=0;i<n;++i){
        int year = i*m + x;
        if(year%n == y)
            return year;
    }
    return -1;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n,x,y;
        scanf("%d%d%d%d",&m,&n,&x,&y);
        printf("%d\n",solve(m,n,x,y));
    }
    return 0;
}
