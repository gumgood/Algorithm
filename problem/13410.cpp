#include<cstdio>
#include<algorithm>
using namespace std;

int n, k;

int rev(int n){
    int ret = 0;
    for(;n;n/=10)
        ret = ret*10 + n%10;
    return ret;
}

int solve(){
    int ret = 0;
    for(int i=1;i<=k;++i)
        ret = max(ret, rev(n*i));
    return ret;
}

int main(){
    scanf("%d%d",&n,&k);
    printf("%d",solve());
    return 0;
}
