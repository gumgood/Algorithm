#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, a[50], b[50];

int cost(int l,int s,int e){
    if(s>e) return cost(l,e,s);

    int ret = 0;
    for(int i=s;i<e;++i)
        ret += a[i];
    return min(ret, l-ret);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
        scanf("%d",b+i);
    
    int ans = 0;
    for(int i=1;i<=n;++i)
        a[i] = 1;
    for(int i=1;i<=m;++i){
        ans += cost(n-i+1,b[i],b[i-1]);
        a[b[i]] = 0;
    }
    printf("%d",ans);
    return 0;
}
