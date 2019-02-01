#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;
double p[20][20];

double dp[1<<20];

double solve(){
    for(int i=0;i<n;++i)
        dp[1<<i] = p[0][i];
    for(int i=1;i<n;++i)
        for(int bit=0;bit<(1<<n);++bit){
            int cnt = 0;
            for(int j=bit;j;j/=2)
                cnt += j%2;
            if(cnt!=i) continue;

            for(int j=0;j<n;++j)
                if((bit & (1<<j))==0)
                    dp[bit|(1<<j)] = max(dp[bit|(1<<j)], dp[bit]*p[i][j]);
        }
    return dp[(1<<n)-1];
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            scanf("%lf",&p[i][j]);
            p[i][j] /= 100.0f;
        }
    printf("%.9lf",solve()*100.0f);
    return 0;
}
