#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char a[1002] = {' '};
char b[1002] = {' '};
int dp[1002][1002];

int main(){
    scanf("%s%s",a+1,b+1);
    int n = strlen(a), m = strlen(b);
    for(int i=0;i<n;++i)
        dp[i][0] = i;
    for(int i=0;i<m;++i)
        dp[0][i] = i;
    for(int i=1;i<n;++i)
        for(int j=1;j<m;++j)
            if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
    printf("%d",dp[n-1][m-1]);
    return 0;
}

