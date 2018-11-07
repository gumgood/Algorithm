#include<cstdio>
#include<algorithm>
using namespace std;

int dp[21];
int t[16], p[16];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d%d",t+i,p+i);
    
    for(int i=1;i<=n;++i){
        int nextDay = i + t[i] - 1;
        dp[nextDay] = max(dp[nextDay], dp[i-1] + p[i]);
        dp[i] = max(dp[i], dp[i-1]);
    }
    int ans = 0;
    for(int i=1;i<=n;++i)
        ans = max(ans, dp[i]);
    printf("%d",ans);

    return 0;
}
