#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int _INF = 1e9;

int k, in[501];
int psum[501];
int dp[501][501];

int sum(int s, int e){
    if(s==0) return psum[e];
    return psum[e] - psum[s-1];
}

int solve(int s,int e){
    int &ret = dp[s][e];

    if(ret != -1)
        return ret;

    if(e-s == 0)
        return ret = 0;
    else if(e-s == 1)
        return ret = sum(s,e);
    else{
        ret = _INF;
        for(int i=s;i<e;++i)
            ret = min(ret, solve(s,i)+solve(i+1,e)+sum(s,e));
    }
    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(psum,0,sizeof(psum));
        scanf("%d",&k);
        for(int i=0;i<k;++i)
            scanf("%d",in+i);
        psum[0] = in[0];
        for(int i=1;i<k;++i)
            psum[i] = psum[i-1] + in[i];
        printf("%d\n",solve(0,k-1));
    }
    return 0;
}

