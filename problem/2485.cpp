#include<cstdio>

int in[100001];

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",in+i);

    int diff = 0;
    for(int i=1;i<n;++i)
        diff = gcd(diff, in[i]-in[i-1]);
    printf("%d",(in[n-1]-in[0])/diff + 1 - n);

    return 0;
}
