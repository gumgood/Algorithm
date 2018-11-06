#include<cstdio>

long long solve(long long n){
    long long ret = 0;
    long long pow3 = 1;
    while(n){
        ret += (n%2)*pow3;

        n /= 2;
        pow3 *=3;
    }
    return ret;
}

int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld",solve(n));
    return 0;
}
