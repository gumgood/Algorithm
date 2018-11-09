#include<cstdio>
#include<algorithm>
using namespace std;

long long dp[101][21];

int main(){
    int S, K;
    scanf("%d%d",&S,&K);
   
    for(int i=1;i<=S;++i)
        dp[i][1] = i;
    for(int i=1;i<=S;++i)
        for(int j=1;j<=K;++j)
            for(int k=1;k<i;++k)
                dp[i][j] = max(dp[i][j],k*dp[i-k][j-1]);

    printf("%lld",dp[S][K]);
    return 0;
}

