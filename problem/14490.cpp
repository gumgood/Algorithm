#include<cstdio>

int n, m;
char in[101];

int gcd(int a,int b){
    return b ? gcd(b, a%b) : a;
}

int main(){
    scanf("%s",in);
    
    int i;
    for(i=0;in[i]!=':';++i)
        n = n*10 + (in[i] - '0');    
    for(i++;in[i];++i)
        m = m*10 + (in[i] - '0');
    printf("%d:%d",n/gcd(n,m),m/gcd(n,m));
    return 0;
}

