#include<cstdio>

int dp[2001][2001];

int main(){
    for(int i=0;i<=2000;++i) dp[0][i] = 1;
    for(int i=1;i<=2000;++i){
        for(int j=1;j<=2000;++j){
            dp[i][j] = dp[i][j-1];
            if(i>=j) dp[i][j] = (dp[i][j] + dp[i-j][j-1]) % 100999;
        }
    }

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n][n]);
    }
    return 0;
}
