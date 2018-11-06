#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<vector<int> > mat;

int n;
long long b;

mat matmul(const mat &a,const mat &b){
    mat ret(n,vector<int>(n,0));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k)
                ret[i][j] = (ret[i][j] + (a[i][k]*b[k][j])%1000)%1000;
    return ret;
}

mat matpow(const mat &m,long long p){
    if(p==1)
        return m;
    else if(p==2)
        return matmul(m,m);
    
    if(p%2)
        return matmul(m,matpow(m,p-1));
    
    mat t = matpow(m, p/2);
    return matmul(t, t);
}

int main(){
    mat a;
    scanf("%d%lld",&n,&b);
    a.assign(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int t;
            scanf("%d",&t);
            a[i][j] = t%1000;
        }
    }

    mat ans = matpow(a,b);
    for(int i=0;i<n;++i,puts(""))
        for(int j=0;j<n;++j)
            printf("%d ",ans[i][j]);

    return 0;
}
