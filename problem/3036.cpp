#include<cstdio>

int n, r[101];

int gcd(int a, int b){
    return a%b ? gcd(b,a%b) : b;
}

void solve(){
    for(int i=1;i<n;++i){
        int _gcd = gcd(r[0], r[i]);
        printf("%d/%d\n",r[0]/_gcd,r[i]/_gcd);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d", r+i);
    solve();
    return 0;
}
